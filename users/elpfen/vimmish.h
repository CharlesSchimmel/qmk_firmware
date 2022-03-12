#pragma once
#include QMK_KEYBOARD_H

#define VI_B C(KC_LEFT)
#define VI_W C(KC_RIGHT)
#define VI_Y C(KC_C)

#ifdef TAP_DANCE_ENABLE
#define VI_G TD(TD_VIM_G)
#else
#define VI_G C(KC_HOME)
#endif

bool vimmish_keys(uint16_t current_keycode, keyrecord_t *record);

// act (sort of) like G in vim: single tap (instead of shift) for END, double
// tap for HOME. This assumes that systems will interpret C+HOME as "start of
// file" instead of "start/end of line"
#define TD_VI_G_ENTRY [TD_VIM_G] = ACTION_TAP_DANCE_DOUBLE(C(KC_END), C(KC_HOME))
