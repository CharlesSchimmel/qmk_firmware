#include QMK_KEYBOARD_H
#include "elpfen.h"

// Required to expand ___Dvorak___ macros correctly
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

enum custom_keycodes {
  BASE = ELPFEN_SAFE_RANGE,
  VI_U,
  VI_D,
  VI_R,
  VI_P,
  VI_Y,
  VI_W,
  VI_B
};

enum tap_dances {
  TD_VIM_G = 0,
  TD_VI_V
};

#define VI_G TD(TD_VIM_G)
#define VI_V TD(TD_VI_V)
#define Z_NAV TD(TD_ZMO_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,                                      _____________Dvorak_2Up_Core_______________,                                     KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                                                _____________Dvorak_1Up_Sides______________,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                                                _____________Dvorak_Home_Sides_____________,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _____________Dvorak_1Dn_Sides_L____________,     MO_ADJ,           MO_ADJ,      _____________Dvorak_1Dn_Sides_R____________,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                ___________Base_Bottom_Center_6k___________
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Symbols
  [_SYM] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                                                _____________SYM_2U_Sides_12k______________,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,                                     _____________SYM_1U_Core_10k_______________,                                     KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,                                     _____________SYM_Home_Core_10k_____________,                                     _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, KC_LALT, M_SHTAB, KC_TAB,  _______, _______,          _______, _______,  TG_FNC, _______, _______, _______, SH_DEL,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, OOOOOOO,                   OOOOOOO, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Navigation
  [_NAV] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  _______, _______, _______, KC_END,  _______,                            _______, _______, _______, _______, KC_HOME, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, _______,  VI_P,    VI_Y,                              _______,   VI_G,  _______,  VI_R,   KC_RGHT, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, _______, _______,  VI_U,   _______,                             VI_D,   KC_LEFT, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  L_NAV,  KC_LCTL, KC_DOWN,  KC_UP,  _______, _______,          _______,  VI_B,   TG_MSE,   VI_W,    VI_V,    L_NAV,  _______,
//└────────┴oooooooo┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴oooooooo┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /* Functions
   * Volume/Media/Brightness on <>? which sorta point the right directions
   * M_LOK: Win-L on L key for mnemonic "Lock"
   * M_CAD: Ctl-Alt-Delete on U for "Unlock"
   * KC_SLEEP: on S key for "sleep"
   * M_CSE: Ctl-Sh-Esc on usually Escape
   * RESET: Reset to bootloader, on Q for "Quit"
   * KC_PSCR: PrintScr on G for "Grab"
   */
  [_FNC] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    M_CSE,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,                            _______, KC_PSCR, _______, _______,  M_LOK,  _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______,                             M_CAD,  _______, _______, _______, KC_SLEP, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, RESET,   _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  OOOOOOO, _______, _______,                   _______, _______, OOOOOOO
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Mouse Control
  [_MOUSE] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, OOOOOOO, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // New Symbol Layout
  /* [_NEWSYM] = LAYOUT( */
/* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*  _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                              _______, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC,│ KC_BSLS, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*  _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_EQL,  KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_MINS, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*  _______, _______, _______, M_SHTAB, KC_TAB,  _______, _______,          _______,   NAV,     FNC,   _______, _______, _______, SH_DEL, */
/* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                 _______, _______, OOOOOOO,                   OOOOOOO, _______, _______ */
/* //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* ), */

  // GUI & Other Functions
  [_ADJ] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  GUI_1,   GUI_2,   GUI_3,   GUI_4,   GUI_5,                              GUI_6,   GUI_7,   GUI_8,   GUI_9,  _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, XXXXXXX, KC_LALT, M_SHTAB,  KC_TAB, _______, OOOOOOO,          OOOOOOO, _______, _______, KC_RCTL, KC_RALT, XXXXXXX, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, OOOOOOO,                   OOOOOOO, _______, _______
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};


layer_state_t layer_state_set_user(layer_state_t current_state) {
    current_state = update_tri_layer_state(state, _SYM, _NAV, _ADJ);
    return switchboard(current_state);
}

/* ~~~~~~~~~ Pseudo-Vi ~~~~~~~~~~
 * Just some macros to mimic the most useful vim keys
 */
static bool visual_mode = false;
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

// ~~~~ Keypress Processing ~~~~~
bool process_record_user(uint16_t current_keycode, keyrecord_t *record) {
    return pseudo_twm(current_keycode, record)
        && multi_purpose_volume_keys(current_keycode, record)
        && layer_lock(current_keycode, record)
        && vi_keys(current_keycode, record)
        && true;
}

// ~~~~~~~~~ TapDances ~~~~~~~~~~
static td_tap_t td_tap_state = {
    .state = TD_NONE,
};


// This could maybe be replaced with a mod-tap overload
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
