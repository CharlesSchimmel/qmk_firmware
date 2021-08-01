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
#include "elpfen.h"

// LAYER DEFs
#define _DEF 0
#define _NAV 1
#define _FUNC 2
#define _SYM 3

// Mod Taps
#define AL_3    ALT_T(KC_3)
#define AL_8    RALT_T(KC_8)

#define CT_2    CTL_T(KC_2)
#define CT_9    RCTL_T(KC_9)

// Layer Taps

// Modded Keys
#define SH_INS LSFT(KC_INS)

// Quick Macros
#define M_LOK LGUI(KC_L)
#define M_CAD LCA(KC_DEL)
#define M_CSE LCTL(LSFT(KC_ESC))

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

/*
KC_GESC, KC_1,    CT_2,    AL_3,   KC_4,    KC_5,    KC_6,    KC_7, AL_8,    CT_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
AL_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P,    KC_Y,    KC_F,    KC_G, KC_C,    KC_R,   KC_L,    KC_LBRC, KC_RBRC, CT_BSLS, \
CT_ESC,  KC_A,    KC_O,    KC_E,   KC_U,    KC_I,    KC_D,    KC_H, KC_T,    KC_N,   KC_S,    KC_MINS, AL_ENT,           \
SH_TAB,  RS_SCLN,  KC_Q,    KC_J,   KC_K,    KC_X,    KC_B,    KC_M, KC_W,    KC_V,   RS_Z,   SH_BSP,                    \
KC_LCTL, FN_MNU, KC_LGUI, LW_SPC, KC_RGUI, FN_MNU, KC_RALT, KC_RCTL
*/

KC_GESC, KC_1,    CT_2,    AL_3,   KC_4,    KC_5,    KC_6,    KC_7, AL_8,    CT_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
AL_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, CT_BSLS, \
CT_ESC,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, AL_ENT,           \
SH_TAB,  RS_Z,   KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT, RS_SCLN,  SH_BSP,                    \
KC_LCTL, FN_MNU,  KC_LGUI, LW_SPC, KC_RGUI, FN_MNU, KC_RALT, KC_RCTL
           ),

  /* Keymap 1: Navigation, VIM
   * Parent: Default
   *    Actvtr: Space
   * ,-----------------------------------------------------------.
   * | ` |   |   |   |End|   |   |   |   |   |Hom|   |   |  Del  |
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

/*
KC_GRV, _____,  _____,   _____,   KC_END,  _____, _____,   _____,   _____, _____,   KC_HOME, _____,   _____,   KC_DEL, \
_____, MS_WUP, MS_BTN1, MS_UP,   MS_BTN2, _____, _____,   _____,   _____, _____,   KC_RGHT, KC_PGUP, KC_PGDN, KC_INS, \
_____, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _____, _____,   KC_LEFT, _____, _____,  _____,   _____,   _____,           \
_____, RS_Z,  _____,   KC_DOWN, KC_UP,   _____, _____,   _____,   _____, _____,   RS_SCLN,  SH_DEL,                   \
_____, _____,  _____,   _____,   _____,   _____, _____,   _____
*/

_____, _____,  _____,   _____,   KC_END,  _____, _____,   _____,   _____, _____,   KC_HOME, _____,   _____,   KC_DEL, \
_____, MS_WUP, MS_BTN1, MS_UP,   MS_BTN2, _____, _____,   _____,   _____, _____,   M_PST,   KC_PGUP, KC_PGDN, KC_INS, \
_____, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _____, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _____,   _____,   _____,           \
_____, RS_Z,  _____,   _____,   _____,   _____, _____,   _____,   _____, _____,   RS_SCLN,  SH_DEL,                   \
_____, _____,  _____,   _____,   _____,   _____, _____,   _____
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
  [_FUNC] = LAYOUT_60_ansi(
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

bool process_record_user(uint16_t current_keycode, keyrecord_t *record) {
  return vim_windows_movement(current_keycode, record)
      && dual_purpose_volume_keys(current_keycode, record)
      && true;
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

