#include "layer_helpers.h"
#include <stdbool.h>

bool was_layer_turned_off(layer_state_t previous, layer_state_t current, uint16_t layer) {
  if (previous == current) return false;

  uint16_t was_on = IS_LAYER_ON_STATE(previous, layer);
  uint16_t now_off = IS_LAYER_OFF_STATE(current, layer);
  return was_on && now_off;
}

// modified from tmk_core/common/action_layer.c
layer_state_t layer_on_state(layer_state_t layer_state, uint8_t layer) {
    return layer_state | (1UL << layer);
}

// pulled from tmk_core/common/action_layer.c
layer_state_t layer_off_state(layer_state_t layer_state, uint8_t layer) {
    return layer_state & ~(1UL << layer);
}

