#include "keycodes.h"
#include "layer_helpers.h"

#include "switchboard.h"

/* Switchboard: For momentary/layer-tapped layers, make a "child" layer
 * dependent on its parent layer.
 *
 * Example: If _LOW is the active laer, then TG(_RAISE) is pressed, _RAISE
 * will stay active so long as _LOW is active. When _LOW is deactivated, so
 * will _RAISE.
 *
 * This is really useful as it lets one layer "switchboard" to many other
 * layers, but occupy only one activating switch. It's like a
 * Raise+Lower=Adjust but you only have to keep one key held.
 *
 * Switchboard layers are enabled by either adding a TG(<Child Layer>) to the
 * parent layer keymap, or intercepting the "mod" half of a mod-tap in
 * process_record_user
 *
 * Note: this requires that the child layers are higher than the parent
 * layers.
 *
 * TODO: Allow passing in a list of {parent, children} layers
 */
layer_state_t switchboard(layer_state_t current_state) {
    static layer_state_t previous_state;
    current_state = switchboard_state(previous_state, current_state, _NAV, _MOUSE)  
                  & switchboard_state(previous_state, current_state, _SYM, _MCR & _ADJ);
;
    previous_state = current_state;
    return current_state;
}

layer_state_t switchboard_state
    ( layer_state_t previous_state
    , layer_state_t current_state
    , uint8_t parent_layer
    , uint8_t child_layers
    ) {
    if (was_layer_turned_off(previous_state, current_state, parent_layer))
        current_state = layer_off_state(current_state, child_layers);
    return current_state;
}

// ignore keyup of ADJ mod-taps to switchboard them from SYM
bool switchboard_adj(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed || record->tap.count) return true; // ignore taps
    if (keycode == AD_ENT || keycode == AD_SPC) return false;    // intercept holds
    return true;
}

