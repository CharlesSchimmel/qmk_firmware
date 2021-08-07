/* Copyright 2017 elpfen
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

#include QMK_KEYBOARD_H
#include "elpfen.h"

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
  [_BASE] = LAYOUT_60_ansi(
    KC_GESC, KC_1,   KC_2,    KC_3,   KC_4,    KC_5,   KC_6,    KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    AL_TAB,  KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,   KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, CT_BSLS,
    CT_ESC,  KC_A,   KC_S,    KC_D,   KC_F,    KC_G,   KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, AL_ENT,
    SH_TAB,  RS_Z,   KC_X,    KC_C,   KC_V,    KC_B,   KC_N,    KC_M, KC_COMM, KC_DOT, RS_SCLN, SH_BSP,
    KC_LCTL, FN_MNU, KC_LGUI, LW_SPC, KC_RGUI, FN_MNU, KC_RALT, KC_RCTL
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
    _______, _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, KC_HOME, _______, _______, KC_DEL,
    _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______, _______, _______, _______, _______, M_PST,   KC_PGUP, KC_PGDN, KC_INS,
    _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
    _______, RS_Z,    _______, _______, _______, _______, _______, _______, _______, _______, RS_SCLN, SH_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______
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
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, M_LOK,   M_CAD,   M_CSE,   _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, SH_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______
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
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  _______, KC_INS,
    _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK, KC_RABK, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, OOOOOOO, _______, _______, _______, _______
  )

};

bool process_record_user(uint16_t current_keycode, keyrecord_t *record) {
  return pseudo_twm(current_keycode, record)
      && multi_purpose_volume_keys(current_keycode, record)
      && true;
}

