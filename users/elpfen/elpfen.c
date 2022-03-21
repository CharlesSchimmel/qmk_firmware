#include "quantum.h"
#include "action.h"
#include "elpfen.h"
#include "keycodes.h"
#include "layer_helpers.h"

/* Multi-Purpose Volume Keys: Alter the behavior of volume keys depending on
 * if Shift or Control is pressed.
 *
 * Some OS's/Desktops will use Ctl, Alt, and Shift to change how much the
 * volume is increased, so it might not be for everyone.
 */
bool multi_purpose_volume_keys(uint16_t keycode, keyrecord_t *record) {
    // ignore keyup
    if (!record->event.pressed) return true;

    bool with_shift = WITH_SHIFT;
    bool with_ctl = WITH_CTRL;
    bool vanilla = !(with_shift || with_ctl);

    if (vanilla) { return true; }

    switch(keycode) {
        case KC_VOLD :
            with_shift ? tap_code(KC_MEDIA_PREV_TRACK) : tap_code(KC_BRIGHTNESS_DOWN);
            return false;
        case KC_VOLU :
            with_shift ? tap_code(KC_MEDIA_NEXT_TRACK) : tap_code(KC_BRIGHTNESS_UP);
            return false;
        case KC_MUTE :
            tap_code(KC_MEDIA_PLAY_PAUSE);
            return false;
    }

    return true;
}

/* Pseudo TWM: Imitate Xmonad or i3 in Windows by enabling movement of windows with
 * Win+HJKL and closing windows with W-S-C
 */
bool pseudo_twm(uint16_t keycode, keyrecord_t *record) {
    if (!WITH_GUI) return true;

    // handle mod-tap keys by only intercepting keyup (tap)
    if (!record->event.pressed && record->event.time <= get_tapping_term(keycode, record)) {
        switch (keycode) {
          case SH_J :
            tap_code(KC_DOWN);
            return false;

          case CT_K :
            tap_code(KC_UP);
            return false;
        }
        return true;
    }

    // move and close windows in Windows using vim keys (WIN+HJKL)
    if (!record->event.pressed) return true;
    switch(keycode) {
        case KC_H :
            tap_code(KC_LEFT);
            return false;

        case KC_J :
            tap_code(KC_DOWN);
            return false;

        case KC_K :
            tap_code(KC_UP);
            return false;

        case KC_L :
            tap_code(KC_RIGHT);
            return false;

        case KC_C :
            if (WITH_SHIFT) {
                tap_code16(A(KC_F4));
                // still want win-shift-c to get sent when using this keyboard with
                // xmonad/i3
                return true;
            }
    }

    return true;
}

/* Switchboard: For momentary/layer-tapped layers, make a "child" layer
 * dependent on its parent layer.
 *
 * Example: If _LOW is the active laer, then TG(_RAISE) is pressed, _RAISE
 * will stay active so long as _LOW is active. When _LOW is deactivated, so
 * will _RAISE.
 *
 * This is really useful as it lets one layer "switchboard" to many other
 * layers, but occupy only one activating switch. It's like a
 * Raise+Lower=Adjust but you only have to keep one key held.
 *
 * Note: this requires that the child layers are higher than the parent
 * layers.
 */
layer_state_t switchboard(layer_state_t current_state) {
    static layer_state_t previous_state;
    current_state = switchboard_state(previous_state, current_state);
    previous_state = current_state;
    return current_state;
}

layer_state_t switchboard_state(layer_state_t previous_state, layer_state_t current_state) {
    if (was_layer_turned_off(previous_state, current_state, _NAV)) {
        current_state = layer_off_state(current_state, _MOUSE);
    }

    if (was_layer_turned_off(previous_state, current_state, _SYM)) {
        current_state = layer_off_state(current_state, _MCR);
        current_state = layer_off_state(current_state, _ADJ);
    }
    return current_state;
}

/* layer-lock: If a layer-tap is being held to activate a layer, tapping a
 * specific key will "Lock In" that layer, preventing it from being deactivated
 * when the mod-tap is released. In this case, my layer is _NAV, my mod-taps
 * are aliased to RS_Z and RS_SCLN and my lock macro is L_NAV
 *
 * This works by overriding the MT(_LAYER, KC_KEY) code and preventing it's
 * Keyup event from being processed..
 */
bool layer_lock(uint16_t current_keycode, keyrecord_t *record) {
    static bool nav_lock = false;
    switch (current_keycode) {
        // the MT(_layer, KC_KEY) mod-taps that activate the layer
        case RS_ESC:
        case RS_BSP:
            if (nav_lock) {
                return false;
            } else {
                return true;
            }

        // the custom keycode that will lock and unlock in the layer
        case L_NAV:
            if (record->event.pressed) {
                if (nav_lock) {
                    layer_off(_NAV);
                    nav_lock = false;
                } else {
                   nav_lock = true;
                }
            }
            return false;
        default:
            return true;
    }
}

/* Lenient Adjust: Turn on the third layer if both RAISE and LOWER are on (like
 * update_tri_layer_state), but only turn off the third layer when _both_
 * parent layers are turned off.
 */
layer_state_t lenient_update_tri_layer_state(
        layer_state_t state,
        uint8_t layer1,
        uint8_t layer2,
        uint8_t layer3
        ) {
    layer_state_t mask12 = (1UL << layer1) | (1UL << layer2);
    layer_state_t mask3  = 1UL << layer3;

    bool both_on = (state & mask12) == mask12;
    bool both_off = (state & mask12) == 0;

    if (both_on)  return state | mask3;
    if (both_off) return state & ~mask3;

    return state;
}

/* Layer-Sticky Mods: If a mod is pressed in this layer, keep it on until the
 * layer is deactivated. Simply intercept and ignore keyup for those modifiers
 * and call clear_mods when the layer turns off.
 *
 * I think this could be done more generally by checking the mod bits, but idk.
 */
bool layer_sticky_mods(
        uint16_t current_keycode,
        keyrecord_t *record,
        layer_state_t layers) {
    if (IS_LAYER_OFF(layers)) return true;
    if (record->event.pressed) return true;

    switch (current_keycode) {
        case KC_LALT:
        case KC_RALT:
        case KC_LCTL:
        case KC_RCTL:
        case KC_LSFT:
        case KC_RSFT:
            return false;
        default:
            return true;
    }
}

// the other half of layer_sticky_mods if not using an tri-layer
bool clear_mods_after_adj(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) return true;
    if (keycode == AD_ENT || keycode == AD_SPC) {
        clear_mods();
    }
    return true;
}

bool process_macros
    ( uint16_t keycode
    , keyrecord_t *record
    ) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case TILDE_SLASH:
            SEND_STRING("~/");
            return false;
        case DDOT_SLASH:
            SEND_STRING("../");
            return false;
    }
    return true;
}

#define ALPHA_MODS   \
        case GU_SCLN:\
        case GU_Z:   \
        case AL_Q:   \
        case AL_V:   \
        case SH_J:   \
        case SH_W:   \
        case SH_DN:  \
        case CT_K:   \
        case CT_M:   \
        case CT_UP:  \

/* TAPPING_FORCE_HOLD_PER_KEY: For these specific mod-taps, do not interpret
 * a 'tap, tap-hold' event as repeating the tapped keypress. This is useful
 * for mod-taps whose tapped key is used in normal typing.
 */
__attribute__((weak)) bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        ALPHA_MODS
            return true;
        default:
            return false;
    }
}

/* IGNORE_MOD_TAP_INTERRUPT_PER_KEY: For these specific mod-taps, if the
 * second key in a chord is released after the modifier key is released,
 * ignore the modifier, even if it's inside the tapping term.
 */
__attribute__((weak)) bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        ALPHA_MODS
            return true;
        default:
            return false;
    }
}
