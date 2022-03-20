#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "layer_helpers.h"
#include "keycodes.h"
#include "keymaps.h"
#include "vimmish.h"
#include "caps_word.h"

#ifdef TAP_DANCE_ENABLE
#include "tap_dances.h"
#include "td_helpers.h"
#endif

#define WITH_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
#define WITH_CTRL ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
#define WITH_GUI ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)

bool pseudo_twm(uint16_t, keyrecord_t*);
bool multi_purpose_volume_keys(uint16_t, keyrecord_t*);

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record);
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record);
bool layer_lock(uint16_t current_keycode, keyrecord_t *record);
layer_state_t switchboard(layer_state_t current_state);
layer_state_t switchboard_state(
        layer_state_t previous_state,
        layer_state_t current_state);
layer_state_t lenient_update_tri_layer_state(
        layer_state_t state,
        uint8_t layer1,
        uint8_t layer2,
        uint8_t layer3);
bool layer_sticky_mods(
        uint16_t current_keycode,
        keyrecord_t *record,
        layer_state_t layers);
bool clear_mods_after_adj
    ( uint16_t keycode
    , keyrecord_t *record
    );
