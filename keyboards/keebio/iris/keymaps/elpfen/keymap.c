#include QMK_KEYBOARD_H
#include "elpfen.h"

// Required to expand ___Dvorak___ macros correctly
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

/* enum layers { */
/*     aoeu = ELPFEN_LAYERS_END */
/* }; */

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

#define MO_NAV MO(_NAV)

enum tap_dances {
  TD_VIM_G = 0,
};

#define VI_G TD(TD_VIM_G)
#define VI_V CTL_T(KC_RSFT)
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
        _____________Dvorak_1Dn_Sides_L____________,     MO_NAV,           MO_NAV,      _____________Dvorak_1Dn_Sides_R____________,
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

// using multiple layers means that the mods will stay on so long as any of
// those layers is activated. May or may not be desired.
void unregister_mods_on_layer_off(
        layer_state_t previous_state,
        layer_state_t current_state,
        layer_state_t layers) {
    if (was_layer_turned_off(previous_state, current_state, layers)) {
        clear_mods();
    }
}


layer_state_t layer_state_set_user(layer_state_t current_state) {
    static layer_state_t previous_state;

    current_state = update_tri_layer_state(current_state, _SYM, _NAV, _ADJ);

    unregister_mods_on_layer_off(previous_state, current_state, _ADJ | _SYM);

    current_state = switchboard_state(previous_state, current_state);
    previous_state = current_state;

    return current_state;
}

/* If a mod is pressed in this layer, keep it on until the layer is deactivated.
 * 
 * I think this could be done more generally, but idk
 */
bool layer_sticky_mods(uint16_t current_keycode, keyrecord_t *record, layer_state_t layers) {
    if (IS_LAYER_OFF(layers)) return true;
    // ignore keydown; only keyup behavior will be changed
    if (record->event.pressed) return true;

    switch (current_keycode) {
        case CT_ESC:
        case CT_MINS:
        case SH_TAB:
        case SH_DEL:
        case SH_BSP:
        case AL_V:
        case AL_Q:
            // ignore keyup when key was held. Taps should still be processed
            if (record->event.time > TAPPING_TERM) {
                return false;
            } else {
                return true;
            }
        case KC_LALT:
        case KC_RALT:
        case KC_RCTL:
            return false;
        default:
            return true;
    }
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

        /* Ignore alternating keyups and keydowns for KC_RSFT to toggle it
         * on and off. There's probably a way to do this more generally by
         * loading all of the mod keys into a byte, similar to how
         * one-shot-mods does it. Maybe I just use real_mods as my toggling
         * var?
         */
        case VI_V: // CTL_T(KC_RSFT)

            // let the hold (Ctl) be processed as usual
            if (record->event.time > TAPPING_TERM) return true;

            /* visual_mode needs to alternate at half the rate of event.pressed
             * this is sort of like scanning a stream with a XOR:
             * scanl xor False . take 10 . cycle $ [True, False]
             * v_m  e.p  ==
             * f  ^  t    t
             * t  ^  f    t
             * t  ^  t    f
             * f  ^  f    f
             *
             * this could also be achieved with:
             * if (record->event.pressed) visual_mode = !visual_mode;
             * but that's less fun
             */

            visual_mode ^= record->event.pressed;

            // v_m   e.p   ===
            // t      t     t
            // t      f     f
            // f      t     f
            // f      f     t
            //
            // mb   e.p   ===  mb
            //                 f
            // f     t     t   t
            // t     f     f   t
            // t     t     f   t
            // t     f     t   f

            // results in:
            // event.pressed: 10101010101
            // visual_mode  : 11001100110
            // return       : 10011001100
            return visual_mode == record->event.pressed;

        default:
            return true;
    }
    return true;
}

// ~~~~ Keypress Processing ~~~~~
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return pseudo_twm(keycode, record)
        && multi_purpose_volume_keys(keycode, record)
        && layer_lock(keycode, record)
        && vi_keys(keycode, record)
        && layer_sticky_mods(keycode, record, _ADJ | _SYM)
        && true;
}

// ~~~~~~~~~ TapDances ~~~~~~~~~~
static td_tap_t td_tap_state = {
    .state = TD_NONE,
};


qk_tap_dance_action_t tap_dance_actions[] = {
  // act (sort of) like G in vim: single tap (instead of shift) for END, double
  // tap for HOME. This assumes that systems will interpret C+HOME as "start of file"
  [TD_VIM_G] = ACTION_TAP_DANCE_DOUBLE(C(KC_END), C(KC_HOME))
};
