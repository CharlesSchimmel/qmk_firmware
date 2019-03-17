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
#define AL_BSLS ALT_T(KC_BSLS)
#define AL_ENT  ALT_T(KC_ENT)
#define AL_TAB  RALT_T(KC_TAB)

#define CT_BSLS RCTL_T(KC_BSLS)
#define CT_ENT  CTL_T(KC_ENT)
#define CT_ESC  CTL_T(KC_ESC)

#define SH_BSP  MT(MOD_RSFT, KC_BSPC)
#define SH_DEL  MT(MOD_RSFT, KC_DEL)
#define SH_SLSH MT(MOD_RSFT, KC_SLSH)
#define SH_TAB  MT(MOD_LSFT, KC_TAB)

// Layer Taps
#define MNU_FNC LT(_SYM, KC_APP)
#define SP_NAV LT(_NAV, KC_SPC)
#define SP_SYM LT(_SYM, KC_SPC)
#define SC_NAV LT(_NAV, KC_SCLN)

// Macro defs
enum custom_keycodes {
  M_LOK = SAFE_RANGE,
  M_CAD,
};

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
   * |Ctrl|Alt |Gui |         SpSym           |Sym | Fn |Alt|Ctrl|
   * `-----------------------------------------------------------'
   */
  [0] = LAYOUT_60_ansi(
	       KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
	       AL_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, CT_BSLS, \
	       CT_ESC,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J, KC_K,    KC_L,   SC_NAV,  KC_QUOT, AL_ENT,  \
	       SH_TAB,  KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, SH_BSP,  \
	       KC_LCTL, KC_LALT, KC_LGUI, SP_SYM, MNU_FNC, TD(TD_ALTAB), KC_RALT, KC_RCTL
		   ),

  /* Keymap 1: Navigation, VIM
   * Parent: Default
   *	Actvtr: Space
   * ,-----------------------------------------------------------.
   * |   |   |   |   |End|   |   |   |   |   |Hom|   |   |  Del  |
   * |-----------------------------------------------------------|
   * |     |wu |lc | u | rc|   |   |   |   |   |   |PU|PgD| Ins  |
   * |-----------------------------------------------------------|
   * |      |wd | l | d | r |   | h | j | k | l |XxX|   |        |
   * |--------------------.-----------.--------------------------|
   * |        |   |   |   |   |    |    |   |   |   |   | SftDel |
   * |-----------------------------------------------------------|
   * |    |    |    |          XXXX          |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_NAV] = LAYOUT_60_ansi(
       _____, _____,         _____,      _____,      KC_END,      _____, _____,   _____,   _____, _____,   KC_HOME, _____,   _____,   KC_DEL, \
	       _____, KC_MS_WH_UP,   KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  _____, _____,   _____,   _____, _____,   _____,   KC_PGUP, KC_PGDN, KC_INS, \
	       _____, KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _____, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _____,   _____,   _____,   \
	       _____, _____,         _____,      _____,      _____,       _____, _____,   _____,   _____, _____,   _____,   SH_DEL,  \
	       _____, _____,         _____,      _____,      _____,       _____, _____,   _____
		   ),

  /* Keymap 2: Function, Media
   * Parent: Default
   * ,-----------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |LOK|CAD|   |   |   |   |   |   |   |Ply|I<| >I|      |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |--------------------.-----------.--------------------------|
   * |        |Prn|Slk|   |   |    |    |   |VlD|VlU|Mut| SftDel |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |XXXX|    |    |
   * `-----------------------------------------------------------'
   */
  [_FNC] = LAYOUT_60_ansi(
	       KC_GRV, KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, \
	       _____,  M_LOK,   M_CAD,   _____, _____, _____, _____,   _____, _____,   _____,   KC_MPLY, KC_MPRV, KC_MNXT, _____,  \
	       _____,  _____,   _____,   _____, _____, _____, _____,   _____, _____,   _____,   _____,   _____,   _____,           \
	       _____,  _____,   _____,   _____, _____, _____, _____,   _____, KC_VOLD, KC_VOLU, KC_MUTE, SH_DEL,                   \
	       _____,  _____,   _____,   _____, _____, _____, _____,   _____
		   ),

  /* Keymap 3: Symbols
   * Parent: Default
   * ,-----------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     | { | [ | ( | = |   |   | - | ) | ] | } |  |   |      |
   * |-----------------------------------------------------------|
   * |      | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | = |        |
   * |--------------------.-----------.--------------------------|
   * |        |   |   |   |   |    |    |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |    |    |    |          XXXX          |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_SYM] = LAYOUT_60_ansi(
	       KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   \
	       _____,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  _____,   _____,    \
	       _____,   KC_LBRC, KC_LCBR, KC_LPRN, KC_EQL,  _____,   _____,   KC_MINS, KC_RPRN, KC_RCBR, KC_RBRC, _____,   _____,             \
	       _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,                      \
	       _____,   _____,   _____,   XXXXX,   _____,   _____,   _____,   _____
		   )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // on keydown
  if (record->event.pressed) {

	switch(keycode) {
	  case M_LOK :
		SEND_STRING(SS_LGUI("l"));
		return false;
	  case M_CAD :
		SEND_STRING(SS_DOWN(X_LCTRL));
		SEND_STRING(SS_DOWN(X_LALT));
		SEND_STRING(SS_TAP(X_DELETE));
		SEND_STRING(SS_UP(X_LALT));
		SEND_STRING(SS_UP(X_LCTRL));
		return false;
	}

	// windows/meta key activated macros for i3 parity :D
	if (get_mods() & MOD_BIT(KC_LGUI)) {
	  switch(keycode) {
		case KC_H :
		  SEND_STRING(SS_TAP(X_LEFT));
		  return false;
		case KC_J :
		  SEND_STRING(SS_TAP(X_DOWN));
		  return false;
		case KC_K :
		  SEND_STRING(SS_TAP(X_UP));
		  return false;
		case KC_L :
		  SEND_STRING(SS_TAP(X_RIGHT));
		  return false;
		case KC_Q :
		  SEND_STRING(SS_DOWN(X_LALT));
		  SEND_STRING(SS_TAP(X_F4));
		  SEND_STRING(SS_UP(X_LALT));
		  return true; // want W-Q to still go through for i3 setup
		  break;
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

