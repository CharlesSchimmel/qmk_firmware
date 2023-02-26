#pragma once
#include QMK_KEYBOARD_H

#define _BASE _DVORAK
#define _RAISE _SYM
#define _LOWER _NAV

enum elpfen_layers {
    _DVORAK = 0,
    _SYM,
    _NAV,
    _ADJ,
    _MCR,
    _ABL,
    _MOUSE,
    ELPFEN_LAYERS_END
};

enum elpfen_custom_keycodes {
    L_NAV = SAFE_RANGE,
    VI_U,        // C-Z or PgUp
    VI_D,        // C-X or PgDn
    VI_R,        // C-Y
    DDOT_SLASH,  // ../
    ARROW,       // ->
    DARROW,      // =>
    NEQS,        // != or !==
    EQS,         // == or ===
    CLS_TAG,     // </
    ELPFEN_KEYCODES_END
};

#define OOOOOOO KC_TRNS // "This key is pressed for this layer"

// ~~~~~~~~~ Mod-Taps ~~~~~~~~~~
#define GU_SCLN LGUI_T(KC_SCLN)
#define GU_Z    RGUI_T(KC_Z)

#define AL_Q    LALT_T(KC_Q)
#define AL_V    LALT_T(KC_V)

#define SH_J    LSFT_T(KC_J)
#define SH_W    RSFT_T(KC_W)
#define SH_DN   LSFT_T(KC_DOWN)
#define SH_TAB  LSFT_T(KC_TAB)
#define SH_BSP  LSFT_T(KC_BSPC)

#define CT_K    LCTL_T(KC_K)
#define CT_M    RCTL_T(KC_M)
#define CT_UP   LCTL_T(KC_UP)

#define ALPHA_MODS   \
        case GU_SCLN:\
        case GU_Z:   \
        case AL_Q:   \
        case AL_V:   \
        case SH_J:   \
        case SH_W:   \
        case SH_DN:  \
        case CT_K:   \
        case CT_M:   \
        case CT_UP:  \

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

// ~~~~~~ SimpleAliases ~~~~~~~
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3
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

/* ~~~~~~~~~ Hold-Taps ~~~~~~~~~~
 * Send KEY on tap, and some other behavior on hold by intercepting the hold 
 * event for LT(0, KEY). Overridden in process_record_user.
 *
 * The advantage of using LT(0, KEY) over regular macros is that you don't 
 * have to specify the tap behavior, just the hold behavior.
 */
// Keycodes used for hold-tap overrides. Check quantum/keycodes.h for more.
enum hold_tap_keycodes {
    HT_VI_WV = KC_NUM_LOCK,
    HT_VI_L = KC_KP_SLASH,
    HT_VI_P = KC_KP_ASTERISK,
    HT_LAB_CLS = KC_KP_MINUS,
    HT_RAB_DRW = KC_KP_PLUS,
    // there's like 11 more safe ones before KC_APP
    _END_KEYPAD_RANGE_ = KC_APPLICATION,
    _MORE_SAFE_RANGE_ = KC_KP_COMMA,
};

#define HT(...) LT(0, __VA_ARGS__)

#define M_DOT13     HT(KC_DOT)     // . on tap, F13 on hold
#define TILDE_SLASH HT(KC_GRAVE)   // Grave/Tilde on tap, ~/ on hold
#define DASH_ARW    HT(KC_MINS)    // -, ->
#define EQ_DEQ      HT(KC_EQL)     // =, ==
#define SLSH_BSLSH  HT(KC_SLSH)    // /, \ on hold
#define LAB_CLS     HT(HT_LAB_CLS) // <, </ on hold
#define RAB_DRW     HT(HT_RAB_DRW) // >, => on hold
#define HT_1        HT(KC_1)
#define HT_2        HT(KC_2)
#define HT_3        HT(KC_3)
#define HT_4        HT(KC_4)
#define HT_5        HT(KC_5)
#define HT_6        HT(KC_6)
#define HT_7        HT(KC_7)
#define HT_8        HT(KC_8)
#define HT_9        HT(KC_9)
#define HT_0       HT(KC_0)


// ~~~~~~~~~ Ableton ~~~~~~~~~~
#define ZERO_S       HT(KC_INT1)
#define CUT_DEL      HT(KC_INT2)
#define CPY_PST      HT(KC_INT3)
#define NDO_RDO      HT(KC_INT4)
#define SPLIT_JOIN   HT(KC_INT5)
#define QUANT        HT(KC_INT6)
#define GROUP        HT(KC_INT7)
#define TAB_SHTAB    HT(KC_INT8)
#define Z_X          HT(KC_INT9)
#define SPC_SHPC     HT(KC_LANGUAGE_1)
#define MIDI_KEY_MAP HT(KC_LANGUAGE_2)

#define NOTE_C  KC_A
#define NOTE_CS KC_W
#define NOTE_D  KC_S
#define NOTE_DS KC_E
#define NOTE_E  KC_D
#define NOTE_F  KC_F
#define NOTE_FS KC_T
#define NOTE_G  KC_G
#define NOTE_GS KC_Y
#define NOTE_A  KC_H
#define NOTE_AS KC_U
#define NOTE_B  KC_H
