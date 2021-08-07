#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "layer_helpers.h"
#include "keycodes.h"
#include "keymaps.h"

#ifdef TAP_DANCE_ENABLE
#include "td_helpers.h"
#endif

bool pseudo_twm(uint16_t, keyrecord_t*);
bool multi_purpose_volume_keys(uint16_t, keyrecord_t*);

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record);
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record);
bool layer_lock(uint16_t current_keycode, keyrecord_t *record);
layer_state_t switchboard(layer_state_t current_state);
