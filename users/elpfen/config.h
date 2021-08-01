#pragma once

/* For Mod-Tap keys: Sets the time needed to hold mod-taps (MO(), MT()) before 
 * it will apply that modifier. The shorter this is, the more often it will 
 * erroneosly apply the modifier when you intended to tap. The longer this is, 
 * the more difficult it will be to quickly execute chords.
 *
 * ./docs/tap_hold.md > TAPPING_TERM
 */
#define TAPPING_TERM 150

/* For Mod-Tap keys (but not Layer-tap keys): If the second key in a chord is 
 * released after the modifier key is released, ignore it, even if it's inside 
 * the tapping term.  Results in fewer dropped taps, but more dropped chords. 
 * 
 * Sometimes when typing, fast typists will overlap the presses of multiple 
 * keys. Ex: "the" may be typed t_down, h_down, t_up, e_down, h_up, e_up.  
 * Without this, if 't' had a mod-tap on this it would be sent as `MOD-h .`.  
 * With this, it will be sent as "the".
 *
 * This will also affect PERMISSIVE_HOLD: The regular key has the modifier 
 * added if the first key is released first or if both keys are held longer 
 * than the TAPPING_TERM.
 *
 * ./docs/tap_hold.md > IGNORE_MOD_TAP_INTERRUPT
 */
// #define IGNORE_MOD_TAP_INTERRUPT

/* For Mod-Tap keys: If the MOD is pressed and released without another key 
 * having been pressed, send the TAP key. This has an odd effect of always 
 * waiting for keyup to send the TAP key, which feels laggy. Sometimes if you 
 * press a chord, the tap in the mod tap will register
 *
 * ./docs/tap_hold.md > RETRO_TAPPING
 */
// #define RETRO_TAPPING

/* If you tap another key while holding a Mod-Tap key it will always be sent as 
 * MOD+Key. This means that if the chord is executed within the TAPPING_TERM it 
 * will still be sent as MOD+Key. This makes it easier for fast typists to 
 * execute chords.
 *
 * ./docs/tap_hold.md > PERMISSIVE_HOLD
 */
#define PERMISSIVE_HOLD
