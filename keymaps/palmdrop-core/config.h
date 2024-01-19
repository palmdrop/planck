/* Copyright 2015-2021 Jack Humbert
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

#pragma once

// Custom settings
#define DISABLE_LAYER_LED // Disables layer indicator leds

// Standard settings
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_ALPHA

#define TAPPING_TERM 170 
#define QUICK_TAP_TERM 0
#define DEBOUNCE 10
#define COMBO_TERM 50
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

// Make home row mods usable
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

// Enables configuring behavior of dual function layer keys.
// Lower and raise (and possibly other layer keys) have dual functions
// However, when rolling to one of these layers, I need to prioritize the "hold" action
// to avoid accidentally triggering the tap action.
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Enables stopping macro recording by tapping layer keys for layer used to access macro record keys
#define DYNAMIC_MACRO_USER_CALL

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_INTERVAL 20

#define MOUSEWHEEL_INTERVAL 100
#define MOUSEWHEEL_MAX_SPEED 8
#define MOUSEWHEEL_DELAY 400
#define MOUSEWHEEL_TIME_TO_MAX 40

// Special features
#define LAYER_LOCK_IDLE_TIMEOUT 10000 // Disable layer locks after 10s of idle time

// From default
#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
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
