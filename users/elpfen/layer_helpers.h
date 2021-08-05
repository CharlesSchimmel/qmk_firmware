#pragma once
#include QMK_KEYBOARD_H

bool was_layer_turned_off(layer_state_t previous, layer_state_t current, uint16_t layer);

layer_state_t layer_on_state(layer_state_t layer_state, uint8_t layer);

layer_state_t layer_off_state(layer_state_t layer_state, uint8_t layer);
