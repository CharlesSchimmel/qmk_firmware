#include "quantum.h"
#include "action.h"
#include "elpfen.h"
#include "keycodes.h"
#include "layer_helpers.h"

/* Multi-Purpose Volume Keys: Alter the behavior of valume keys depending on
 * if Shift or Control is pressed.
 *
 * Some OS's/Desktops will use Ctl, Alt, and Shift to change how much the
 * volume is increased, so it might not be for everyone.
 */
bool multi_purpose_volume_keys(uint16_t keycode, keyrecord_t *record) {
    // ignore keyup
    if (!record->event.pressed) return true;

    bool with_shift = get_mods() & MOD_BIT(KC_LSFT)
                   || get_mods() & MOD_BIT(KC_RSFT);
    bool with_ctl = get_mods() & MOD_BIT(KC_LCTL)
                 || get_mods() & MOD_BIT(KC_RCTL);
    bool vanilla = !with_shift && !with_ctl;

    if (vanilla) { return true; }

    switch(keycode) {
        case KC_VOLD :
            with_shift ? tap_code(KC_MEDIA_PREV_TRACK) : tap_code(KC_BRIGHTNESS_DOWN);
            return false;
        case KC_VOLU :
            with_shift ? tap_code(KC_MEDIA_NEXT_TRACK) : tap_code(KC_BRIGHTNESS_UP);
            return false;
        case KC_MUTE :
            SEND_STRING(SS_TAP(X_MEDIA_PLAY_PAUSE));
            return false;
    }

    return true;
}

/* Pseudo TWM: Imitate Xmonad or i3 in Windows by enabling movement of windows with
 * Win+HJKL and closing windows with W-S-C
 */
bool pseudo_twm(uint16_t keycode, keyrecord_t *record) {
    // ignore keyup
    if (!record->event.pressed) return true;
    if (!(get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))) return true;

    // move and close windows in Windows using vim keys (WIN+HJKL)
    switch(keycode) {
        case KC_H :
        SEND_STRING(SS_TAP(X_LEFT));
        return false;

        case KC_J :
        SEND_STRING(SS_TAP(X_DOWN));
        return false;

        case KC_K :
        SEND_STRING(SS_TAP(X_UP));
        return false;

        case KC_L :
        SEND_STRING(SS_TAP(X_RIGHT));
        return false;

        case KC_C :
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
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
        current_state = layer_off_state(current_state, _FNC);
    }
    return current_state;
}

/* layer-lock: If a layer-tap is being held to activate a layer, tapping a
 * specific macro associated with that layer will "Lock In" that layer,
 * preventing it from being deactivated when the mod-tap is released. In
 * this case, my layer is _NAV, my mod-taps are aliased to RS_Z and RS_SCLN
 * and my lock macro is L_NAV
 *
 * This works by overriding the MT(_LAYER, KC_KEY) code and preventing it's
 * Keyup event from being processed..
 */
bool layer_lock(uint16_t current_keycode, keyrecord_t *record) {
    static bool nav_lock = false;
    switch (current_keycode) {
        // the MT(_layer, KC_KEY) mod-taps that activate the layer
        case RS_Z:
        case RS_SCLN:
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

/* TAPPING_FORCE_HOLD_PER_KEY: For these specific mod-taps, do not interpret
 * a 'tap, tap-hold' event as repeating the tapped keypress. This is useful
 * for mod-taps whose tapped key is used in normal typing.
 */
__attribute__((weak)) bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AL_Q:
        case AL_V:
        case AL_X:
        case AL_DOT:
            return true;
        default:
            return false;
    }
}

/* IGNORE_MOD_TAP_INTERRUPT_PER_KEY: For these specific mod-taps, if the
 * second key in a chord is pressed after the modifier key is released,
 * ignore the modifier, even if it's inside the tapping term.
 */
__attribute__((weak)) bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AL_Q:
        case AL_V:
        case AL_X:
        case AL_DOT:
            return true;
        default:
            return false;
    }
}

