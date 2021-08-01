#include "quantum.h"
#include "action.h"
#include "elpfen.h"


bool dual_purpose_volume_keys(uint16_t keycode, keyrecord_t *record) {
  // ignore keyup
  if (!record->event.pressed) return true;

  // use the VOL keys as media keys as well
  if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
    switch(keycode) {
      case KC_VOLD :
        SEND_STRING(SS_TAP(X_MEDIA_PREV_TRACK));
        return false;
      case KC_VOLU :
        SEND_STRING(SS_TAP(X_MEDIA_NEXT_TRACK));
        return false;
      case KC_MUTE :
        SEND_STRING(SS_TAP(X_MEDIA_PLAY_PAUSE));
        return false;
    }
  }
  return true;
}


bool vim_windows_movement(uint16_t keycode, keyrecord_t *record) {
  // ignore keyup
  if (!record->event.pressed) return true;

  // move and close windows in Windows using vim keys (WIN+HJKL)
  if (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI)) {
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
        send_alt_f4();
        return false;

      case KC_C :
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
          send_alt_f4();
          return false;
        }
    }
  }
  return true;
}

void send_alt_f4(void) {
  SEND_STRING(SS_DOWN(X_LALT));
  SEND_STRING(SS_TAP(X_F4));
  SEND_STRING(SS_UP(X_LALT));
}


