#include "combos.h"
#include "keycodes.h"
#include "tap_hold.h"

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

#ifdef MOUSE_ENABLE
const uint16_t PROGMEM comma_dot_mouse1[] = {KC_COMMA, M_DOT13, COMBO_END};
const uint16_t PROGMEM dot_p_mouse2[]     = {M_DOT13,  KC_P,    COMBO_END};
const uint16_t PROGMEM comma_p_mouse3[]   = {KC_COMMA, KC_P,    COMBO_END};
#endif

const uint16_t PROGMEM quot_comma_tab[] = {KC_QUOTE, KC_COMMA, COMBO_END};
const uint16_t PROGMEM f12_f2_f1[] = {KC_F12, KC_F2, COMBO_END};
const uint16_t PROGMEM f9_f10_f11[] = {KC_F9, KC_F10, COMBO_END};
const uint16_t PROGMEM ht_f12_f2_f1[] = {HT_1, HT_2, COMBO_END};
const uint16_t PROGMEM ht_f9_f10_f11[] = {HT_9, HT_0, COMBO_END};

combo_t key_combos[] = {
#ifdef MOUSE_ENABLE
  [CMA_DOT_MS1] = COMBO(comma_dot_mouse1, MS_BTN1),
  [DOT_P_MS2] = COMBO(dot_p_mouse2, MS_BTN2),
  [CMA_P_MS3] = COMBO(comma_p_mouse3, MS_BTN3),
#endif
  [QT_CMA_TAB] = COMBO(quot_comma_tab, KC_TAB),
  [F12_F2_F1] = COMBO(f12_f2_f1, KC_F1),
  [F9_F10_F11] = COMBO(f9_f10_f11, KC_F11),
  [HT_F12_F2_F1] = COMBO(ht_f12_f2_f1, KC_F1),
  [HT_F9_F10_F11] = COMBO(ht_f9_f10_f11, KC_F11)
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

__attribute__((weak)) void process_combo_event(uint16_t combo_index, bool pressed) {
}
