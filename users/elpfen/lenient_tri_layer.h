#pragma once
#include QMK_KEYBOARD_H

layer_state_t lenient_update_tri_layer_state
    ( layer_state_t state
    , uint8_t layer1
    , uint8_t layer2
    , uint8_t layer3
    );

