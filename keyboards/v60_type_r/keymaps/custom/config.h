/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#ifdef V60_POLESTAR
#undef V60_POLESTAR
#endif

// Have to hold space (or whatever MO(<layer>) key for 200ms before shifting
#define TAPPING_TERM 200

// Always tap if another key wasn't pressed. Feels like lag but get used to it.
// #define RETRO_TAPPING

// This makes it easier for fast typists to use dual-function keys. Without this, if you let go of a held key inside the tapping term, it won't register.
#define PERMISSIVE_HOLD

// For KC_GESC - ignore grave escape when those modifiers pressed.
#define GRAVE_ESC_ALT_OVERRIDE
#define GRAVE_ESC_CTRL_OVERRIDE
#define GRAVE_ESC_GUI_OVERRIDE

#endif