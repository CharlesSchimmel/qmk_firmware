#include "switchboard.h"
#include "keycodes.h"
#include "layer_helpers.h"

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
 * Note: this requires that the child layers are higher than the parent
 * layers.
 */
layer_state_t switchboard(layer_state_t current_state) {
    static layer_state_t previous_state;
    current_state = switchboard_state(previous_state, current_state);
    previous_state = current_state;
    return current_state;
}

layer_state_t switchboard_state(layer_state_t previous_state, layer_state_t current_state) {
    if (was_layer_turned_off(previous_state, current_state, _NAV)) {
        current_state = layer_off_state(current_state, _MOUSE);
    }

    if (was_layer_turned_off(previous_state, current_state, _SYM)) {
        current_state = layer_off_state(current_state, _MCR);
        current_state = layer_off_state(current_state, _ADJ);
    }
    return current_state;
}

