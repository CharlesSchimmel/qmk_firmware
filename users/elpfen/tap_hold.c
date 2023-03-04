#include "tap_hold.h"
#include "keycodes.h"
#include <stdbool.h>
#include "elpfen_util.h"

// Custom Tap-Holds https://docs.qmk.fm/#/mod_tap?id=intercepting-mod-taps
bool custom_tap_holds
    ( uint16_t keycode
    , keyrecord_t *record
    ) {
        if (!record->event.pressed) return true; // ignore tap-up and hold-up
        // These keycodes everride their tap behavior
        switch (keycode) {
            case LAB_CLS:
                if (!record->tap.count) {
                    SEND_STRING("</");
                    return false;
                } else {
                    tap_code16(KC_LABK);
                    return false;
                }
            case RAB_DRW:
                if (!record->tap.count) {
                    SEND_STRING("=>");
                    return false;
                } else {
                    tap_code16(KC_RABK);
                    return false;
                }
            case BWD_HOME:
                if (!record->tap.count) {
                    tap_code16(C(KC_HOME));
                    return false;
                } else {
                    tap_code16(KC_HOME);
                    return false;
                }
            case FWD_END:
                if (!record->tap.count) {
                    tap_code16(C(KC_END));
                    return false;
                } else {
                    tap_code16(KC_END);
                    return false;
                }
            case LOK_UNLOK:
                if (!record->tap.count) {
                    tap_code16(G(KC_L));
                    return false;
                } else {
                    tap_code16(C(A(KC_DEL)));
                    return false;
                }
        }
        if (record->tap.count) return true; // ignore any unhandled hold behaviors

        // These keycodes keep their Tap behavior
        switch (keycode) {
            case GRAVE_SLASH: SEND_STRING("~/");      return false;
            case EQ_DEQ:      SEND_STRING("==");      return false;
            case DASH_ARW:    SEND_STRING("->");      return false;
            case SLSH_BSLSH:  tap_code(KC_BSLS);      return false;
            case PDN_DEND:    tap_code16(C(KC_END));  return false;
            case PUP_DHOM:    tap_code16(C(KC_HOME)); return false;
            case HT_1:        tap_code(KC_F12);       return false;
            case HT_2:        tap_code(KC_F2);        return false;
            case HT_3:        tap_code(KC_F3);        return false;
            case HT_4:        tap_code(KC_F4);        return false;
            case HT_5:        tap_code(KC_F5);        return false;
            case HT_6:        tap_code(KC_F6);        return false;
            case HT_7:        tap_code(KC_F7);        return false;
            case HT_8:        tap_code(KC_F8);        return false;
            case HT_9:        tap_code(KC_F9);        return false;
            case HT_0:        tap_code(KC_F10);       return false;
        }
        return   true;
}

