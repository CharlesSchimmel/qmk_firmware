#include "layer_sticky_mods.h"
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

// the other half of layer_sticky_mods if not using an tri-layer
// should not be needed with the layer_state_set_user hook
bool clear_mods_after_adj(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) return true;
    if (keycode == AD_ENT || keycode == AD_SPC) {
        clear_mods();
    }
    return true;
}

