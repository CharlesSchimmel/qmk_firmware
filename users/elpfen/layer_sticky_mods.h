#pragma once
#include QMK_KEYBOARD_H

bool layer_sticky_mods
    ( uint16_t current_keycode
    , keyrecord_t *record
    , layer_state_t layers
    );

void layer_sticky_mods_state_hook
    ( layer_state_t previous_state
    , layer_state_t current_state
    , layer_state_t layer
    );

