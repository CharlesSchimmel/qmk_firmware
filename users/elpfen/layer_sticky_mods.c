#include "layer_sticky_mods.h"
#include "layer_helpers.h"
#include "keycodes.h"

/* Layer-Sticky Mods: If a mod is pressed in this layer, keep it on until the
 * layer is deactivated. Simply intercept and ignore keyup for those modifiers
 * and call clear_mods when the layer turns off.
 *
 * I think this could be done more generally by checking the mod bits, but idk.
 */
bool layer_sticky_mods
    ( uint16_t current_keycode
    , keyrecord_t *record
    , layer_state_t layers
    ) {
    if (IS_LAYER_OFF(layers)) return true;
    if (record->event.pressed) return true;

    switch (current_keycode) {
        case KC_LALT:
        case KC_RALT:
        case KC_LCTL:
        case KC_RCTL:
        case KC_LSFT:
        case KC_RSFT:
            return false;
        default:
            return true;
    }
}

// Clear layer-sticky mods: using multiple layers means that the mods will stay
// on so long as any of those layers is activated. May or may not be desired.
void layer_sticky_mods_state_hook
    ( layer_state_t previous_state
    , layer_state_t current_state
    , layer_state_t layer
    ) {
    if (was_layer_turned_off(previous_state, current_state, layer)) {
        clear_mods();
    }
}
