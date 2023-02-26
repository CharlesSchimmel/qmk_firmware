#pragma once
#include QMK_KEYBOARD_H

#define _BASE _DVORAK
#define _RAISE _SYM
#define _LOWER _NAV

#define MT_OVR(...) LT(0, __VA_ARGS__)

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

/* ~~~~~~~~~ Weird Taps ~~~~~~~~~~
 * Send KEY on tap, and some other behavior on hold by intercepting the hold 
 * event for LT(0, KEY). Overridden in process_record_user.
 *
 * The advantage of using LT(0, KEY) over regular macros is that you don't 
 * have to specify the tap behavior, just the hold behavior.
 */
// KC_DOT on tap, KC_F13 on hold. F13 mapped in AutoHotkey
#define M_DOT13 LT(0, KC_DOT)
// Grave/Tilde on tap, ~/ on hold
#define TILDE_SLASH LT(0, KC_GRAVE)


// "This key is pressed for this layer"
#define OOOOOOO KC_TRNS


// ~~~~~~~~~ Ableton ~~~~~~~~~~
#define ZERO_S       MT_OVR(KC_INT1)
#define CUT_DEL      MT_OVR(KC_INT2)
#define CPY_PST      MT_OVR(KC_INT3)
#define NDO_RDO      MT_OVR(KC_INT4)
#define SPLIT_JOIN   MT_OVR(KC_INT5)
#define QUANT        MT_OVR(KC_INT6)
#define GROUP        MT_OVR(KC_INT7)
#define TAB_SHTAB    MT_OVR(KC_INT8)
#define Z_X          MT_OVR(KC_INT9)
#define SPC_SHPC     MT_OVR(KC_LANGUAGE_1)
#define MIDI_KEY_MAP MT_OVR(KC_LANGUAGE_2)

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
