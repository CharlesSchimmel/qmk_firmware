#include "elpfen.h"
#include "quantum.h"
#include "action.h"


bool dual_purpose_volume_keys(uint16_t keycode) {
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


bool vim_windows_movement(uint16_t keycode) {
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
        if (getmods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
          send_alt_f4();
          return false;
    }
  }
  return true;
}

void send_alt_f4() {
  SEND_STRING(SS_DOWN(X_LALT));
  SEND_STRING(SS_TAP(X_F4));
  SEND_STRING(SS_UP(X_LALT));
}
