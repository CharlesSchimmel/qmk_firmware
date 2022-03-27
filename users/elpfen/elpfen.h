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

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record);
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record);

bool pseudo_twm(uint16_t, keyrecord_t*);

bool multi_purpose_volume_keys(uint16_t, keyrecord_t*);

bool layer_lock(uint16_t current_keycode, keyrecord_t *record);

bool process_macros
    ( uint16_t keycode
    , keyrecord_t *record
    );
