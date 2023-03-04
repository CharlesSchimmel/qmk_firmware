#pragma once

/* This is the length of time (in milliseconds) that a mod-tap needs to be held
 * to be considered a hold and not a tap (other options not withstanding).
 *
 * Shorter intervals result in more taps being interpreted as holds, resulting
 * in more dropped taps. Good for keys that are held more often than tapped.
 *
 * Longer intervals result in more holds being interpreted as taps, resulting
 * in more dropped holds. Good for keys that are tapped more often than held.
 */
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

/* If the second key in a chord is released after the modifier key is released,
 * treat it as two taps instead, even if it's inside the tapping term.
 *
 * Fewer dropped keypresses, but more dropped chords. Good for keys that are
 * used in normal typing (ie, alpha-nums)
 */
#define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

/* Normally with a mod-tap, tapping then tapping and holding will repeat the
 * tap key. TAPPING_FORCE_HOLD turns that off, allowing the mod to be activated
 * shortly after using it as a tap. This is useful for keys that are used as
 * normal characters to allow for a quick transition from tapping to modding.
 */
#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

/* For mod-taps and layer-taps, always tap if another key wasn't pressed.
 *
 * This can prevent dropped taps for shorter TAPPING_TERM intervals, but feels
 * a little odd. If you sometimes shift into a layer and then change your mind,
 * you'll have to undo whatever tap was.
 */
// #define RETRO_TAPPING

/* If a chord is executed entirely within the tapping term, register it as a
 * chord (instead of ignoring the held key because it was released before the
 * tapping term elapsed.)
 *
 * This makes it easier for fast typists to use dual-function keys, but can
 * result in unintended chords 
 */
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define ONESHOT_TIMEOUT 1500  /* Time (in ms) before the one shot key is released, Default 5000 */

/* HOLD_ON_OTHER_KEY_PRESS chooses the hold action immediately when another key 
 * is tapped.
 */
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
