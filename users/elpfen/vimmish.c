#include "vimmish.h"
#include "tap_dances.h"
#include "keycodes.h"
#include <stdbool.h>

// Vimmish-Keys: A few mocros to mimic the most useful vim keys
bool vimmish_keys(uint16_t current_keycode, keyrecord_t *record) {
    // ignore keyup
    if (!record->event.pressed) return true;

    bool with_ctl = get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL);
    bool with_shift = get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT);

    switch(current_keycode) {
        case VI_P:
            if (with_shift) {
                tap_code16(S(KC_INSERT));
            } else {
                tap_code16(C(KC_V));
            }
            return false;

        case VI_R:
            if (with_ctl) {
                tap_code16(C(KC_Y));
            }
            return false;

        case VI_U:
            if (with_ctl) {
                tap_code(KC_PGUP);
            } else {
                tap_code16(C(KC_Z));
            }
            return false;

        case VI_D: 
            if (with_ctl) {
                tap_code(KC_PGUP);
            } else {
                tap_code16(C(KC_X));
            }
            return false;

        default:
            return true;
    }
    return true;
}

