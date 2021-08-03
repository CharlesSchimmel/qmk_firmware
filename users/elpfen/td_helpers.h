#pragma once
#include "quantum.h"

// This is all from the docs

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);
