/* Copyright 2015-2017 Jack Humbert
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

#define _SYM _LOWER
#define _NAV _RAISE
#define _FNC _ADJUST

enum planck_layers {
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _UTIL
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define AL_TAB  ALT_T(KC_GRV)

// "This key is pressed for this layer"
#define OOOOOOO KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | AlTab|   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Ct/  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | EsCtl|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  Al- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ShTab|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |ShBsp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | LGUI | LEnt | LSpc | RGUI | Menu |      |             |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    AL_GRV,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_F,   KC_G,    KC_C,   KC_R,    KC_L,    CT_SLSH,
    CT_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_D,   KC_H,    KC_T,   KC_N,    KC_S,    AL_MINS,
    SH_TAB,  RS_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_B,   KC_M,    KC_W,   KC_V,    RS_Z,    SH_BSP,
    _______, _______, _______, _______, KC_LGUI, LW_ENT, LW_SPC, KC_RGUI, KC_MNU, _______, _______, _______
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    AL_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    SH_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   {  |   [  |   (  |   -  |   <  |   >  |   =  |   )  |   }  |   ]  |  Al' |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | OOOO | OOOO |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK, KC_RABK, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, AL_QUOT,
    _______, _______, _______, _______, _______, OOOOOOO, OOOOOOO, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      | MwUp |      | MUp  |      |      | Home | PgDn | PgUp | End  |  ->  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MwDn | MLft | MDn  | MRht |      |      |  <-  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | OOOO |      | ArDn | ArUp |      |      |      |      |      | OOOO | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Mute | VlDn | VlUp | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
   _______,  MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RGHT, KC_INS,
   _______,  MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, KC_LEFT, _______, _______, _______, _______,
   _______,  OOOOOOO, _______, KC_DOWN, KC_UP,   _______, _______, _______, _______, _______, OOOOOOO, SH_DEL,
   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Lock | CAD  | CSE  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FNC] = LAYOUT_planck_grid(
   _______, M_LOK,   M_CAD,   M_CSE,   _______, _______, _______, _______, _______, _______, _______, _______,
   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
),

/* Util
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UTIL] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* switch (keycode) { */
    /* case DVORAK: */
    /*   if (record->event.pressed) { */
    /*     set_single_persistent_default_layer(_DVORAK); */
    /*   } */
    /*   return false; */
    /*   break; */
  /* } */
  /* return true; */
  if (record->event.pressed) {

    if ( get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI)) {
      switch(keycode) {
        // windows/meta key activated macros for i3/XMonad parity :D
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
          return false; break;
      }
    } else if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT) ) {
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

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
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
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
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

/* if true, it will try to interpret the keycode as a note
 */
bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
