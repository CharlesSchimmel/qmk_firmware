/* Notes:
 * Quote as Control mod-tap?
 * Function layer on upper thumbs
 * Lsft mod-tap as enter?
 * One shot layers on upper thumbs
 * Tap Dance LSft for Enter or Tab?
 */
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3
#define _ADJUST 16

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MD_UP,
  MD_DWN,
  MD_ALT
};

// Mod Taps
#define AL_ENT  RALT_T(KC_ENT)
#define AL_TAB  ALT_T(KC_TAB)
#define AL_QUOT RALT_T(KC_QUOT)
#define AL_3    ALT_T(KC_3)
#define AL_8    RALT_T(KC_8)

#define CT_ESC  CTL_T(KC_ESC)
#define CT_ENT  RCTL_T(KC_ENT)
#define CT_SLSH CTL_T(KC_SLSH)
#define CT_2    CTL_T(KC_2)
#define CT_9    RCTL_T(KC_9)

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

// "This key is pressed for this layer"
#define OOOOOOO KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GESC, KC_1,    CT_2,    AL_3,    KC_4,    KC_5,                               KC_6,    KC_7,    AL_8,    CT_9,    KC_0,    KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   AL_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CT_ENT,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    RS_SCLN, AL_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   SH_ENT,  RS_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RAISE,            LOWER,   KC_N,    KC_M,    KC_COMM, KC_DOT,  RS_SLSH, SH_BSP,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_RCTL, KC_LGUI, LW_ENT,                    LW_SPC,  KC_RGUI,  KC_RALT
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
                              /*
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   AL_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    CT_SLSH,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CT_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    AL_ENT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   SH_TAB,  RS_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    RAISE,            LOWER,   KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SH_BSP,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_RCTL, KC_LGUI, RS_ENT,                    LW_SPC,  FN_MNU,  KC_RALT
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
                              */
  ),

  // Symbols
  [_LOWER] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_LABK,                            KC_RABK, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, OOOOOOO,                   OOOOOOO, _______, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Navigation
  [_RAISE] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, _______, _______, _______, KC_END,  _______,                            _______, _______, _______, KC_HOME, _______, KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_INS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, OOOOOOO, KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, OOOOOOO, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, OOOOOOO, SH_DEL,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
/*
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, _______, _______, _______, KC_END,  _______,                            _______, _______, _______, KC_HOME, _______, KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RGHT, KC_INS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            _______, KC_LEFT, _______, _______, OOOOOOO, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, OOOOOOO, _______, KC_DOWN, KC_UP,   _______, _______,          _______, _______, _______, _______, _______, OOOOOOO, SH_DEL,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
*/
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
   _______, RESET,   _______, _______, _______, _______, _______,          _______, _______, _______, MD_DWN,  MD_UP,   MD_ALT,  _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, OOOOOOO, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // no mods
  switch (keycode) {

    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
      }
      return false; break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false; break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false; break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false; break;
  }

  // on keydown
  if (record->event.pressed) {

    if ( get_mods() & MOD_BIT(KC_LGUI) ) {
      switch(keycode) {
        // windows/meta key activated macros for i3 parity :D
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
          return true; break; // want W-Q to still go through for i3 setup
      }
    } else if ( get_mods() & MOD_BIT(KC_LSFT) ) {
      switch(keycode) {
        case MD_UP :
          tap_code(KC_MNXT);
          return false; break;

        case MD_DWN :
          tap_code(KC_MPRV);
          return false; break;

        case MD_ALT :
          tap_code(KC_MPLY);
          return false; break;
      }
    }
   // on keyup
  } else {
  }
  return true;
}
