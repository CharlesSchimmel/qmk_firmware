#pragma once
#include QMK_KEYBOARD_H

layer_state_t switchboard(layer_state_t current_state);
layer_state_t switchboard_state
    ( layer_state_t previous_state
    , layer_state_t current_state
    );

