/* Notes:
 * Quote as Control mod-tap?
 * Function layer on upper thumbs
 * Lsft mod-tap as enter?
 */
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  M_LOK,
  M_CAD,
  MD_UP,
  MD_DWN,
  MD_ALT
};

// Mod Taps
#define AL_BSLS ALT_T(KC_BSLS)
#define AL_ENT  ALT_T(KC_ENT)
#define AL_TAB  RALT_T(KC_TAB)
#define AL_MNU  ALT_T(KC_MENU)

#define CT_BSLS RCTL_T(KC_BSLS)
#define CT_ENT  CTL_T(KC_ENT)
#define CT_ESC  CTL_T(KC_ESC)
#define CT_QUOT CTL_T(KC_QUOT)

#define SH_BSP  MT(MOD_RSFT, KC_BSPC)
#define SH_DEL  MT(MOD_RSFT, KC_DEL)
#define SH_SLSH MT(MOD_RSFT, KC_SLSH)
#define SH_TAB  MT(MOD_LSFT, KC_TAB)

// Layer Taps
#define LW_SPC LT(LOWER, KC_SPC)
#define RS_ENT LT(RAISE, KC_SPC)

// Mouse Aliases
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_UP KC_MS_UP
#define MS_WDWN KC_MS_WH_DOWN
#define MS_WUP KC_MS_WH_UP

#define _____ KC_TRNS
#define XXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     AL_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CT_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, AL_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SH_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSLS,          XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SH_BSP,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_RCTL, KC_LGUI, RS_ENT,                    LW_SPC,  AL_MNU,  KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_GRV,  KC_LBRC, KC_LPRN, KC_MINS, _______,                            _______, KC_EQL,  KC_RPRN, KC_RBRC, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   XXXXXXX, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, KC_END,  _______,                            _______, _______, _______, KC_HOME, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, MS_WUP,  MS_BTN1, MS_UP,   MS_BTN2, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_INS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, MS_WDWN, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, SH_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, XXXXXXX,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, MD_DWN,  MD_UP,   MD_ALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, XXXXXXX,                   XXXXXXX, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
    /*
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // no mods
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case M_LOK :
      SEND_STRING(SS_LGUI("l"));
      return false;
    case M_CAD :
      SEND_STRING(SS_DOWN(X_LCTRL));
      SEND_STRING(SS_DOWN(X_LALT));
      SEND_STRING(SS_TAP(X_DELETE));
      SEND_STRING(SS_UP(X_LALT));
      SEND_STRING(SS_UP(X_LCTRL));
      return false;
      break;
    /* case MD_UP : */
    /*   SEND_STRING(X_AUDIO_VOL_UP); */
    /*   return false; */
    /*   break; */
    /* case MD_DWN : */
    /*   SEND_STRING(X_AUDIO_VOL_DOWN); */
    /*   return false; */
    /*   break; */
    /* case MD_ALT : */
    /*   SEND_STRING(X_AUDIO_MUTE); */
    /*   return false; */
    /*   break; */
  }

  // windows/meta key activated macros for i3 parity :D
  if ( get_mods() & MOD_BIT(KC_LGUI) ) {
    switch(keycode) {
      case KC_H :
        SEND_STRING(SS_TAP(X_LEFT));
        return false;
      case KC_J :
        SEND_STRING(SS_TAP(X_DOWN));
        return false;
      case KC_K :
        SEND_STRING(SS_TAP(X_UP));
        return false;
      case KC_L :
        SEND_STRING(SS_TAP(X_RIGHT));
        return false;
      case KC_Q :
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_TAP(X_F4));
        SEND_STRING(SS_UP(X_LALT));
        return true; // want W-Q to still go through for i3 setup
        break;
    }
  } else if ( get_mods() & MOD_BIT(KC_LALT) ) {
    switch(keycode) {
      case KC_ESC : // block Alt+Esc
      return false;
    }
  } 
  /* else if ( get_mods() & MOD_BIT(KC_LSFT) ) { */
  /*   switch(keycode) { */
  /*     case MD_UP : */
  /*       SEND_STRING(X_MEDIA_NEXT_TRACK); */
  /*       return false; */
  /*       break; */
  /*     case MD_DWN : */
  /*       SEND_STRING(X_MEDIA_PREV_TRACK); */
  /*       return false; */
  /*       break; */
  /*     case MD_ALT : */
  /*       SEND_STRING(X_MEDIA_PLAY_PAUSE); */
  /*       return false; */
  /*       break; */
  /*   } */
  /* } */
  return true;
}
