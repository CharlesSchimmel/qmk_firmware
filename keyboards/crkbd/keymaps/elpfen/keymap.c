/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include <stdio.h>
#include "elpfen.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                _____________Dvorak_1Up_Sides_12k__________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                _____________Dvorak_Home_Sides_12k_________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           _____________Dvorak_1Dn_Sides_L_6k_________,                              _____________Dvorak_1Dn_Sides_R_6k_________,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _____________Base_Bottom_Center_6k_________
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                _____________SYM_1Up_Sides_12k_____________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                _____________SYM_Home_Sides_12k____________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           _____________SYM_1Dn_Sides_L_6k____________,                              _____________SYM_1Dn_Sides_R_6k____________,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _____________SYM_Bottom_Center_6k__________
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                _____________NAV_1Up_Sides_12k_____________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                _____________NAV_Home_Sides_12k____________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           _____________NAV_1Dn_Sides_L_6k____________,                              _____________NAV_1Dn_Sides_R_6k____________,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJ] = LAYOUT_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                _____________ADJ_1Up_Sides_12k_____________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                _____________ADJ_Home_Sides_12k____________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           _____________ADJ_1Dn_Sides_L_6k____________,                              _____________ADJ_1Dn_Sides_R_6k____________,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  } else {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_ln_P(PSTR("DVK"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("VIM"), false);
            break;
        case _ADJ:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
    }

    oled_write_ln_P(PSTR(""), false);

    oled_write_P(PSTR(" GUI "), (modifiers & MOD_BIT(KC_LGUI)) | (modifiers & MOD_BIT(KC_RGUI)));
    oled_write_P(PSTR(" ALT "), (modifiers & MOD_BIT(KC_LALT)) | (modifiers & MOD_BIT(KC_RALT)));
    oled_write_P(PSTR(" SFT "), (modifiers & MOD_BIT(KC_LSFT)) | (modifiers & MOD_BIT(KC_RSFT)));
    oled_write_P(PSTR(" CTL "), (modifiers & MOD_BIT(KC_LCTL)) | (modifiers & MOD_BIT(KC_RCTL)));

    static const char PROGMEM icon[] = {
        0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x60, 0x20, 0x10, 0x10, 0x08, 0x08, 0x04, 0x06, 0x02, 0x01, 
        0x01, 0x02, 0x02, 0x04, 0x0c, 0x08, 0x10, 0x10, 0x20, 0x60, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 
        0xfe, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xfe, 
        0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
        0x0f, 0x10, 0x10, 0x20, 0x20, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x20, 0x20, 0x10, 0x10, 0x0f, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x04, 0x0c, 0x08, 0x10, 
        0x10, 0x08, 0x08, 0x04, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_set_cursor(0, 11);
    oled_write_raw_P(icon, sizeof(icon));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        // off
    }
    return false;
}

#endif // OLED_ENABLE

#ifdef RGBLIGHT_ENABLE
enum light_layers {
    LL_DVK,
    LL_SYM,
    LL_NAV,
    LL_ADJ,
    LL_END_NULL
};

const rgblight_segment_t PROGMEM ll_sym[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM ll_nav[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_GREEN}
);

const rgblight_segment_t PROGMEM ll_mcr[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_RED}
);

const rgblight_segment_t PROGMEM ll_adj[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_CORAL}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = {
    [LL_SYM] = ll_sym,
    [LL_NAV] = ll_nav,
    [LL_ADJ] = ll_adj,
    [LL_END_NULL] = NULL // required, see definition for RGBLIGHT_LAYERS_LIST
};

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

void light_layer_state_set(layer_state_t state) {
    rgblight_set_layer_state(LL_SYM, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(LL_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(LL_ADJ, layer_state_cmp(state, _ADJ));
}

// this might need to happen after pro_rec_user
bool light_layer_prorec(uint16_t keycode, keyrecord_t *record) {
    /* uint8_t modifiers = (get_mods() | get_oneshot_mods()); */
    /* rgblight_set_layer_state(LL_SFT, (modifiers & MOD_BIT(KC_LSHIFT))); */
    /* rgblight_set_layer_state(LL_CTL, WITH_CTRL); */
    /* rgblight_set_layer_state(LL_ALT, WITH_ALT); */
    return true;
}
#endif

layer_state_t layer_state_set_user(layer_state_t current_state) {
    current_state = elpfen_default_layer_state_set(current_state);
#ifdef RGBLIGHT_ENABLE
    light_layer_state_set(current_state);
#endif
    return current_state;
}


// ~~~~ Keypress Processing ~~~~~
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return
#ifdef RGBLIGHT_ENABLE
        light_layer_prorec(keycode, record) &&
#endif
        ELPFEN_DEFAULT_PROREC
        ;
}
