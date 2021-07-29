/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #undef RGBLED_NUM
// #define RGBLIGHT_ANIMATIONS
// #define RGBLED_NUM 12
// #define RGBLIGHT_HUE_STEP 8
// #define RGBLIGHT_SAT_STEP 8
// #define RGBLIGHT_VAL_STEP 8

// Have to hold space (or whatever MO(<layer>) or MT() ) key for 200ms before shifting
#define TAPPING_TERM 150

// If the second key in a chord is pressed after the modifier key is released, ignore it, even if it's inside the tapping term
// Fewer dropped keypresses, but more dropped chords
// #define IGNORE_MOD_TAP_INTERRUPT

// Always tap if another key wasn't pressed. Feels like lag but get used to it.
// Sometimes if you press a chord, the tap in the mod tap will register
// #define RETRO_TAPPING

// This makes it easier for fast typists to use dual-function keys. Without this, if you let go of a held key inside the tapping term, it won't register.
#define PERMISSIVE_HOLD

// For KC_GESC - ignore grave escape when those modifiers pressed.
#define GRAVE_ESC_ALT_OVERRIDE
#define GRAVE_ESC_CTRL_OVERRIDE
#define GRAVE_ESC_GUI_OVERRIDE
