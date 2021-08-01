#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"
#include "td_layer_lock.h"

/*
 * _SYM, NAV, and _FUNC need to be defined in the individual
 * keyboard file
 */

// Mod Taps
#define AL_ENT  RALT_T(KC_ENT)
#define AL_TAB  ALT_T(KC_TAB)
#define AL_QUOT RALT_T(KC_QUOT)
#define AL_MINS RALT_T(KC_MINS)
#define AL_Q LALT_T(KC_Q)
#define AL_V RALT_T(KC_V)

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
#define M_SHTAB LSFT(KC_TAB)

// "This key is pressed for this layer"
#define OOOOOOO KC_TRNS


bool vim_windows_movement(uint16_t, keyrecord_t*);
bool dual_purpose_volume_keys(uint16_t, keyrecord_t*);
void send_alt_f4(void);

#endif
