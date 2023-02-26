#pragma once
#include QMK_KEYBOARD_H
#include <stdbool.h>

enum combo_events {
#ifdef MOUSE_ENABLE
  CMA_DOT_MS1,
  DOT_P_MS2,
  CMA_P_MS3,
#endif
  QT_CMA_TAB,
  F12_F2_F1,
  F9_F10_F11,
  COMBO_LENGTH
};

uint16_t COMBO_LEN; // remove the COMBO_COUNT define and use this instead!

#ifdef MOUSE_ENABLE
const uint16_t PROGMEM comma_dot_mouse1[];
const uint16_t PROGMEM dot_p_mouse2[];
const uint16_t PROGMEM comma_p_mouse3[];
#endif

const uint16_t PROGMEM quot_comma_tab[];
const uint16_t PROGMEM f12_f2_f1[];
const uint16_t PROGMEM f9_f10_f11[];

combo_t key_combos[];

__attribute__((weak)) void process_combo_event(uint16_t combo_index, bool pressed);
