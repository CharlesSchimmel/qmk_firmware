#include QMK_KEYBOARD_H
#include "elpfen.h"

enum layers {
    _BASE = 0,
    _SYM,
    _NAV,
    _FNC,
    _ADJ
};

enum tap_dances {
  TD_VIM_G = 0,
  TD_ZMO_NAV,
  TD_SCLNMO_NAV,
  TD_VI_V
};
#define VI_G TD(TD_VIM_G)
#define VI_V TD(TD_VI_V)
#define Z_NAV TD(TD_ZMO_NAV)
#define CLN_NAV TD(TD_SCLNMO_NAV)

enum custom_keycodes {
  BASE = SAFE_RANGE,
  SYM,
  NAV,
  FNC,
  ADJ,
  L_NAV,
  VI_U,
  VI_D,
  VI_R,
  VI_P,
  VI_Y,
  VI_W,
  VI_B,
};

#define MO_ADJ MO(_ADJ)
#define MO_NAV MO(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_GRV,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CT_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CT_MINS,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   SH_TAB,  CLN_NAV, AL_Q,    KC_J,    KC_K,    KC_X,    MO_NAV,           MO_NAV,  KC_B,    KC_M,    KC_W,    AL_V,    Z_NAV,   SH_BSP,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_APP,  KC_LGUI, LW_ENT,                    LW_SPC,  KC_RGUI, FN_MNU
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Symbols
  [_SYM] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK,                            KC_RABK, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______,   NAV,   _______, M_SHTAB, KC_TAB,  _______, _______,          _______,   NAV,     FNC,   _______, _______,   NAV,   SH_DEL,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, OOOOOOO,                   OOOOOOO, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Navigation
  [_NAV] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  _______, _______, _______, KC_END,  _______,                            _______, _______, _______, _______, KC_HOME, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, _______,  VI_P,    VI_Y,                              _______,   VI_G,  _______,  VI_R,   KC_RGHT,  M_PST,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, _______, _______,  VI_U,   _______,                             VI_D,   KC_LEFT, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  L_NAV,  KC_LCTL, KC_DOWN,  KC_UP,  _______, _______,          _______,  VI_B,   _______,   VI_W,    VI_V,  L_NAV,   _______,
//└────────┴oooooooo┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴oooooooo┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘

  ),

  // Functions
  [_FNC] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, RESET,    M_LOK,   M_CAD,   M_CSE,  _______, _______,          _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, _______, OOOOOOO
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Symbols
  [_NEWSYM] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                              _______, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_EQL,  KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_MINS,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______,   NAV,   _______, M_SHTAB, KC_TAB,  _______, _______,          _______,   NAV,     FNC,   _______, _______,   NAV,   SH_DEL,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, OOOOOOO,                   OOOOOOO, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Functions
  [_ADJ] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  GUI_1,   GUI_2,   GUI_3,   GUI_4,   GUI_5,                              GUI_6,   GUI_7,   GUI_8,   GUI_9,  _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______, OOOOOOO,          OOOOOOO, _______, _______, _______, _______, _______, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, OOOOOOO,                   OOOOOOO, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NAV, _ADJ);
}

static bool visual_mode = false;

/* If MO(LOW) is held, then FNC or NAV are presesd, FNC or NAV will be
 * activated so long as MO(LOW) is maintained.  This should act and feel like
 * only FNC or NAV are activated; _BASE should still be the lowest layer.
 */
bool switchboard(uint16_t current_keycode, keyrecord_t *record) {
    // ignore keyup
    if (!record->event.pressed) {
        switch (current_keycode) {
            case LW_SPC:
            case LW_ENT:
                layer_move(_BASE);
            default:
                return true;
        }
    }

    switch (current_keycode) {
        case FNC:
            layer_off(_SYM);
            layer_on(_FNC);
            return false;
        case NAV:
            layer_off(_SYM);
            layer_on(_NAV);
            return false;
        default:
            return true;
    }
}

bool vi_keys(uint16_t current_keycode, keyrecord_t *record) {
    // ignore keyup
    if (!record->event.pressed) return true;

    bool with_ctl = get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL);
    bool with_shift = get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT);

    switch(current_keycode) {
        case KC_ESC:
        case KC_LSFT:
        case KC_RSFT:
            visual_mode = false;
            return true;

        case VI_B:
            SEND_STRING(SS_DOWN(X_LCTL));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_UP(X_LCTL));
            return false;

        case VI_W:
            SEND_STRING(SS_DOWN(X_LCTL));
            SEND_STRING(SS_TAP(X_RIGHT));
            SEND_STRING(SS_UP(X_LCTL));
            return false;

        case VI_Y:
            SEND_STRING(SS_LCTL("c"));
            visual_mode = false;
            return false;

        case VI_P:
            if (!visual_mode && with_shift) {
                SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
            } else {
                SEND_STRING(SS_LCTL("v"));
            }
            return false;

        case VI_R:
            if (with_ctl) {
                SEND_STRING(SS_LCTL("y"));
            }
            return false;

        case VI_U:
            if (with_ctl) {
                SEND_STRING(SS_TAP(X_PGUP));
            } else {
                SEND_STRING(SS_LCTL("z"));
            }
            return false;

        case VI_D: 
            if (with_ctl) {
                SEND_STRING(SS_TAP(X_PGDOWN));
            } else {
                SEND_STRING(SS_LCTL("x"));
                visual_mode = false;
            }
            return false;

        default:
            return true;
    }
    return true;
}

static bool nav_lock = false;

bool process_record_user(uint16_t current_keycode, keyrecord_t *record) {
    return vim_windows_movement(current_keycode, record)
        && vi_keys(current_keycode, record)
        && dual_purpose_volume_keys(current_keycode, record)
        && m_layer_lock(current_keycode, record, &nav_lock, L_NAV, _NAV)
        && switchboard(current_keycode, record)
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

static td_tap_t td_tap_state = {
    .state = TD_NONE,
};


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

  // layer locks 
  [TD_ZMO_NAV] =
    ACTION_TAP_DANCE_FN_ADVANCED_TIME(
        NULL,
        ZMO_NAV_finished,
        nav_lock_reset,
        150
        ),
  [TD_SCLNMO_NAV] =
    ACTION_TAP_DANCE_FN_ADVANCED_TIME(
        NULL,
        SCLN_NAV_finished,
        nav_lock_reset,
        150
        )
};

