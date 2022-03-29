#include "combos.h"
#include "keycodes.h"

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

#ifdef MOUSE_ENABLE
const uint16_t PROGMEM comma_dot_mouse1[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM dot_p_mouse2[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM comma_p_mouse3[] = {KC_COMMA, KC_P, COMBO_END};
#endif

combo_t key_combos[] = {
#ifdef MOUSE_ENABLE
  [CMA_DOT_MS1] = COMBO(comma_dot_mouse1, MS_BTN1),
  [DOT_P_MS2] = COMBO(dot_p_mouse2, MS_BTN2),
  [CMA_P_MS3] = COMBO(comma_p_mouse3, MS_BTN3)
#endif
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

__attribute__((weak)) void process_combo_event(uint16_t combo_index, bool pressed) {
}
