#include "vimmish.h"
#include "keycodes.h"
#include <stdbool.h>
#include "elpfen_util.h"

/****** Currently Unused (but there's some cool stuff in there) ********/

// Vimmish-Keys: A few mocros to mimic the most useful vim keys
bool vimmish_keys(uint16_t current_keycode, keyrecord_t *record) {
    // ignore keyup
    if (!record->event.pressed) return true;

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
                tap_code16(S(KC_INSERT));
            } else {
                tap_code16(KC_END);
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
