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
#define _NAV 1
#define _NUMPAD 2
#define _FUNC 3

// Mod Taps
#define SH_BSP MT(MOD_RSFT, KC_BSPC)
#define SH_DEL MT(MOD_RSFT, KC_DEL)
#define CT_ESC CTL_T(KC_ESC)
#define AL_ENT ALT_T(KC_ENT)
#define SH_SLSH MT(MOD_RSFT, KC_SLSH)

// Layer Taps
#define FN_MNU LT(_FUNC, KC_APP)
#define SP_NAV LT(_NAV, KC_SPC)

#define _____ KC_TRNS
#define XXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default Layer (Qwerty)
   * ,-----------------------------------------------------------.
   * | ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |   Bs  |
   * |-----------------------------------------------------------|
   * | Tab | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \  |
   * |-----------------------------------------------------------|
   * | EsCtl | A | S | D | F | G | H | J | K | L | ; | ' | AlEnt |
   * |-----------------------------------------------------------|
   * | Shift  | Z | X | C | V | B | N | M | , | . | / |  SftBsp  |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |         Space           |Nav |Gui |Mnu|Ctrl|
   * `-----------------------------------------------------------'
   */
  [0] = LAYOUT_60_ansi(
	       KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,    KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
	       KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
	       CT_ESC,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, AL_ENT,  \
	       KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT, SH_SLSH, SH_BSP,  \
	       KC_LCTL, KC_LALT, KC_LGUI, SP_NAV, FN_MNU, KC_RGUI, KC_RALT, KC_RCTL
		   ),

  /* Keymap 1: Navigation, VIM
   * Parent: Default
   *	Actvtr: Space
   * Chldrn: Numpad (RCtrl)
   * ,-----------------------------------------------------------.
   * |   |   |   |   |End|   |   |   |   |   |Hom|   |   |  Del  |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |PU|PgD| Ins  |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   | h | j | k | l |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |    |    |   |   |   |   | SftDel |
   * |-----------------------------------------------------------|
   * |    |    |    |          XXXX          |    |    |    |NumP|
   * `-----------------------------------------------------------'
   */
  [_NAV] = LAYOUT_60_ansi(
	       _____, _____, _____, _____, KC_END, _____, _____,   _____,   _____, _____,   KC_HOME, _____,   _____,   KC_DEL, \
	       _____, _____, _____, _____, _____,  _____, _____,   _____,   _____, _____,   _____,   KC_PGUP, KC_PGDN, KC_INS, \
	       _____, _____, _____, _____, _____,  _____, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _____,   _____,   _____,   \
	       _____, _____, _____, _____, _____,  _____, _____,   _____,   _____, _____,   _____,   SH_DEL,  \
	       _____, _____, _____, _____, _____,  _____, _____,   TG(_NUMPAD)
		   ),

  /* Keymap 2: Numpad Layer
   * Parent: Navigation
   * Chldrn: None
   * ,-----------------------------------------------------------.
   * |   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   | 7 | 8 | 9 |   |   |  |   |      |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   | 4 | 5 | 6 |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |  0 |  1 | 2 | 3 | . | / |        |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |NumP|
   * `-----------------------------------------------------------'
   */

  [_NUMPAD] = LAYOUT_60_ansi(
	       _____, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,         KC_8, KC_9,   KC_0,    KC_MINS, KC_EQL, KC_BSPC, \
	       _____, _____, _____, _____, _____, _____, KC_7,  KC_8,         KC_9, _____,  _____,   _____,   _____,  _____,   \
	       _____, _____, _____, _____, _____, _____, KC_4,  KC_5,         KC_6, _____,  _____,   _____,   _____,  \
	       _____, _____, _____, _____, _____, KC_0,  KC_1,  KC_2,         KC_3, KC_DOT, KC_SLSH, _____,   \
	       _____, _____, _____, _____, _____, _____, _____, TG(_NUMPAD)
		   ),

  /* Keymap 3: Function, Media
   * Parent: Default
   * Chldrn: None
   * ,-----------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Del   |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |PSc|SLk|   |  |   |      |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |MPrv|MNxt|Mut|VlD|VlU|Ply| SftDel |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |XXXX|    |Caps|NumP|
   * `-----------------------------------------------------------'
   */
  [_FUNC] = LAYOUT_60_ansi(
	       KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, KC_DEL, \
	       _____,  _____, _____, _____, _____, _____,   _____,   _____,   KC_PSCR, KC_SLCK, _____,   _____,  _____,  _____,  \
	       _____,  _____, _____, _____, _____, _____,   _____,   _____,   _____,   _____,   _____,   _____,  KC_ENT, \
	       _____,  _____, _____, _____, _____, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, SH_DEL, \
	       _____,  _____, _____, _____, _____, _____,   KC_CAPS, TG(_NUMPAD)
		   ),
};


const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      /* switch(id) { */
      /*   case 0: */
      /*     if (record->event.pressed) { */
      /*       register_code(KC_RSFT); */
      /*     } else { */
      /*       unregister_code(KC_RSFT); */
      /*     } */
      /*   break; */
      /* } */
    return MACRO_NONE;
};


void led_set_user(uint8_t usb_led) {
}
