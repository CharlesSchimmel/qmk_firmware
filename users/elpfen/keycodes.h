#pragma once
#include QMK_KEYBOARD_H

#define _BASE _DVORAK
#define _RAISE _SYM
#define _LOWER _NAV

enum elpfen_layers {
    _DVORAK = 0,
    _SYM,
    _NAV,
    _FNC,
    _MOUSE,
    _ADJ,
    ELPFEN_LAYERS_END
};

enum elpfen_custom_keycodes {
    L_NAV = SAFE_RANGE,
    VI_U,
    VI_D,
    VI_R,
    VI_P,
    ELPFEN_KEYCODES_END
};

// ~~~~~~~~~ Mod-Taps ~~~~~~~~~~
#define AL_ENT  RALT_T(KC_ENT)
#define AL_TAB  ALT_T(KC_TAB)
#define AL_QUOT RALT_T(KC_QUOT)
#define AL_MINS RALT_T(KC_MINS)
#define AL_Q    LALT_T(KC_Q)
#define AL_V    RALT_T(KC_V)
#define AL_X    LALT_T(KC_X)
#define AL_DOT  RALT_T(KC_DOT)
#define AL_J    LALT_T(KC_J)
#define AL_W    LALT_T(KC_W)

#define CT_ESC  CTL_T(KC_ESC)
#define CT_SLSH CTL_T(KC_SLSH)
#define CT_BSLS CTL_T(KC_BSLS)
#define CT_MINS CTL_T(KC_MINS)
#define CT_QUOT CTL_T(KC_QUOT)

#define SH_BSP  RSFT_T(KC_BSPC)
#define SH_DEL  RSFT_T(KC_DEL)
#define SH_TAB  LSFT_T(KC_TAB)
#define SH_ENT  LSFT_T(KC_ENT)
#define SH_A    LSFT_T(KC_A)
#define SH_S    LSFT_T(KC_S)

// ~~~~~~~~~ Layers ~~~~~~~~~~
#define LW_SPC  LT(_SYM, KC_SPC)
#define LW_ENT  LT(_SYM, KC_ENT)
#define RS_ENT  LT(_NAV, KC_ENT)
#define RS_SCLN LT(_NAV, KC_SCLN)
#define RS_Z    LT(_NAV, KC_Z)
#define RS_SLSH LT(_NAV, KC_SLSH)
#define FN_MNU  LT(_FNC, KC_APP)

#define MO_ADJ  MO(_ADJ)
#define MO_NAV  MO(_NAV)
#define TG_FNC  TG(_FNC)
#define TG_MSE  TG(_MOUSE)
#define TG_ADJ  TG(_ADJ)

// ~~~~~~~~~ Simple Aliases ~~~~~~~~~~
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_UP   KC_MS_UP
#define MS_WDWN KC_MS_WH_DOWN
#define MS_WUP  KC_MS_WH_UP

// ~~~~~~~~~ Quick Mocros ~~~~~~~~~~
#define M_LOK   LGUI(KC_L)
#define M_CAD   LCA(KC_DEL)
#define M_CSE   LCTL(LSFT(KC_ESC))
#define M_PST   LSFT(KC_INS)
#define M_SHTAB LSFT(KC_TAB)

#define GUI_1   LGUI(KC_1)
#define GUI_2   LGUI(KC_2)
#define GUI_3   LGUI(KC_3)
#define GUI_4   LGUI(KC_4)
#define GUI_5   LGUI(KC_5)
#define GUI_6   LGUI(KC_6)
#define GUI_7   LGUI(KC_7)
#define GUI_8   LGUI(KC_8)
#define GUI_9   LGUI(KC_9)

// "This key is pressed for this layer"
#define OOOOOOO KC_TRNS

