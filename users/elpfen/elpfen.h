#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"
#include "td_helpers.h"
#include "layer_helpers.h"

/*
 * _SYM, NAV, and _FUNC need to be defined in the individual
 * keyboard file
 */

enum elpfen_custom_keycodes {
    ELPFEN_START_RANGE = SAFE_RANGE,
    ELPFEN_SAFE_RANGE
};

// Mod Taps
#define AL_ENT  RALT_T(KC_ENT)
#define AL_TAB  ALT_T(KC_TAB)
#define AL_QUOT RALT_T(KC_QUOT)
#define AL_MINS RALT_T(KC_MINS)
#define AL_Q    LALT_T(KC_Q)
#define AL_V    RALT_T(KC_V)

#define CT_ESC  CTL_T(KC_ESC)
#define CT_SLSH CTL_T(KC_SLSH)
#define CT_BSLS CTL_T(KC_BSLS)
#define CT_MINS CTL_T(KC_MINS)

#define SH_BSP  MT(MOD_RSFT, KC_BSPC)
#define SH_DEL  MT(MOD_RSFT, KC_DEL)
#define SH_TAB  MT(MOD_LSFT, KC_TAB)
#define SH_ENT  MT(MOD_LSFT, KC_ENT)

// Layer Taps
#define LW_SPC  LT(_SYM, KC_SPC)
#define LW_ENT  LT(_SYM, KC_ENT)
#define RS_ENT  LT(_NAV, KC_ENT)
#define RS_SCLN LT(_NAV, KC_SCLN)
#define RS_Z    LT(_NAV, KC_Z)
#define RS_SLSH LT(_NAV, KC_SLSH)
#define FN_MNU  LT(_FNC, KC_APP)

// Mouse Aliases
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_UP   KC_MS_UP
#define MS_WDWN KC_MS_WH_DOWN
#define MS_WUP  KC_MS_WH_UP

// Quick Macros
#define M_LOK   LGUI(KC_L)
#define M_CAD   LCA(KC_DEL)
#define M_CSE   LCTL(LSFT(KC_ESC))
#define M_PST   LSFT(KC_INS)
#define M_SHTAB LSFT(KC_TAB)

#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)
#define GUI_4 LGUI(KC_4)
#define GUI_5 LGUI(KC_5)
#define GUI_6 LGUI(KC_6)
#define GUI_7 LGUI(KC_7)
#define GUI_8 LGUI(KC_8)
#define GUI_9 LGUI(KC_9)

// "This key is pressed for this layer"
#define OOOOOOO KC_TRNS


bool vim_windows_movement(uint16_t, keyrecord_t*);
bool dual_purpose_volume_keys(uint16_t, keyrecord_t*);
void send_alt_f4(void);

#endif

// clang-format off

/* ~~~~~~~~~ Common Keymaps ~~~~~~~~~~
 *
 * Keymaps are defined here to be reused in multiple keyboards
 *
 * Keymaps are named relative to the home row, so '1Up' is 1 above the home
 * row, '2Dn' is 2 below the home row, etc. Except for the bottom row, which is
 * always the bottom.
 *
 * Some macros include their key count as a suffix. Ex:
 * _____________SYM_2U_Sides_12k______________ corresponds to 12 keys.
 *
 * Rows are organized as "Core" meaning just the 12 (usually alphanumeric)
 * keys, and  "Sides", meaning that they include the side keys. Some rows are
 * also split into Left and Right sections for keyboards that include middle
 * keys.
 *
 */

// BoTtoM row, Left side, 0 from the middle
#define BTML0 LW_ENT
#define BTML1 KC_LGUI
#define BTML2 FN_MNU
#define BTMR0 LW_SPC
#define BTMR1 KC_RGUI
#define BTMR2 FN_MNU

#define ___________Base_Bottom_Center_6k___________ BTML2, BTML1, BTML0, BTMR0, BTMR1, BTMR2

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

// ~~~~~~~~~ Symbol Layer ~~~~~~~~~~
#define _____________SYM_2U_Sides_12k______________ KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F11

#define _____________SYM_1U_Sides_10k______________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0

#define ____________SYM_Home_Sides_10k_____________ KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK, KC_RABK, KC_EQL, KC_RPRN, KC_RCBR, KC_RBRC
// clang-format on

