/* Copyright 2021 elpfen
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
#include "muse.h"
#include "elpfen.h"

#define LAYOUT_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

enum layers {
  _QWERTY = ELPFEN_LAYERS_END,
  _QNAV,
  _UTIL
};

enum custom_keycodes {
  DVORAK = ELPFEN_KEYCODES_END,
  QWERTY,
  BACKLIT
};

#define LOWER MO(_SYM)
#define RAISE MO(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 *     `         '       ,        .        P        Y        F        G        C        R        L        /
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *  Ctl-Esc      A       O        E        U        I        D        H        T        N        S      Ctl--
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *  Sh-Tab    Nav-;    Alt-Q      J        K        X        B        M        W      Alt-V    Nav-Z   Sh-BckSp
 * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┴────────┼────────┼────────┼────────┼────────┤
  *                            Fnc-App    LGUI   Sym-Entr Sym-Spce   RGUI   Fnc-App
 * └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_DVORAK] = LAYOUT_wrapper(
                                _____________Dvorak_1Up_Sides_12k__________,
                                _____________Dvorak_Home_Sides_12k_________,
                                _____________Dvorak_1Dn_Sides_12k__________,
   _______, _______, _______, KC_APP, KC_LGUI, LW_ENT, LW_SPC, KC_RGUI, KC_APP, _______, _______, MO(_UTIL)
),

/* Qwerty
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 *     `        Q        W        E        R        T        Y        U        I        O        P        /
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *  Ctl-Esc     A        S        D        F        G        H        J        K        L        ;      Ctl-'
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *   Sh-Tab   Nav-Z      X        C        V        B        N        M        ,        .      Nav-/   Sh-BckSp
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *                             Fnc-App    LGUI   Sym-Entr Sym-Spce   RGUI   Fnc-App
 * └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_QWERTY] = LAYOUT_planck_grid(
   KC_GRV,  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_SLSH,
   CT_ESC,  KC_A,    KC_S,   KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, CT_QUOT,
   SH_TAB,  RS_Z,    AL_X,   KC_C,    KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, AL_DOT, RS_SLSH, SH_BSP,
   _______, _______, KC_APP, KC_LGUI, LW_ENT, LW_ENT, LW_SPC, LW_SPC, KC_RGUI, KC_APP, _______, MO(_UTIL)
),

/* SYMbols
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 *              1        2        3        4        5        6        7        8        9        0        \
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *              [        {        (        -        <        >        =        )        }        [
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *   1Shft     ADJ      1Alt     1Ctl                                FNC      1Ctl     1Alt     ADJ     1Shft
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                                                   OOO      OOO
 * └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_SYM] = LAYOUT_wrapper(
                                    _____________SYM_1Up_Sides_12k_____________,
    _______,                        _____________SYM_Home_Core_10k_____________,                       _______,
        _____________SYM_1Dn_Sides_L_6k____________,            _____________SYM_1Dn_Sides_R_6k____________,
    _______, _______, _______,      _____________SYM_Bottom_Center_6k__________,      _______, _______, _______
),

/* NAVigation
 * ,-----------------------------------------------------------------------------------.
 * |      | MwUp |  M1  | MUp  |  M2  |      | Home | PgDn | PgUp | End  |  ->  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MwDn | MLft | MDn  | MRht |      |      |  <-  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | OOOO |      | ArDn | ArUp |      |      |      |      |      | OOOO | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RGHT, KC_INS,
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, KC_LEFT, _______, _______, _______, _______,
   _______, L_NAV,   KC_LCTL, KC_DOWN, KC_UP,   _______, _______, _______, _______, KC_RCTL, L_NAV,   SH_DEL,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* QWERTY Nav
 * Need a different layer for QWERTY nav so that the Vim arrows are in the right place
 * Everything else is the same.
 * ,-----------------------------------------------------------------------------------.
 * |      | MwUp |  M1  | MUp  |  M2  |      | Home | PgDn | PgUp | End  |  Pst | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MwDn | MLft | MDn  | MRht |      |  <-  |  Dn  |  Up  |  ->  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | OOOO |      |      |      |      |      |      |      |      | OOOO | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QNAV] = LAYOUT_planck_grid(
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  M_PST,   KC_INS,
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_QUOT,
   _______, OOOOOOO, _______, _______, _______, _______, _______, _______, _______, _______, OOOOOOO, SH_DEL,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* FNCtions
 * ,-----------------------------------------------------------------------------------.
 * |  CSE | Mut  | VolD | VolU |      | PScr |  F9  | F10  | F11  | F12  | Lok  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | CAD  |      |  F5  |  F6  |  F7  |  F8  | Slep |      |
 * |------+------+------+------+--..--+------+------+--..--+------+------+------+------|
 * |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F4  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |VolDn |VolUp | Mute |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FNC] = LAYOUT_wrapper(
M_CSE,   KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_PSCR, KC_F9,   KC_F10,  KC_F11,  KC_F12,  M_LOK,   _______,
_______, _______, _______, _______, M_CAD,   _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_SLEP, _______,
_______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJ] = LAYOUT_wrapper(
    _____________ADJ_1Up_Sides_12k_____________,
    _____________ADJ_Home_Sides_12k____________,
    _____________ADJ_1Dn_Sides_L_6k____________, _____________ADJ_1Dn_Sides_R_6k____________,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Util
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UTIL] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______, _______, AU_ON,   AU_OFF,  _______, _______, QWERTY,  _______,  DVORAK,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, TG(_UTIL)
),

[_MOUSE] = LAYOUT_planck_grid(
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______, _______, _______, _______, _______, _______, _______,
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, OOOOOOO, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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

bool process_macros(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return pseudo_twm(keycode, record)
      && multi_purpose_volume_keys(keycode, record)
      && process_macros(keycode, record)
      && layer_lock(keycode, record)
      && vimmish_keys(keycode, record)
      && layer_sticky_mods(keycode, record, _ADJ)
      && true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_off(_ADJ);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

