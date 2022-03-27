#pragma once
#include QMK_KEYBOARD_H

bool layer_sticky_mods
    ( uint16_t current_keycode
    , keyrecord_t *record
    , layer_state_t layers
    );

bool clear_mods_after_adj
    ( uint16_t keycode
    , keyrecord_t *record
    );

