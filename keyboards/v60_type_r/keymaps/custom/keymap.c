/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* This is the default ANSI layout provided by the KBP V60 Type R
* as depicted in their manual and on the stock keycaps.
*/
#include QMK_KEYBOARD_H

// LAYER DEFs
#define _DEF 0
#define _NAV 1
#define _FNC 2
#define _SYM 3

// Mod Taps
#define AL_ENT  RALT_T(KC_ENT)
#define AL_TAB  ALT_T(KC_TAB)
#define AL_3    ALT_T(KC_3)
#define AL_8    RALT_T(KC_8)

#define CT_BSLS RCTL_T(KC_BSLS)
#define CT_ENT  CTL_T(KC_ENT)
#define CT_ESC  CTL_T(KC_ESC)
#define CT_2    CTL_T(KC_2)
#define CT_9    RCTL_T(KC_9)

#define SH_BSP  MT(MOD_RSFT, KC_BSPC)
#define SH_DEL  MT(MOD_RSFT, KC_DEL)
#define SH_TAB  MT(MOD_LSFT, KC_TAB)
#define SH_ENT  MT(MOD_LSFT, KC_ENT)

// Layer Taps
#define MNU_FNC LT(_FNC, KC_APP)
#define SP_SYM  LT(_SYM, KC_SPC)
#define SC_NAV  LT(_NAV, KC_SCLN)
#define Z_NAV   LT(_NAV, KC_Z)
#define SL_NAV  LT(_NAV, KC_SLSH)

// Modded Keys
#define SH_INS LSFT(KC_INS)

// Mouse Aliases
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_UP   KC_MS_UP
#define MS_WDN  KC_MS_WH_DOWN
#define MS_WUP  KC_MS_WH_UP

// Quick Macros
#define M_LOK LGUI(KC_L)
#define M_CAD LCA(KC_DEL)
#define M_CSE LCTL(LSFT(KC_ESC))
#define M_SHN LSFT(KC_INS)

// Tap Dance
enum {
  TD_ALTAB = 0
};

#define _____ KC_TRNS
#define XXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default Layer (Qwerty)
   * ,-----------------------------------------------------------.
   * | ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |   Bs  |
   * |-----------------------------------------------------------|
   * | ATb | Q | W | E | R | T | Y | U | I | O | P | [ | ] | Ct\ |
   * |-----------------------------------------------------------|
   * | EsCtl | A | S | D | F | G | H | J | K | L | ; | ' | AlEnt |
   * |---------------------.-----------.-------------------------|
   * | Shift  | Z | X | C | V | B | N | M | , | . | / |  SftBsp  |
   * |-----------------------------------------------------------|
   * |Ctrl|MFnc|Gui |         SpSym           |RGui| Fn |Alt|Ctrl|
   * `-----------------------------------------------------------'
   */
  [0] = LAYOUT_60_ansi(

KC_GESC, KC_1,    CT_2,    AL_3,   KC_4,    KC_5,    KC_6,    KC_7, AL_8,    CT_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
AL_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P,    KC_Y,    KC_F,    KC_G, KC_C,    KC_R,   KC_L,    KC_LBRC, KC_RBRC, CT_BSLS, \
CT_ESC,  KC_A,    KC_O,    KC_E,   KC_U,    KC_I,    KC_D,    KC_H, KC_T,    KC_N,   KC_S,    KC_MINS, AL_ENT,           \
SH_ENT,  SL_NAV,  KC_Q,    KC_J,   KC_K,    KC_X,    KC_B,    KC_M, KC_W,    KC_V,   Z_NAV,   SH_BSP,                    \
KC_LCTL, MNU_FNC, KC_LGUI, SP_SYM, KC_RGUI, MNU_FNC, KC_RALT, KC_RCTL

/*
KC_GESC, KC_1,    CT_2,    AL_3,   KC_4,    KC_5,    KC_6,    KC_7, AL_8,    CT_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
AL_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, CT_BSLS, \
CT_ESC,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, AL_ENT,           \
SH_ENT,  Z_NAV,   KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT, SL_NAV,  SH_BSP,                    \
KC_LCTL, MNU_FNC, KC_LGUI, SP_SYM, KC_RGUI, MNU_FNC, KC_RALT, KC_RCTL
*/
           ),

  /* Keymap 1: Navigation, VIM
   * Parent: Default
   *    Actvtr: Space
   * ,-----------------------------------------------------------.
   * |   |   |   |   |End|   |   |   |   |   |Hom|   |   |  Del  |
   * |-----------------------------------------------------------|
   * |     |wu |lc | u | rc|   |   |   |   |   |SHn|PU|PgD| Ins  |
   * |-----------------------------------------------------------|
   * |      |wd | l | d | r |   | h | j | k | l |   |   |        |
   * |--------------------.-----------.--------------------------|
   * |        |xxx|   |   |   |    |    |   |   |   |xxx| SftDel |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_NAV] = LAYOUT_60_ansi(

_____, _____,  _____,   _____,   KC_END,  _____, _____,   _____,   _____, _____,   KC_HOME, _____,   _____,   KC_DEL, \
_____, MS_WUP, MS_BTN1, MS_UP,   MS_BTN2, _____, _____,   _____,   _____, _____,   KC_RGHT, KC_PGUP, KC_PGDN, KC_INS, \
_____, MS_WDN, MS_LEFT, MS_DOWN, MS_RGHT, _____, _____,   KC_LEFT, _____, _____,  _____,   _____,   _____,           \
_____, Z_NAV,  _____,   KC_DOWN, KC_UP,   _____, _____,   _____,   _____, _____,   SL_NAV,  SH_DEL,                   \
_____, _____,  _____,   _____,   _____,   _____, _____,   _____

/*
_____, _____,  _____,   _____,   KC_END,  _____, _____,   _____,   _____, _____,   KC_HOME, _____,   _____,   KC_DEL, \
_____, MS_WUP, MS_BTN1, MS_UP,   MS_BTN2, _____, _____,   _____,   _____, _____,   M_SHN,   KC_PGUP, KC_PGDN, KC_INS, \
_____, MS_WDN, MS_LEFT, MS_DOWN, MS_RGHT, _____, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _____,   _____,   _____,           \
_____, Z_NAV,  _____,   _____,   _____,   _____, _____,   _____,   _____, _____,   SL_NAV,  SH_DEL,                   \
_____, _____,  _____,   _____,   _____,   _____, _____,   _____
*/
           ),

  /* Keymap 2: Function, Media
   * Parent: Default
   * ,-----------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |LOK|CAD|CSE|   |   |   |   |   |   |Ply|I<| >I|      |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |--------------------.-----------.--------------------------|
   * |        |   |   |   |   |    |    |   |VlD|VlU|Mut| SftDel |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |XXXX|    |    |    |
   * `-----------------------------------------------------------'
   */
  [_FNC] = LAYOUT_60_ansi(
KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, \
_____,  M_LOK, M_CAD, M_CSE, _____, _____, _____, _____, _____,   _____,   KC_MPLY, KC_MPRV, KC_MNXT, _____,  \
_____,  _____, _____, _____, _____, _____, _____, _____, _____,   _____,   _____,   _____,   _____,           \
_____,  _____, _____, _____, _____, _____, _____, _____, KC_VOLD, KC_VOLU, KC_MUTE, SH_DEL,                   \
_____,  _____, _____, _____, _____, _____, _____, _____
           ),

  /* Keymap 3: Symbols
   * Parent: Default
   * ,-----------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |  |   | Ins  |
   * |-----------------------------------------------------------|
   * |      | { | [ | ( | - | < | > | = | ) | ] | } |   |        |
   * |--------------------.-----------.--------------------------|
   * |        |   |   |   |   |    |    |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |    |    |    |          XXXX          |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_SYM] = LAYOUT_60_ansi(
KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, \
_____,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  _____,   KC_INS, \
_____,   KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK, KC_RABK, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, _____,   _____,           \
_____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,                    \
_____,   _____,   _____,   XXXXX,   _____,   _____,   _____,   _____
           )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // on keydown 
  if (record->event.pressed) {

    if (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI)) {
      switch(keycode) {
        // windows/meta key activated macros for i3 parity :D
        case KC_H :
          SEND_STRING(SS_TAP(X_LEFT));
          return false; break;
        case KC_J :
          SEND_STRING(SS_TAP(X_DOWN));
          return false; break;
        case KC_K :
          SEND_STRING(SS_TAP(X_UP));
          return false; break;
        case KC_L :
          SEND_STRING(SS_TAP(X_RIGHT));
          return false; break;
        case KC_Q :
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_F4));
          SEND_STRING(SS_UP(X_LALT));
          return true; break; // want W-Q to still go through for i3 setup
      }
    } else if (get_mods() & MOD_BIT(KC_LSFT)) {
      switch(keycode) {
        case KC_VOLD :
          SEND_STRING(SS_TAP(X_MEDIA_PREV_TRACK));
          return false; break;
        case KC_VOLU :
          SEND_STRING(SS_TAP(X_MEDIA_NEXT_TRACK));
          return false; break;
        case KC_MUTE :
          SEND_STRING(SS_TAP(X_MEDIA_PLAY_PAUSE));
          return false; break;
      }
    }

  // on keyup
  } else {
  }

  return true;
}

void td_atab_fn(qk_tap_dance_state_t *state, void *user_data) {
  if (state-> count == 1) {
    SEND_STRING(SS_DOWN(X_LALT));
    SEND_STRING(SS_TAP(X_TAB));
  } else {
    SEND_STRING(SS_TAP(X_TAB));
  }
}

void td_atab_done_fn(qk_tap_dance_state_t *state, void *user_data) {
  SEND_STRING(SS_UP(X_LALT));
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ALTAB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(td_atab_fn, td_atab_done_fn, NULL, 300)
};

