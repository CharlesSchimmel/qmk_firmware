#pragma once
#include "quantum.h"
#include <stdbool.h>

enum combo_events {
  CMA_DOT_MS1,
  DOT_P_MS2,
  CMA_P_MS3,
  COMBO_LENGTH
};

uint16_t COMBO_LEN; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM comma_dot_mouse1[];
const uint16_t PROGMEM dot_p_mouse2[];
const uint16_t PROGMEM comma_p_mouse3[];

combo_t key_combos[];

__attribute__((weak)) void process_combo_event(uint16_t combo_index, bool pressed);
