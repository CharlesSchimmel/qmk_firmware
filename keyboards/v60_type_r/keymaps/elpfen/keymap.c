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

#define LAYOUT_wrapper(...) LAYOUT_60_ansi(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Dvorak
   * ,-----------------------------------------------------------.
   * | ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |   \   |
   * |-----------------------------------------------------------|
   * |  `  | ' | , | . | P | y | f | g | c | r | l | / | = |  /  |
   * |-----------------------------------------------------------|
   * | EsCtl | a | o | e | u | i | d | h | t | n | s |-Ct| SyEnt |
   * |---------------------.-----------.-------------------------|
   * | ShTab  | ; | q | j | k | x | b | m | w | v | z |  SftBsp  |
   * |-----------------------------------------------------------|
   * |Ctrl|MFnc|Gui |         SpSym           |RGui| Fn |Alt|Ctrl|
   * `-----------------------------------------------------------'
   */
  [_BASE] = LAYOUT_wrapper(
                      KC_GRV, _____________Dvorak_2Up_Core_10k___________, KC_LBRC, KC_RBRC, KC_BSLS,

                      KC_GRV, _____________Dvorak_1Up_Core_10k___________, KC_SLSH, KC_EQL,  KC_BSLS,
                              _____________Dvorak_Home_Sides_12k_________,                    LW_ENT,
                              _____________Dvorak_1Dn_Sides_12k__________,
    KC_LCTL, FN_MNU, KC_LGUI,                  LW_SPC,              KC_RGUI, FN_MNU, KC_RALT, KC_RCTL
  ),

  /* Symbols
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
  [_SYM] = LAYOUT_wrapper(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,
    _______,                         _____________SYM_1Up_Core_10k______________,                      KC_EQL,  _______,  KC_INS,
    _______,                         _____________SYM_Home_Core_10k_____________,                               _______, _______,
    _______, _______, _______, _______, _______, _______,                            _____________SYM_1Dn_Sides_R_6k____________,
    _______, _______, _______,                        OOOOOOO,                                _______, _______, _______, _______
  ),

  /* Navigation
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
  [_NAV] = LAYOUT_wrapper(
    _____________NAV_2Up_Sides_12k_____________, _______, KC_DEL,
    _____________NAV_1Up_Sides_12k_____________, _______, KC_INS,
    _____________NAV_Home_Sides_12k____________, _______,
    _____________NAV_1Dn_Sides_12k_____________,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Keymap 2: Function, Media
   * Parent: Default
   * ,-----------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |VlD|VlU|Mut|   |   |   |PSc|   |   |Lok|  |   |      |
   * |-----------------------------------------------------------|
   * |      |   |   |   |Ulk|   |   |   |   |   |Slp| - |        |
   * |--------------------.-----------.--------------------------|
   * |        |   |   |   |   |    |    |   |   |Wak|   | SftDel |
   * |-----------------------------------------------------------|
   * |    |Rset|    |                        |    |oooo|    |    |
   * `-----------------------------------------------------------'
   */
  [_FNC] = LAYOUT_wrapper(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _____________FNC_1Up_Sides_12k_____________, _______, _______,
    _____________FNC_Home_Sides_12k____________, _______,
    _______, _______, _______, _______, _______, _______, _____________FNC_1Dn_Sides_R_6k____________,
    _______, RESET, _______, _______, _______, OOOOOOO, _______, _______
  ),


};

layer_state_t layer_state_set_user(layer_state_t current_state) {
    static layer_state_t previous_state;

    current_state = lenient_update_tri_layer_state(current_state, _SYM, _NAV, _ADJ);

    // Clear sticky mods: using multiple layers means that the mods will
    // stay on so long as any of those layers is activated. May or may not
    // be desired.
    if (was_layer_turned_off(previous_state, current_state, _ADJ)) {
        clear_mods();
    }

    current_state = switchboard_state(previous_state, current_state);
    previous_state = current_state;

    return current_state;
}

// ~~~~ Keypress Processing ~~~~~
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return pseudo_twm(keycode, record)
        && multi_purpose_volume_keys(keycode, record)
        && layer_lock(keycode, record)
        && vimmish_keys(keycode, record)
        && layer_sticky_mods(keycode, record, _ADJ)
        && true;
}
