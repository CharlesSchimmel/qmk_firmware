#pragma once
#include QMK_KEYBOARD_H

#define VI_B C(KC_LEFT)
#define VI_W C(KC_RIGHT)
#define VI_Y C(KC_C)
#define VI_G TD(TD_VIM_G)
#define VI_V CTL_T(KC_RSFT)

bool vimmish_keys(uint16_t current_keycode, keyrecord_t *record);
