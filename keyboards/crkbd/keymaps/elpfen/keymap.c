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
  ),


  [_MCR] = LAYOUT_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                _____________MCR_1Up_Sides_12k_____________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                _____________MCR_Home_Sides_12k____________,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _____________MCR_1Dn_Sides_L_6k____________,                                _____________MCR_1Dn_Sides_R_6k____________,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _____________MCR_BotCenter_6k______________
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _DVORAK:
            oled_write_ln_P(PSTR("Dvorak"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Vimmish"), false);
            break;
        case _ADJ:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool oled_prorec(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

#ifdef RGBLIGHT_ENABLE
enum light_layers {
    LL_DVK,
    LL_SYM,
    LL_NAV,
    LL_ADJ,
    LL_SFT,
    LL_CTL,
    LL_ALT,
    // LL_GUI,
    LL_END_NULL
};

const rgblight_segment_t PROGMEM ll_dvk[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 6, HSV_CYAN}       // Light 4 LEDs, starting with LED 6
);

const rgblight_segment_t PROGMEM ll_sym[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 6, HSV_CYAN}
);

const rgblight_segment_t PROGMEM ll_nav[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 6, HSV_GREEN}
);

const rgblight_segment_t PROGMEM ll_adj[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 6, HSV_TEAL}
);

const rgblight_segment_t PROGMEM ll_sft[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 3, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM ll_ctl[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 3, HSV_CORAL}
);

const rgblight_segment_t PROGMEM ll_alt[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 3, HSV_YELLOW}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = {
    [LL_DVK] = ll_dvk,
    [LL_SYM] = ll_sym,
    [LL_NAV] = ll_nav,
    [LL_ADJ] = ll_adj,
    [LL_SFT] = ll_sft,
    [LL_CTL] = ll_ctl,
    [LL_ALT] = ll_alt,
    [LL_END_NULL] = NULL // required, see definition for RGBLIGHT_LAYERS_LIST
};

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

void default_light_layer_set(layer_state_t state) {
    rgblight_set_layer_state(LL_DVK, layer_state_cmp(state, _DVORAK));
}

void light_layer_state_set(layer_state_t state) {
    rgblight_set_layer_state(LL_SYM, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(LL_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(LL_ADJ, layer_state_cmp(state, _ADJ));
}

// this might need to happen after pro_rec_user
bool light_layer_prorec(uint16_t keycode, keyrecord_t *record) {
    rgblight_set_layer_state(LL_SFT, WITH_SHIFT);
    rgblight_set_layer_state(LL_CTL, WITH_CTRL);
    rgblight_set_layer_state(LL_ALT, WITH_ALT);
    return true;
}
#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    default_light_layer_set(state);
#endif
    return state;
}

// ~~~~ Keypress Processing ~~~~~
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_macros(keycode, record)
        && pseudo_twm(keycode, record)
        && multi_purpose_volume_keys(keycode, record)
        && vimmish_keys(keycode, record)
        && layer_sticky_mods(keycode, record, _ADJ)
        && switchboard_adj(keycode, record)
        && process_caps_word(keycode, record)
#ifdef RGBLIGHT_ENABLE
        && light_layer_prorec(keycode, record)
#endif
#ifdef OLED_ENABLE
        && oled_prorec(keycode, record)
#endif
        ;
}

