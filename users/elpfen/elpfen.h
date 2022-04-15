#pragma once
#include QMK_KEYBOARD_H

#include "caps_word.h"
#include "keycodes.h"
#include "keymaps.h"
#include "layer_helpers.h"
#include "layer_sticky_mods.h"
#include "lenient_tri_layer.h"
#include "switchboard.h"
#include "elpfen_util.h"
#include "vimmish.h"

#ifdef TAP_DANCE_ENABLE
#include "tap_dances.h"
#include "td_helpers.h"
#endif

#define ELPFEN_DEFAULT_PROREC process_macros(keycode, record) \
        && weird_taps(keycode, record)                        \
        && pseudo_twm(keycode, record)                        \
        && multi_purpose_volume_keys(keycode, record)         \
        && vimmish_keys(keycode, record)                      \
        && layer_lock(keycode, record)                        \
        && layer_sticky_mods(keycode, record, _ADJ)           \
        && switchboard_adj(keycode, record)                   \
        && process_caps_word(keycode, record)                 \

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record);
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record);

bool pseudo_twm(uint16_t, keyrecord_t*);

bool multi_purpose_volume_keys(uint16_t, keyrecord_t*);

bool layer_lock(uint16_t current_keycode, keyrecord_t *record);

bool process_macros
    ( uint16_t keycode
    , keyrecord_t *record
    );

bool weird_taps
    ( uint16_t keycode
    , keyrecord_t *record
    );

layer_state_t elpfen_default_layer_state_set(layer_state_t current_state);
