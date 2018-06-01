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
#define _DVORAK 1
#define _NAV 2
#define _NUMPAD 3
#define _FUNC 4

#define _____ KC_TRNS
#define XXXXX KC_NO

#define _VIM_WORD 1
#define _VIM_BACK 2

#define VIM_WORD M(1)
#define VIM_BACK M(2)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default Layer (Qwerty)
   * ,-----------------------------------------------------------.
   * | ` |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Esc/Ctl|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space,NUM          |Fn0 |Gui |App|Ctrl|
   * `-----------------------------------------------------------'
   */
  [0] = LAYOUT_60_ansi(
	       KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
	       KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
	       CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
	       KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,   \
	       KC_LCTL,       KC_LGUI, KC_LALT,          LT(_NAV,KC_SPC),                         MO(_FUNC),   KC_RGUI, KC_APP,  KC_RCTL),

  /* Keymap 1: Default Layer (DVORAK)
   * ,-----------------------------------------------------------.
   * | ` |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Esc/Ctl|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space,NUM          |Fn0 |Gui |App|Ctrl|
   * `-----------------------------------------------------------'
   */
  [_DVORAK] = LAYOUT_60_ansi(
	       KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC,  KC_BSPC, \
	       KC_TAB,        KC_QUOT,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL, KC_BSLS, \
	       CTL_T(KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,          KC_ENT,  \
	       KC_LSFT,       KC_SCLN,   KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W, KC_V,  KC_Z,          KC_RSFT,   \
	       KC_LCTL,       KC_LGUI, KC_LALT,          LT(_NAV,KC_SPC),                         MO(_FUNC),   KC_RGUI, KC_APP,  KC_RCTL),

  /* Keymap 2: Navigation, VIM
   * Parent: Default
   *	Actvtr: Space
   * Chldrn: Numpad (LCtrl)
   * ,-----------------------------------------------------------.
   * |   |   |   |   |End|   |   |   |   |   |Hom|   |   |  Del  |
   * |-----------------------------------------------------------|
   * |     |   | w |   |   |   |   |   |   |   |   |PU|PgD| Ins  |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   | h | j | k | l |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   | b  |    |   |VlD|VlU|Mut|        |
   * |-----------------------------------------------------------|
   * |NumP|    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_NAV] = LAYOUT_60_ansi(
	       _____,    _____,    _____,    _____,    KC_END,    _____,    _____,     _____,   _____,   _____,   KC_HOME,  _____,   _____,  _____, \
	       _____,   _____,  VIM_WORD,     _____,  _____,  _____,  _____,   _____, _____, _____, _____, KC_PGUP,    KC_PGDN,          KC_INS, \
	       _____,   _____,  _____,  _____,  _____,  _____,  KC_LEFT,   KC_DOWN,   KC_UP, KC_RGHT, _____, _____,          _____,          \
	       _____,   _____,  _____,  _____,  _____,  VIM_BACK, _____, _____, KC_VOLD,  KC_VOLU,  KC_MUTE,           _____,  \
	       MO(_NUMPAD),   _____,  _____,            _____,                                                           _____,  _____, _____, _____),

  /* Keymap 3: Numpad Layer
   * Parent: Navigation
   *	Actvtr: LCtrl
   * Chldrn: None
   * ,-----------------------------------------------------------.
   * |   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |Num| 7 | 8 | 9 |   |   |  |   |      |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   | 4 | 5 | 6 |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |  0 |  1 | 2 | 3 | . | / |        |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

  [_NUMPAD] = LAYOUT_60_ansi(
	       _____,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
	       _____,        _____,    _____,    _____,    _____,    KC_NUMLOCK,    KC_KP_7,    KC_KP_8,    KC_KP_9,    _____,    _____,    _____, _____, _____, \
	       _____, _____,    _____,    _____,    _____,    _____,    KC_KP_4,    KC_KP_5,    KC_KP_6,    _____,    _____, _____,          _____,  \
	       _____,       _____,    _____,    _____,    _____,    KC_KP_0,    KC_KP_1,    KC_KP_2,    KC_KP_3, KC_DOT,  KC_SLSH,          _____,   \
	       _____,       _____, _____,          _____,                                      _____,   _____, _____,  _____),

  /* Keymap 4: Function, Media
   * Parent: Default
   *	Actvtr: Fn0
   * Chldrn: None
   * ,-----------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |Pau|<<|>> |      |
   * |-----------------------------------------------------------|
   * | Caps |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |    |    |   |VlD|VlU|Mut|        |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_FUNC] = LAYOUT_60_ansi(
	       KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  _____, \
	       _____,   DF(0),  _____,     _____,  _____,  _____,  _____,   _____, _____, _____, KC_MPLY, KC_MPRV,    KC_MNXT,          _____, \
	       KC_CAPS,   _____,  _____,  DF(_DVORAK),  _____,  _____,  DF(_DVORAK),   _____,   _____, _____, _____, _____,          _____,          \
	       _____,   _____,  DF(0),  _____,  _____,  _____, _____, KC_MUTE, KC_VOLD,  KC_VOLU,  _____,           _____,  \
	       _____,   _____,  _____,            _____,                                                           _____,  _____, _____, _____),
};




const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
		case _VIM_WORD:
		  return MACRO(D(LCTL),T(RIGHT),U(LCTL),T(RIGHT));
		case _VIM_BACK:
		  return MACRO(D(LCTL),T(LEFT),U(LCTL));
        break;
      }
    return MACRO_NONE;
};


void led_set_user(uint8_t usb_led) {
}
