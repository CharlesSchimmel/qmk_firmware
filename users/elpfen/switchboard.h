#pragma once
#include QMK_KEYBOARD_H

layer_state_t switchboard(layer_state_t current_state);

layer_state_t switchboard_state
    ( layer_state_t previous_state
    , layer_state_t current_state
    , uint8_t parent_layer
    , uint8_t child_layers
    );

bool switchboard_adj(uint16_t keycode, keyrecord_t *record);
