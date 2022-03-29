#include "layer_helpers.h"
#include <stdbool.h>

bool was_layer_turned_off(layer_state_t previous, layer_state_t current, uint16_t layer) {
  if (previous == current) return false;

  return (IS_LAYER_ON_STATE(previous, layer)) && (IS_LAYER_OFF_STATE(current, layer));
}

// modified from tmk_core/common/action_layer.c
layer_state_t layer_on_state(layer_state_t layer_state, uint8_t layer) {
    return layer_state | (1UL << layer);
}

// pulled from tmk_core/common/action_layer.c
layer_state_t layer_off_state(layer_state_t layer_state, uint8_t layer) {
    return layer_state & ~(1UL << layer);
}

