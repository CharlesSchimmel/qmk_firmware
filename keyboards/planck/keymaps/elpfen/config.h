#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

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
