#pragma once
#include QMK_KEYBOARD_H

#define WITH_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
#define WITH_CTRL ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
#define WITH_ALT ((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT)
#define WITH_GUI ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)
