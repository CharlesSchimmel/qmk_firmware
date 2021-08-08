#pragma once
#include QMK_KEYBOARD_H
#include "keycodes.h"

/* ~~~~~~~~~ Common Keymaps ~~~~~~~~~~
 *
 * Keymaps are named relative to the home row, so '1Up' is 1 above the home
 * row, '2Dn' is 2 below the home row, etc. Except for the bottom row, which is
 * always the bottom.
 *
 */


// ~~~~~~~~~ Base Dvorak Layer ~~~~~~~~~~
#define _____________Dvorak_2Up_Core_______________ KC_1,    KC_2,    KC_3,    KC_4,   KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define _____________Dvorak_2Up_Sides______________ KC_GRV,  _____________Dvorak_1Up_Core_______________,  KC_BSLS

#define _____________Dvorak_1Up_Core_______________ KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L
#define _____________Dvorak_1Up_Sides______________ KC_GRV,  _____________Dvorak_1Up_Core_______________,  KC_SLSH

#define _____________Dvorak_Home_Core______________ KC_A,    KC_O,    KC_E,    KC_U,   KC_I, KC_D, KC_H, KC_T, KC_N, KC_S
#define _____________Dvorak_Home_Sides_____________ CT_ESC,  _____________Dvorak_Home_Core______________,  CT_MINS

#define _____________Dvorak_1Dn_Core_L_____________ RS_SCLN, AL_Q,    KC_J,   KC_K, KC_X
#define _____________Dvorak_1Dn_Core_R_____________ KC_B, KC_M, KC_W, AL_V, RS_Z
#define _____________Dvorak_1Dn_Sides_L____________ SH_TAB,  _____________Dvorak_1Dn_Core_L_____________
#define _____________Dvorak_1Dn_Sides_R____________ _____________Dvorak_1Dn_Core_R_____________, SH_BSP
#define _____________Dvorak_1Dn_Core_______________ _____________Dvorak_1Dn_Core_L_____________, _____________Dvorak_1Dn_Core_R_____________
#define _____________Dvorak_1Dn_Sides______________ _____________Dvorak_1Dn_Sides_L____________, _____________Dvorak_1Dn_Sides_R____________

#define ___________Base_Bottom_Center_6k___________ FN_MNU, KC_LGUI, LW_ENT, LW_SPC, KC_RGUI, FN_MNU

// ~~~~~~~~~ Symbol Layer ~~~~~~~~~~
#define _____________SYM_2U_Sides_12k______________ KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F11

#define ___1_through_10___ KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0
#define _____________SYM_1U_Core_10k_______________ ___1_through_10___

#define _____________SYM_Home_Core_10k_____________ KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK, KC_RABK, KC_EQL, KC_RPRN, KC_RCBR, KC_RBRC
