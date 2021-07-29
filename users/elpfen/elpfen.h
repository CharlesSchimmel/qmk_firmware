#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"
#endif

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3

// Mod Taps
#define AL_ENT  RALT_T(KC_ENT)
#define AL_TAB  ALT_T(KC_TAB)
#define AL_QUOT RALT_T(KC_QUOT)
#define AL_MINS RALT_T(KC_MINS)

#define CT_ESC  CTL_T(KC_ESC)
#define CT_SLSH CTL_T(KC_SLSH)

#define SH_BSP  MT(MOD_RSFT, KC_BSPC)
#define SH_DEL  MT(MOD_RSFT, KC_DEL)
#define SH_TAB  MT(MOD_LSFT, KC_TAB)
#define SH_ENT  MT(MOD_LSFT, KC_ENT)

// Layer Taps
#define LW_SPC  LT(_LOWER, KC_SPC)
#define LW_ENT  LT(_LOWER, KC_ENT)
#define RS_ENT  LT(_RAISE, KC_ENT)
#define RS_SCLN LT(_RAISE, KC_SCLN)
#define RS_Z    LT(_RAISE, KC_Z)
#define FN_MNU  LT(_FUNC, KC_MENU)

// Mouse Aliases
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_UP KC_MS_UP
#define MS_WDWN KC_MS_WH_DOWN
#define MS_WUP KC_MS_WH_UP

// Quick Macros
#define M_LOK LGUI(KC_L)
#define M_CAD LCA(KC_DEL)
#define M_CSE LCTL(LSFT(KC_ESC))
#define M_PST LSFT(KC_INS)

