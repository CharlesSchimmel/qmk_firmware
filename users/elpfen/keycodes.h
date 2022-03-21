#pragma once
#include QMK_KEYBOARD_H

#define _BASE _DVORAK
#define _RAISE _SYM
#define _LOWER _NAV

enum elpfen_layers {
    _DVORAK = 0,
    _SYM,
    _NAV,
    _MCR,
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
    TILDE_SLASH,
    DDOT_SLASH,
    ARROW,
    ELPFEN_KEYCODES_END
};

enum elpfen_combos {
    ELPFEN_COMBOS_END
};

// ~~~~~~~~~ Mod-Taps ~~~~~~~~~~
#define GU_SCLN LGUI_T(KC_SCLN)
#define GU_Z    RGUI_T(KC_Z)

#define AL_Q    LALT_T(KC_Q)
#define AL_V    LALT_T(KC_V)

#define SH_J    LSFT_T(KC_J)
#define SH_W    RSFT_T(KC_W)
#define SH_DN   LSFT_T(KC_DOWN)
#define SH_TAB LSFT_T(KC_TAB)
#define SH_BSP LSFT_T(KC_BSPC)

#define CT_K    LCTL_T(KC_K)
#define CT_M    RCTL_T(KC_M)
#define CT_UP   LCTL_T(KC_UP)

// ~~~~~~~~~ One-Shots ~~~~~~~~~~
#define O_LSFT OSM(MOD_LSFT)
#define O_RSFT OSM(MOD_RSFT)
#define O_LCTL OSM(MOD_LCTL)
#define O_RCTL OSM(MOD_RCTL)
#define O_LALT OSM(MOD_LALT)
#define O_RALT OSM(MOD_RALT)
#define O_LGUI OSM(MOD_LGUI)
#define O_RGUI OSM(MOD_RGUI)

// ~~~~~~~~~ Layers ~~~~~~~~~~
#define LW_SPC  LT(_SYM, KC_SPC)
#define LW_ENT  LT(_SYM, KC_ENT)
#define RS_ESC  LT(_NAV, KC_ESC)
#define RS_BSP  LT(_NAV, KC_BSPC)
#define FN_MNU  LT(_MCR, KC_APP)
#define AD_SPC  LT(_ADJ, KC_SPC)
#define AD_ENT  LT(_ADJ, KC_ENT)

#define MO_NAV  MO(_NAV)
#define TG_MCR  TG(_MCR)
#define TG_MSE  TG(_MOUSE)

// ~~~~~~ SimpleAliases ~~~~~~~
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

// "This key is pressed for this layer"
#define OOOOOOO KC_TRNS

