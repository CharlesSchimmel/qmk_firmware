#pragma once
#include QMK_KEYBOARD_H

#define VI_B C(KC_LEFT)
#define VI_W S(KC_WFAV)
#define VI_L LT(0, KC_WWW_REFRESH) // right or home
#define VI_P LT(0, KC_MAIL) // paste or end
#define VI_Y C(KC_C)

#ifdef TAP_DANCE_ENABLE
#define VI_G TD(TD_VIM_G)
// act (sort of) like G in vim: single tap (instead of shift) for END, double
// tap for HOME. This assumes that systems will interpret C+HOME as "start of
// file" instead of "start/end of line"
#define TD_VI_G_ENTRY [TD_VIM_G] = ACTION_TAP_DANCE_DOUBLE(C(KC_END), C(KC_HOME))
#else
#define VI_G LT(0, KC_WWW_FAVORITES) // document home or end
#endif

bool vimmish_keys(uint16_t current_keycode, keyrecord_t *record);
