#pragma once
#include QMK_KEYBOARD_H
#include "keycodes.h"

/* ~~~~~~~~~ Hold-Taps ~~~~~~~~~~
 * Send KEY on tap, and some other behavior on hold by intercepting the hold 
 * event for LT(0, KEY). Overridden in process_record_user.
 *
 * The advantage of using LT(0, KEY) over regular macros is that you don't 
 * have to specify the tap behavior, just the hold behavior.
 */
// Keycodes used for hold-tap overrides. Check quantum/keycodes.h for more.
// LT(0, KC_whatever) is unlikely to be used, but sometimes it's useful to 
enum hold_tap_keycodes {
    _HT_SAFe_range_start = KC_NUM_LOCK,
    HT_VI_WV = KC_NUM_LOCK, // there's 18 free until KC_APP
    HT_VI_L = KC_KP_SLASH,
    HT_VI_P = KC_KP_ASTERISK,
    HT_LAB_CLS = KC_KP_MINUS,
    HT_RAB_DRW = KC_KP_PLUS,
    HT_BWD_HOME,
    HT_FWD_END,
    HT_LOK_UNLOK,
    _END_KEYPAD_RANGE_ = KC_APPLICATION,
    _MORE_SAFE_RANGE_ = KC_KP_COMMA,
};

#define HT(...) LT(0, __VA_ARGS__)

#define M_DOT13     HT(KC_DOT)      // . on tap, F13 on hold
#define GRAVE_SLASH HT(KC_GRAVE)    // Grave/Tilde on tap, ~/ on hold
#define DASH_ARW    HT(KC_MINS)     // -, ->
#define EQ_DEQ      HT(KC_EQL)      // =, ==
#define SLSH_BSLSH  HT(KC_SLSH)     // /, \ on hold
#define LAB_CLS     HT(HT_LAB_CLS)  // <, </ on hold
#define RAB_DRW     HT(HT_RAB_DRW)  // >, => on hold
#define BWD_HOME    HT(HT_BWD_HOME) // C(Left), Home
#define PDN_DEND    HT(KC_PGDN)     // PgDn, C(End)
#define PUP_DHOM    HT(KC_PGUP)     // PgUp, C(Home)
#define FWD_END     HT(HT_FWD_END)  // C(Right), End
#define LOK_UNLOK   HT(HT_LOK_UNLOK) // G(L), C(S(Del))

#define HT_1        HT(KC_1)
#define HT_2        HT(KC_2)
#define HT_3        HT(KC_3)
#define HT_4        HT(KC_4)
#define HT_5        HT(KC_5)
#define HT_6        HT(KC_6)
#define HT_7        HT(KC_7)
#define HT_8        HT(KC_8)
#define HT_9        HT(KC_9)
#define HT_0        HT(KC_0)

// backword/home
// pgdn/docend
// pgup/dochome
// forward/end

// for use in per_key functions
#define TAP_HOLDS \
case M_DOT13:     \
case GRAVE_SLASH: \
case DASH_ARW:    \
case EQ_DEQ:      \
case SLSH_BSLSH:  \
case LAB_CLS:     \
case RAB_DRW:     \
case HT_1:        \
case HT_2:        \
case HT_3:        \
case HT_4:        \
case HT_5:        \
case HT_6:        \
case HT_7:        \
case HT_8:        \
case HT_9:        \
case HT_0:        \
case BWD_HOME:    \
case PDN_DEND:    \
case PUP_DHOM:    \
case FWD_END:     \
case LOK_UNLOK:   \

bool custom_tap_holds
    ( uint16_t keycode
    , keyrecord_t *record
    );

