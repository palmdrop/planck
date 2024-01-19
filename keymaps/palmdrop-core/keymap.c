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


#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  // Basic layers
  _BASE,
  _LOWER,
  _RAISE,

  // Navigation
  _NAVIGATION,

  // Special
  _COMMAND,
  _ADJUST
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
  BACKLIT,
  EXT_PLV
};

// Layers
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define NAVESQ LT(_NAVIGATION, KC_ESC)

// Multi-key codes
#define CTLSFTI   LCTL(LSFT(KC_I))
#define CTLALTDEL LCTL(LSFT(KC_I))

// Combos
const uint16_t PROGMEM meta_combo[]      = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM escape_combo[]    = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
  COMBO(meta_combo, KC_LGUI),
  COMBO(escape_combo, KC_ESC),
  COMBO(backspace_combo, KC_BSPC)
};

// Tap dance
enum tap_dance_codes {
  TD_GG = 0
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_GG] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_HOME)
};

// Empty layer
/*
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_LAYER] = LAYOUT_planck_grid(
    _______,   _______,  _______,  _______,  _______, _______,   _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______,  _______,  _______,  _______, _______,   _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______,  _______,  _______,  _______, _______,   _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______,  _______,  _______,  _______, _______,   _______,  _______,  _______,  _______,  _______,  _______
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Bspc |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      | Gui  | Tab  |Lower |    Space    |Raise |Shift |      |  Tab | Enter|
  * `-----------------------------------------------------------------------------------'
  */
  [_BASE] = LAYOUT_planck_grid(
      KC_TAB,  KC_Q,    KC_W,         KC_E,           KC_R,         KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,         KC_P,            SE_ARNG,
      NAVESQ,  KC_A,    LALT_T(KC_S), LSFT_T(KC_D),   LCTL_T(KC_F), KC_G,    KC_H,    KC_J,    KC_K,     RSFT_T(KC_L), RCTL_T(SE_ODIA), SE_ADIA,
      KC_LSFT, KC_Z,    KC_X,         KC_C,           KC_V,         KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,       SE_MINS,         KC_BSPC,
      _______, _______, KC_LGUI,      LALT_T(KC_TAB), LOWER,        KC_SPC,  KC_SPC,  RAISE,   KC_RSFT,  ADJUST,       KC_TAB,          RSFT_T(KC_ENTER)
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |   ~  |   !  |   "  |   #  |   ¤  |   %  |   &  |   /  |   (  |   )  |   =  |  ?   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |   ´  |  `   |   '  |   (  |   )  |   $  |   \  |   {  |   }  |   ~  |   ^  |  *   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |  <   |   >  |   [  |   ]  |   |  |   @  |   \  |   ;  |   :  |   _  |  +   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_grid(
      SE_TILD, KC_EXLM, SE_DQUO, KC_HASH, SE_CURR, KC_PERC, SE_AMPR, SE_SLSH, SE_LPRN, SE_RPRN, SE_EQL,  SE_QUES,
      SE_ACUT, SE_GRV,  SE_QUOT, SE_LPRN, SE_RPRN, SE_DLR,  SE_BSLS, SE_LCBR, SE_RCBR, SE_TILD, SE_CIRC, SE_ASTR,
      KC_LSFT, SE_LABK, SE_RABK, SE_LBRC, SE_RBRC, SE_PIPE, SE_AT,   SE_BSLS, SE_SCLN, SE_COLN, SE_UNDS, SE_PLUS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RSFT_T(KC_ENTER)
  ),

  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Base |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   ]  |  .   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |  -   |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |   0  |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_grid(
      _______,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8, KC_9,    KC_0,    SE_PLUS,
      TO(_BASE), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5, KC_6,    KC_0,    KC_DOT,
      _______,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2, KC_3,    SE_MINS, _______,
      _______,   _______, _______, _______, _______, _______, _______, _______, KC_0, _______, _______, _______
  ),

  /* Navigation
  * ,-----------------------------------------------------------------------------------.
  * |      |      |C+Rght|      |S+Undo|      | Copy | Undo | Home |Enter |Paste | Bspc |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      | End  |      |Del/S | Ctrl |  GG  | Left | Down |  Up  |Right | WUp  |C+Bspc|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |Shift |      | Bspc | Bspc |      |C+Left|MLeft |MDown | MUp  |MRght |WDown |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      | Mouse btn 1 |Mbtn3 |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_NAVIGATION] = LAYOUT_planck_grid(
      _______,   _______,  LCTL(KC_RGHT),  _______,         LSFT(KC_UNDO),  _______,        KC_COPY,  KC_UNDO,  KC_HOME,  KC_ENT,   KC_PSTE,  KC_BSPC,
      _______,   KC_END,   _______,        LSFT_T(KC_DEL),  KC_LCTL,        TD(TD_GG),      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_WH_U,  RCTL(KC_BSPC),
      KC_LSFT,   _______,  KC_BSPC,        KC_BSPC,         _______,        LCTL(KC_LEFT),  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_WH_D,  _______,
      _______,   _______,  _______,        _______,         _______,        KC_BTN1,        KC_BTN1,  KC_BTN3,  _______,  _______,  _______,  _______
  ),

  /* Command
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |C+S+I |      |S+Ins |C+A+D |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Caps |      |SysRq |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |CpsWrd|      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_COMMAND] = LAYOUT_planck_grid(
      _______,   _______,  _______,  _______,  _______, _______,   _______,  _______,  CTLSFTI,  _______,  LSFT(KC_INS), CTLALTDEL,
      KC_CAPS,   _______,  KC_SYRQ,  _______,  _______, _______,   _______,  _______,  _______,  _______,  _______,      _______,
      _______,   _______,  _______,  CW_TOGG,  _______, _______,   _______,  _______,  _______,  _______,  _______,      _______,
      _______,   _______,  _______,  _______,  _______, _______,   _______,  _______,  _______,  _______,  _______,      _______
  ),

  /* Adjust
  * ,-----------------------------------------------------------------------------------.
  * |      |      |MPrev |MPlay |MNext |      |      | Bri- | Bri+ |      | SysRq|      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      | Vol- | Vol+ |Mute  |      |      |KBri- |KBri+ |KBTgl |      | Boot |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_BRID, KC_BRIU, _______, KC_SYRQ, _______, 
      _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, BL_DOWN, BL_UP,   BL_TOGG, _______, QK_BOOT,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};


// Backlight
#define RGB_BASE {0x59, 0x9c, 0x32}
#define RGB_LOWER {0x58, 0x8c, 0x69}
#define RGB_RAISE {0x38, 0x8c, 0x6e}
#define RGB_NAV {0x58, 0x8c, 0x69}
#define RGB_CMD {0x58, 0x8c, 0x69}
#define RGB_ADJST {0x58, 0x8c, 0x69}

/*
[_LAYER] = {
  RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP,
  RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP,
  RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP,
  RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP
},
*/

const uint8_t PROGEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [_BASE] = {
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE
  },

  [_LOWER] = {
    RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER,
    RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER,
    RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER,
    RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER
  },

  [_RAISE] = {
    RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE,
    RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE,
    RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE,
    RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE
  },

  [_NAVIGATION] = {
    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV,
    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV,
    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV,
    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV
  },

  [_COMMAND] = {
    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD,
    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD,
    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD,
    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD
  },

  [_ADJUST] = {
    RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST,
    RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST,
    RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST,
    RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST
  }
}

// Misc
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _COMMAND);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
