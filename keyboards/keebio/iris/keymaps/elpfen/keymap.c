/* Notes:
 * Pressing both thumb keys on left thumb sends only upper key,
 * so true "adjust" layer doesn't work.
 */
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3
// #define _GAME 4
// #define _GAM1 5
#define _ADJUST 16

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Mod Taps
#define AL_ENT  RALT_T(KC_ENT)
#define AL_TAB  ALT_T(KC_TAB)
#define AL_QUOT RALT_T(KC_QUOT)
#define AL_MINS RALT_T(KC_MINS)

#define CT_ESC  CTL_T(KC_ESC)
#define CT_ENT  RCTL_T(KC_ENT)
#define CT_BSLS RCTL_T(KC_BSLS)
#define CT_SLSH CTL_T(KC_SLSH)

#define SH_BSP  MT(MOD_RSFT, KC_BSPC)
#define SH_DEL  MT(MOD_RSFT, KC_DEL)
#define SH_TAB  MT(MOD_LSFT, KC_TAB)
#define SH_ENT  MT(MOD_LSFT, KC_ENT)

// Layer Taps
#define LW_SPC  LT(_LOWER, KC_SPC)
#define LW_ENT  LT(_LOWER, KC_ENT)
#define RS_ENT  LT(_RAISE, KC_ENT)
#define RS_SCLN LT(_RAISE, KC_SCLN)
#define RS_SLSH LT(_RAISE, KC_SLSH)
#define RS_Z    LT(_RAISE, KC_Z)
#define FN_MNU  LT(_FUNC, KC_MENU)

/*
#define DF_GAME DF(_GAME)
#define DF_BASE DF(_BASE)
#define GM_Z    LT(_GAM1, KC_Z)
*/

// Mouse Aliases
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_UP KC_MS_UP
#define MS_WDWN KC_MS_WH_DOWN
#define MS_WUP KC_MS_WH_UP

// Quick Macros
#define M_LOK LGUI(KC_L)
#define M_CAD LCA(KC_DEL)
#define M_CSE LCTL(LSFT(KC_ESC))
#define M_PST LSFT(KC_INS)

// Tap Dance
enum {
  TD_ALTAB = 0
};

// "This key is pressed for this layer"
#define OOOOOOO KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
                              /*
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   AL_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CT_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, AL_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   SH_TAB,  RS_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOWER,            KC_RGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  RS_SLSH,  SH_BSP,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_RCTL, KC_LGUI, LW_ENT,                    LW_SPC,  KC_RGUI, FN_MNU
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
                              */

// DVORAK

//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   AL_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    CT_SLSH,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CT_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    AL_MINS,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   SH_TAB,  RS_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    RAISE,            KC_RGUI, KC_B,    KC_M,    KC_W,    KC_V,    RS_Z,    SH_BSP,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_RCTL, KC_LGUI, LW_ENT,                    LW_SPC,  KC_RGUI, FN_MNU
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘

  ),

  // Symbols
  [_LOWER] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
// QWERTY
// _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______,
// DVORAK
   _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK,                            KC_RABK, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, AL_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, OOOOOOO,                   OOOOOOO, _______, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Navigation
  [_RAISE] = LAYOUT(

/*
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  _______, _______, _______, KC_END,  _______,                            _______, _______, _______, KC_HOME, _______, KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  M_PST,   KC_INS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, OOOOOOO, KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, OOOOOOO, DF_GAME, M_PST,   _______, _______, _______,          _______, _______, _______, _______, _______, OOOOOOO, SH_DEL,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘

*/
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  _______, _______, _______, KC_END,  _______,                            _______, _______, _______, KC_HOME, _______, KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RGHT, KC_INS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            _______, KC_LEFT, _______, _______, OOOOOOO, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, OOOOOOO, _______, KC_DOWN, KC_UP,   _______, _______,          _______, _______, _______, _______, _______, OOOOOOO, SH_DEL,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘

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
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /*
  [_GAME] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   AL_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CT_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, AL_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSFT, GM_Z,    KC_X,    KC_C,    KC_V,    KC_B,   MO(_GAM1),         KC_RGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  RS_SLSH,  SH_BSP,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_RCTL, KC_LGUI, KC_SPC,                    LW_ENT,  KC_RGUI, FN_MNU
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_GAM1] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_F5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   AL_TAB,  KC_Q,    KC_W,    KC_I,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CT_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CT_ESC,  KC_A,    KC_S,    KC_D,    KC_J,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, AL_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSFT, OOOOOOO, KC_X,    KC_C,    KC_M,    KC_B,    OOOOOOO,          KC_RGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  RS_SLSH,  SH_BSP,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_RCTL, KC_LGUI, KC_SPC,                    LW_ENT,  KC_RGUI, FN_MNU
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
  */
};

bool lower_press = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // if enter or space is pressed before lower, ignore it when lower is pressed
  // delay the keycode sending until keyup to check if lower was pressed during that time
  /* switch (keycode) { */
  /*   case LOWER: */
  /*     lower_press = record->event.pressed; */
  /*     if (lower_press) { layer_on(_LOWER); } */
  /*     else { layer_off(_LOWER); } */
  /*     return false; // true or false for macros? */
  /*   case KC_ENT: */
  /*   case KC_SPC: */
  /*     return !(record->event.pressed) && !lower_press; */
  /* } */

  // on keydown
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
          return true; break; // want W-Q to still go through for twm setup
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

/* void td_atab_fn(qk_tap_dance_state_t *state, void *user_data) { */
/*   if (state-> count == 1) { */
/*     SEND_STRING(SS_DOWN(X_LALT)); */
/*     SEND_STRING(SS_TAP(X_TAB)); */
/*   } else { */
/*     SEND_STRING(SS_TAP(X_TAB)); */
/*   } */
/* } */

/* void td_atab_done_fn(qk_tap_dance_state_t *state, void *user_data) { */
/*   SEND_STRING(SS_UP(X_LALT)); */
/* } */

/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*   [TD_ALTAB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(td_atab_fn, td_atab_done_fn, NULL, 300) */
/* }; */

