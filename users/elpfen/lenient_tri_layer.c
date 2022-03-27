#include "lenient_tri_layer.h"

/* Lenient Adjust: Turn on the third layer if both RAISE and LOWER are on (like
 * update_tri_layer_state), but only turn off the third layer when _both_
 * parent layers are turned off.
 */
layer_state_t lenient_update_tri_layer_state
    ( layer_state_t state
    , uint8_t layer1
    , uint8_t layer2
    , uint8_t layer3
    ) {
    layer_state_t mask12 = (1UL << layer1) | (1UL << layer2);
    layer_state_t mask3  = 1UL << layer3;

    bool both_on = (state & mask12) == mask12;
    bool both_off = (state & mask12) == 0;

    if (both_on)  return state | mask3;
    if (both_off) return state & ~mask3;

    return state;
}

