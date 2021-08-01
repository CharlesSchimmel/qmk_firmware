#pragma once
#include "quantum.h"

bool m_layer_lock(
        uint16_t current_keycode,
        keyrecord_t *record,
        bool *lock_flag,
        uint16_t target_keycode,
        uint16_t layer
        );

void td_layer_lock_finished(
        qk_tap_dance_state_t *state,
        uint16_t keycode,
        uint16_t layer
        );

void td_layer_lock_reset(
        qk_tap_dance_state_t *state,
        bool lock_flag,
        uint16_t layer
        );

