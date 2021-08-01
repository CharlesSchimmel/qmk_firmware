#include QMK_KEYBOARD_H
#include "elpfen.h"

enum layers {
    _BASE = 0,
    _SYM,
    _NAV,
    _FUNC
};

enum tap_dances {
  TD_VIM_G = 0,
  TD_ZMO_NAV,
  TD_SCLNMO_NAV
};
#define TD_VIMG TD(TD_VIM_G)
#define Z_NAV TD(TD_ZMO_NAV)
#define CLN_NAV TD(TD_SCLNMO_NAV)

enum custom_keycodes {
  BASE = SAFE_RANGE,
  X_LOCK,
  L_NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_GRV,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CT_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CT_MINS,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   SH_TAB,  CLN_NAV, AL_Q,    KC_J,    KC_K,    KC_X,    KC_LGUI,          KC_RGUI, KC_B,    KC_M,    KC_W,    AL_V,    Z_NAV,   SH_BSP,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_APP,  KC_LGUI, LW_ENT,                    LW_SPC,  KC_RGUI, FN_MNU
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘

  ),

  // Symbols
  [_SYM] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK,                            KC_RABK, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, M_SHTAB, KC_TAB,  _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, OOOOOOO,                   OOOOOOO, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Navigation
  [_NAV] = LAYOUT(

//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  _______, _______, _______, KC_END,  _______,                            _______, _______, _______, _______, KC_HOME, KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______,                            _______, TD_VIMG, _______, KC_END,  KC_RGHT, KC_INS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            KC_PGDN, KC_LEFT, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, L_NAV,   KC_LCTL, KC_DOWN, KC_UP,   _______, _______,          _______, _______, _______, _______, KC_RCTL, L_NAV,   SH_DEL,
//└────────┴oooooooo┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴oooooooo┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘

  ),

  // Functions
  [_FUNC] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, M_LOK,   M_CAD,   M_CSE,   _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, RESET,   _______, _______, _______, _______, _______,          _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, _______, OOOOOOO
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};

static bool nav_lock = false;

bool process_record_user(uint16_t current_keycode, keyrecord_t *record) {
    return vim_windows_movement(current_keycode, record)
        && dual_purpose_volume_keys(current_keycode, record)
        && m_layer_lock(current_keycode, record, &nav_lock, L_NAV, _NAV)
        && true;
}

void SCLN_NAV_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_layer_lock_finished(state, KC_SCLN, _NAV);
}

void ZMO_NAV_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_layer_lock_finished(state, KC_Z, _NAV);
}

void nav_lock_reset(qk_tap_dance_state_t *state, void *user_data) {
    td_layer_lock_reset(state, nav_lock, _NAV);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  // act (sort of) like G in vim: single tap (instead of shift) for END, double
  // tap for HOME. This assumes that systems will interpret C+HOME as "start of file"
  [TD_VIM_G] = ACTION_TAP_DANCE_DOUBLE(C(KC_END), C(KC_HOME)),
  // set up Mod-Taps and layer locks 
  [TD_ZMO_NAV] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ZMO_NAV_finished, nav_lock_reset, 100),
  [TD_SCLNMO_NAV] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, SCLN_NAV_finished, nav_lock_reset, 100)
};

