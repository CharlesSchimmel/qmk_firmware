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

enum planck_layers {
  _DVORAK = 0,
  _SYM,
  _NAV,
  _FNC,
  _UTIL,
  _QWERTY,
  _QNAV,
  _ADJUST,
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  BACKLIT,
  L_NAV
};

#define LOWER MO(_SYM)
#define RAISE MO(_NAV)

enum tap_dances {
  TD_VIM_G = 0,
  TD_VI_V
};
#define VI_G TD(TD_VIM_G)
#define VI_V TD(TD_VI_V)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 *     `         '       ,        .        P        Y        F        G        C        R        L        /
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *  Ctl-Esc      A       O        E        U        I        D        H        T        N        S      Ctl--
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *  Sh-Tab    Nav-;    Alt-Q      J        K        X        B        M        W      Alt-V    Nav-Z   Sh-BckSp
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *                             Fnc-App    LGUI   Sym-Entr Sym-Spce   RGUI   Fnc-App
 * └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_DVORAK] = LAYOUT_wrapper(
                                _____________Dvorak_1Up_Sides______________,
                                _____________Dvorak_Home_Sides_____________,
                                _____________Dvorak_1Dn_Sides______________,
    _______, _______, _______,  ___________Base_Bottom_Center_6k___________, _______, _______, TG(_UTIL)
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
   KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH,
   CT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, CT_QUOT,
   SH_TAB,  RS_Z,    AL_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM, AL_DOT,  RS_SLSH, SH_BSP,
   _______, _______, _______, _______, KC_LGUI, LW_ENT, LW_SPC, KC_RGUI, KC_APP,  _______, _______, _______
),

/* SYMbols
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 *              1        2        3        4        5        6        7        8        9        0        \
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *              [        {        (        -        <        >        =        )        }        [
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 *                              Sh+Tab    TAB                        FNC      ADJ                      Sh/Delet
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                                                   OOO      OOO
 * └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_SYM] = LAYOUT_wrapper(
                                    _____________SYM_2U_Sides_12k______________,
    _______,                        _____________SYM_1U_Sides_10k______________,                      _______,
    _______, _______, _______, M_SHTAB, KC_TAB,  _______, _______, _______, _______, _______, _______, SH_DEL,
    _______, _______, _______, _______, _______, OOOOOOO, OOOOOOO, _______, _______, _______, _______, _______
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
 * |      | Lock | CAD  | CSE  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |VolDn |VolUp | Mute |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FNC] = LAYOUT_planck_grid(
   M_CSE,   KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_PSCR, _______, _______, M_LOK,   _______,
   _______, _______, _______, _______, _______, _______, M_CAD,   _______, _______, _______, KC_SLEP, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, QWERTY,  _______,  DVORAK,  _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, TG(_UTIL)
),

[_MOUSE] = LAYOUT(
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______, _______, _______, _______, _______, _______, _______,
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, OOOOOOO, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  ),

};

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

static bool nav_lock = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return vim_windows_movement(keycode, record)
      && dual_purpose_volume_keys(keycode, record)
      && process_macros(keycode, record)
      && true;
}

// ADJUST never works right for me.
/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _SYM, _NAV, _ADJUST); */
/* } */

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_NAV)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_off(_ADJUST);
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

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

static td_tap_t td_tap_state = {
    .state = TD_NONE,
};


static bool visual_mode = false;
void td_vi_v_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_tap_state.state = cur_dance(state);
    switch (td_tap_state.state) {
        case TD_SINGLE_TAP:
            // this sends KC_APP, not sure why
            if (visual_mode) {
                SEND_STRING(SS_UP(X_RSFT));
                visual_mode = false;
            } else {
                SEND_STRING(SS_DOWN(X_RSFT));
                visual_mode = true;
            }
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_RCTL));
            break;
        default: break;

    }
}

void td_vi_v_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (td_tap_state.state == TD_SINGLE_HOLD) {
        SEND_STRING(SS_UP(X_RCTL));
    }
    td_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  // act (sort of) like G in vim: single tap (instead of shift) for END, double
  // tap for HOME. This assumes that systems will interpret C+HOME as "start of file"
  [TD_VIM_G] = ACTION_TAP_DANCE_DOUBLE(C(KC_END), C(KC_HOME)),

  // on tap, toggle "visual mode"
  // on hold, send CTL
  [TD_VI_V] =
    ACTION_TAP_DANCE_FN_ADVANCED_TIME(
        NULL,
        td_vi_v_finished,
        td_vi_v_reset,
        125
        ),

};

