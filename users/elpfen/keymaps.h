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
#define ___1_through_10___ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0

#define _____________Dvorak_2Up_Core_10k___________ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define _____________Dvorak_2Up_Sides_12k__________ KC_GRV, _____________Dvorak_2Up_Core_10k___________, KC_BSLS

#define _____________Dvorak_1Up_Core_10k___________ KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L
#define _____________Dvorak_1Up_Sides_12k__________ KC_GRV, _____________Dvorak_1Up_Core_10k___________, KC_SLSH

#define _____________Dvorak_Home_Core_10k__________ KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S
#define _____________Dvorak_Home_Sides_12k_________ CT_ESC, _____________Dvorak_Home_Core_10k__________, CT_MINS

#define _____________Dvorak_1Dn_Core_L_5k__________ RS_SCLN, AL_Q, KC_J, KC_K, KC_X
#define _____________Dvorak_1Dn_Core_R_5k__________                                 KC_B, KC_M, KC_W, AL_V, RS_Z
#define _____________Dvorak_1Dn_Sides_L_6k_________ SH_TAB, _____________Dvorak_1Dn_Core_L_5k__________
#define _____________Dvorak_1Dn_Sides_R_6k_________                                                     _____________Dvorak_1Dn_Core_R_5k__________, SH_BSP
#define _____________Dvorak_1Dn_Sides_12k__________ _____________Dvorak_1Dn_Sides_L_6k_________, _____________Dvorak_1Dn_Sides_R_6k_________

#define _____________Base_Bottom_Center_6k_________ FN_MNU, KC_LGUI, LW_ENT, LW_SPC, KC_RGUI, FN_MNU

#define ___F1_through_F12___ KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11
// ~~~~~~~~~ Other Layers ~~~~~~~~~~
#define _____________SYM_2Up_Sides_12k_____________ ___F1_through_F12___
#define _____________SYM_1Up_Core_10k______________ ___1_through_10___
#define _____________SYM_1Up_Sides_12k_____________ _______, ___1_through_10___, KC_SLSH
#define _____________SYM_Home_Core_10k_____________ KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK, KC_RABK, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC
#define _____________SYM_1Dn_Sides_L_6k____________ O_LSFT, _______,  O_LALT, O_LCTL, _______, _______
#define _____________SYM_1Dn_Sides_R_6k____________                                                     _______, TG_FNC,  O_RCTL, O_RALT, _______, O_RSFT
#define _____________SYM_Bottom_Center_6k__________ _______, O_LGUI, _______, _______, O_RGUI, _______

#define _____________NAV_2Up_Sides_12k_____________ _______, _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, KC_HOME, _______
#define _____________NAV_1Up_Sides_12k_____________ _______, MS_WUP,  MS_BTN1, _______, VI_P,    VI_Y,    _______, VI_G,    _______, VI_R,    KC_RGHT, _______
#define _____________NAV_Home_Sides_12k____________ _______, MS_WDWN, _______, _______, VI_U,    _______, VI_D,    KC_LEFT, _______, _______, _______, _______
#define _____________NAV_1Dn_Sides_L_6k____________ _______, L_NAV,   KC_LCTL, KC_DOWN, KC_UP,   _______
#define _____________NAV_1Dn_Sides_R_6k____________                                                       VI_B,    TG_MSE,  VI_W,    VI_V,    L_NAV,   _______
#define _____________NAV_1Dn_Sides_12k_____________ _____________NAV_1Dn_Sides_L_6k____________, _____________NAV_1Dn_Sides_R_6k____________

#define _____________FNC_2Up_Sides_12k_____________ M_CSE,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define _____________FNC_1Up_Sides_12k_____________ M_CSE, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_PSCR, _______, _______, M_LOK,   _______
#define _____________FNC_Home_Sides_12k____________ M_CSE, _______, _______, _______, M_CAD,   _______, _______, _______, _______, _______, KC_SLEP, _______
#define _____________FNC_1Dn_Sides_L_6k____________ _______, _______, _______, _______, _______, _______
#define _____________FNC_1Dn_Sides_R_6k____________                                                       _______, _______, _______, _______, _______, _______
#define _____________FNC_BotCenter_6k______________ RESET,   _______, _______, _______, _______, OOOOOOO

#define _____________ADJ_1Up_Sides_12k_____________ _______, GUI_1,   GUI_2,   GUI_3,   GUI_4,   GUI_5,   GUI_6,   GUI_7, GUI_8,   GUI_9,   GUI_L,   _______
#define _____________ADJ_Home_Sides_12k____________ _______, _______, _______, _______, _______, _______, _______, GUI_H, _______, _______, _______, _______
#define _____________ADJ_1Dn_Sides_L_6k____________ KC_LSFT, XXXXXXX, KC_LALT, M_SHTAB,  KC_TAB, _______
#define _____________ADJ_1Dn_Sides_R_6k____________                                                        _______, _______, KC_RCTL, KC_RALT, XXXXXXX, KC_RSFT
#define _____________ADJ_Bottom_Center_6k__________ _______, _______, OOOOOOO, OOOOOOO, _______, _______

