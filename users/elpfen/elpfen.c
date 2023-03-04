#include "action.h"
#include "elpfen.h"
#include "keycodes.h"
#include "tap_hold.h"
#include "layer_sticky_mods.h"
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

    // intercept the "tap" of a mod-tap
    if (record->event.pressed && record->tap.count) {
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
            if (WITH_SHIFT)
                tap_code16(A(KC_F4));
            // return true and keep processing the keycode: we still want
            // win-shift-c to get sent when using this keyboard with xmonad/i3
            // (xmonad/i3 will ignore A-F4)
            return true;
    }

    return true;
}

/* layer-lock: If a layer-tap is being held to activate a layer, tapping a
 * specific key will "Lock In" that layer, preventing it from being deactivated
 * when the mod-tap is released. In this case, my layer is _NAV, my mod-taps
 * are aliased to RS_Z and RS_SCLN and my lock macro is L_NAV
 *
 * This works by overriding the MT(_LAYER, KC_KEY) code and preventing it's
 * Keyup event from being processed.
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

// Boring plain macros
bool process_macros
    ( uint16_t keycode
    , keyrecord_t *record
    ) {
    if (!record->event.pressed) return true; // ignore keyup
    switch (keycode) {
        case DDOT_SLASH:
            SEND_STRING("../");
            return false;

        case ARROW:
            SEND_STRING("->");
            return false;

        case DARROW:
            SEND_STRING("=>");
            return false;

        case NEQS:
            SEND_STRING("!=");
            return false;

        case EQS:
            SEND_STRING("==");
            return false;

        case CLS_TAG:
            SEND_STRING("</");
            return false;

        case TILDE_SLASH:
            SEND_STRING("~/");
            return false;
    }
    return true;
}

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

__attribute__((weak)) bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // !!! Note that the default is true for this one
    switch (keycode) {
        TAP_HOLDS
            return false;
        default:
            return true;
    }
}

#ifdef TAPPING_TERM_PER_KEY
/* TAPPING_TERM_PER_KEY: Pretty self-explanatory */
__attribute__((weak)) uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        TAP_HOLDS
            return 75;
        default:
            return TAPPING_TERM;
    }
}
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RS_BSP:
        case RS_ESC:
        case LW_ENT:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            return false;
    }
}
#endif


// order must follow:
// 1. Lenient Tri-Layer
// 2. Switchboard
// 3. Layer-Sticky Mods
layer_state_t elpfen_default_layer_state_set(layer_state_t current_state) {
    static layer_state_t previous_state;
    /* current_state = lenient_update_tri_layer_state(current_state, _SYM, _NAV, _ADJ); */

    /* current_state = switchboard_state(previous_state, current_state, _SYM, _MCR); */
    current_state = switchboard_state(previous_state, current_state, _SYM, _ADJ);

    layer_sticky_mods_state_hook(previous_state, current_state, _ADJ);
    layer_sticky_mods_state_hook(previous_state, current_state, _NAV);

    previous_state = current_state;

    return current_state;
}

__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t current_state) {
    return elpfen_default_layer_state_set(current_state);
}

// ~~~~ Keypress Processing ~~~~~
__attribute__((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return ELPFEN_DEFAULT_PROREC ;
}
