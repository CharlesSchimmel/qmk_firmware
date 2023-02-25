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
#define ___1_through_10___   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define ___F1_through_F12___ KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11
#define _____12_blanks____   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

#define ___12_X___ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
#define _____________Dvorak_2Up_Core_10k___________ KC_1,    KC_2,    KC_3,    KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define _____________Dvorak_2Up_Sides_12k__________ KC_GRV, _____________Dvorak_2Up_Core_10k___________, KC_BSLS

#define _____________Dvorak_1Up_Core_10k___________ KC_QUOT, KC_COMM, M_DOT13, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L
#define _____________Dvorak_1Up_Sides_12k__________ KC_GRAVE, _____________Dvorak_1Up_Core_10k___________, KC_SLSH

#define _____________Dvorak_Home_Core_10k__________ KC_A,    KC_O,    KC_E,    KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S
#define _____________Dvorak_Home_Sides_12k_________ KC_ESC, _____________Dvorak_Home_Core_10k__________, KC_BSPC

#define _____________Dvorak_1Dn_Core_L_5k__________ GU_SCLN, AL_Q, SH_J, CT_K, KC_X
#define _____________Dvorak_1Dn_Core_R_5k__________                                 KC_B, CT_M, SH_W, AL_V, GU_Z
#define _____________Dvorak_1Dn_Sides_L_6k_________ KC_TAB, _____________Dvorak_1Dn_Core_L_5k__________
#define _____________Dvorak_1Dn_Sides_R_6k_________                                                     _____________Dvorak_1Dn_Core_R_5k__________, XXXXXXX
#define _____________Dvorak_1Dn_Sides_12k__________ _____________Dvorak_1Dn_Sides_L_6k_________, _____________Dvorak_1Dn_Sides_R_6k_________

#define _____________Base_Bottom_Center_6k_________ MO(_MCR), RS_ESC, LW_ENT, LW_SPC, RS_BSP, KC_SPC
#define _____________Alt_Bottom_Center_6k__________ RS_ESC, LW_ENT, _______, _______, LW_SPC, RS_BSP

// ~~~~~~~~~ Other Layers ~~~~~~~~~~
#define _____________SYM_2Up_Sides_12k_____________ ___F1_through_F12___
#define _____________SYM_1Up_Core_10k______________ ___1_through_10___
#define _____________SYM_1Up_Sides_12k_____________ _______, ___1_through_10___, KC_BSLS
#define _____________SYM_Home_Core_10k_____________ KC_LBRC, KC_LABK, KC_LPRN, KC_LCBR, KC_MINS, KC_EQL, KC_RCBR,  KC_RPRN, KC_RABK, KC_RBRC
#define _____________SYM_Home_Sides_12k____________ _______, _____________SYM_Home_Core_10k_____________, KC_DEL
#define _____________SYM_1Dn_Sides_L_6k____________ _______, O_LGUI,  O_LALT, O_LSFT, O_LCTL, KC_APP
#define _____________SYM_1Dn_Sides_R_6k____________                                                     TG_MCR, O_RCTL,  O_LSFT, O_LALT, O_RGUI, _______
#define _____________SYM_Bottom_Center_6k__________ _______, _______, AD_ENT, AD_SPC, KC_DEL, _______

#define _____________NAV_2Up_Sides_12k_____________ _______, _______, _______, _______, KC_END, _______, _______, _______, _______, _______, KC_HOME, _______
#define _____________NAV_1Up_Sides_12k_____________ L_NAV,   MS_WUP,  MS_BTN1, _______, VI_P,   VI_Y,    _______, VI_G,    _______, VI_R,    VI_L, _______
#define _____________NAV_Home_Sides_12k____________ _______, MS_WDWN, _______, _______, VI_U,   _______, VI_D,    VI_H,    _______, _______, _______, _______
#define _____________NAV_1Dn_Sides_L_6k____________ _______, KC_LGUI, KC_LALT, VI_J,    VI_K,   _______
#define _____________NAV_1Dn_Sides_R_6k____________                                                      VI_B,   KC_RCTL,  VI_W,    VI_V,    KC_RGUI, _______
#define _____________NAV_1Dn_Sides_12k_____________ _____________NAV_1Dn_Sides_L_6k____________, _____________NAV_1Dn_Sides_R_6k____________

#define _____________MCR_2Up_Sides_12k_____________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define _____________MCR_1Up_Sides_12k_____________ _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_PSCR, _______, _______, M_LOK,   _______
#define _____________MCR_Home_Sides_12k____________ _______, _______, _______, _______, M_CAD,   _______, _______, _______, _______, _______, KC_SLEP, _______
#define _____________MCR_1Dn_Sides_L_6k____________ _______, _______, M_CSE,   _______, _______, _______
#ifdef RGBLIGHT_ENABLE
#define _____________MCR_1Dn_Sides_R_6k____________                                                       _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG
#else
#define _____________MCR_1Dn_Sides_R_6k____________                                                       _______, _______, _______, _______, _______, _______
#endif
#define _____________MCR_BotCenter_6k______________ QK_BOOTLOADER,   _______, _______, _______, _______, OOOOOOO

#define _____________ADJ_1Up_Core_12k______________ KC_F12,      KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10
#define _____________ADJ_1Up_Sides_12k_____________ _______, _____________ADJ_1Up_Core_12k______________, _______
#define _____________ADJ_Home_Core_10k_____________ TILDE_SLASH, CLS_TAG, _______, DDOT_SLASH, _______, EQS, NEQS, ARROW, DARROW, _______
#define _____________ADJ_Home_Sides_12k____________ _______, _____________ADJ_Home_Core_10k_____________, _______
#define _____________ADJ_1Dn_Sides_L_6k____________ _______, _______, _______, M_SHTAB,  KC_TAB, _______
#define _____________ADJ_1Dn_Sides_R_6k____________                                                        _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______
#define _____________ADJ_Bottom_Center_6k__________ _______, _______, OOOOOOO, OOOOOOO, _______, _______

