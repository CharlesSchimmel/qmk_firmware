#include "td_layer_lock.h"

bool m_layer_lock(uint16_t current_keycode, keyrecord_t *record, bool *lock_flag, uint16_t target_keycode, uint16_t layer) {
    if (current_keycode != target_keycode || !record->event.pressed) return true;

    if (*lock_flag) {
        layer_off(layer);
        *lock_flag = false;
    } else {
        *lock_flag = true;
    }

    return false;
}

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    td_state_t state;
    bool lock_state;
} td_tap_t;

// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .state = TD_NONE,
};

void td_layer_lock_finished(qk_tap_dance_state_t *state, uint16_t keycode, uint16_t layer) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(keycode);
            break;
        case TD_SINGLE_HOLD:
            layer_on(layer);
            break;
        default: break;
    }
}

void td_layer_lock_reset(qk_tap_dance_state_t *state, bool lock_flag, uint16_t layer) {
    if (ql_tap_state.state == TD_SINGLE_HOLD && !lock_flag) {
        layer_off(layer);
    }
    ql_tap_state.state = TD_NONE;
}

