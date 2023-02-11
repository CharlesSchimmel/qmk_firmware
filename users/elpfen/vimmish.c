#include "vimmish.h"
#include "keycodes.h"
#include <stdbool.h>
#include "elpfen_util.h"


// Vimmish-Keys: A few mocros to mimic the most useful vim keys
bool vimmish_keys(uint16_t current_keycode, keyrecord_t *record) {
    // ignore keyup
    if (!record->event.pressed) return true;

    bool with_ctl = WITH_CTRL;
    bool with_shift = WITH_SHIFT;

    switch(current_keycode) {
#ifndef TAP_DANCE_ENABLE
        case VI_G:
            if (record->tap.count) {
                tap_code16(C(KC_HOME));
            } else {
                tap_code16(C(KC_END));
            }
            return false;
#endif
        case VI_L:
            if (record->tap.count) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_HOME);
            }
            return false;
        case VI_W:
            if (record->tap.count) { // tap
                tap_code16(C(KC_RIGHT));
                return false;
            } else {
                return true;
            }
        case VI_P:
            if (record->tap.count) {
                if (with_shift) {
                    tap_code16(S(KC_INSERT));
                } else {
                    tap_code16(C(KC_V));
                }
            } else {
                tap_code16(KC_END);
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
                tap_code(KC_PGDN);
            } else {
                tap_code16(C(KC_X));
            }
            return false;

        case VI_V:
            if (record->tap.count) { // tap
                static bool visual_mode = false;
                visual_mode ? unregister_code(KC_RSFT) : register_code(KC_RSFT);
                visual_mode = !visual_mode;
            } else {
                return true;
            }

        default:
            return true;
    }
    return true;
}
