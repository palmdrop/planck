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
#include "sendstring_swedish.h"

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
  _ADJUST,

  // Variable input
  _CAMEL,
  _SNAKE, // doubles as CONSTANT layer when shift is held
  // _CONSTANT,
  _KEBAB
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
  BACKLIT,
  EXT_PLV
};

enum custom_keycodes {
  UR_OSFT = SAFE_RANGE, // Custom one-shot shift
  UR_CAPS,
  UR_TILD, // ~
  UR_GRV,  // `
  UR_CIRC,  // ^

  UR_CONSTANT
};

// Multi-key codes
#define CTLSFTI   LCTL(LSFT(KC_I))
#define CTLALTDEL LCTL(LALT(KC_DEL))

#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO  LCTL(KC_Z)
#define REDO  LCTL(LSFT(KC_Z))

// Layers
#define LOWER  LT(_LOWER, KC_TAB)
// #define RAISE  LT(_RAISE, KC_BSPC)
#define RAISE  LT(_RAISE, UR_OSFT)
#define ADJUST MO(_ADJUST)
#define NAVESQ LT(_NAVIGATION, KC_ESC)
#define NAVSPC LT(_NAVIGATION, KC_SPC)

// Combos
const uint16_t PROGMEM meta_combo[]      = {LALT_T(KC_S), LSFT_T(KC_D), COMBO_END};
const uint16_t PROGMEM escape_combo[]    = {LCTL_T(KC_F), KC_J,         COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_J,         KC_K,         COMBO_END};

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
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * | Lead |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Rep  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Rep  |      | Gui  | Alt  |Lower |    Space    |Raise |Shift |      |  Tab | Enter|
  * `-----------------------------------------------------------------------------------'
  */
  [_BASE] = LAYOUT_planck_grid(
      QK_LEAD, KC_Q,    KC_W,         KC_E,           KC_R,         KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,         KC_P,            SE_ARNG,
      NAVESQ,  KC_A,    LALT_T(KC_S), LSFT_T(KC_D),   LCTL_T(KC_F), KC_G,    KC_H,    KC_J,    KC_K,     RSFT_T(KC_L), RCTL_T(SE_ODIA), SE_ADIA,
      KC_LSFT, KC_Z,    KC_X,         KC_C,           KC_V,         KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,       SE_MINS,         QK_REP,
      QK_REP,  _______, KC_LGUI,      KC_LALT,        LOWER,        KC_SPC,  KC_SPC,  RAISE,   KC_RSFT,  ADJUST,       KC_TAB,          RSFT_T(KC_ENTER)
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |   ~  |  !   |   "  |   #  |   ¤  |   %  |   &  |   /  |   (  |   )  |   =  |  ?   |
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
      SE_ACUT, UR_GRV,  SE_QUOT, SE_LPRN, SE_RPRN, SE_DLR,  SE_BSLS, SE_LCBR, SE_RCBR, UR_TILD, UR_CIRC, SE_ASTR,
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
      _______,   _______,  LCTL(KC_RGHT),  _______,         REDO,     _______,        COPY,     UNDO,     KC_HOME,  KC_ENT,           PASTE,           KC_BSPC,
      _______,   KC_END,   KC_LALT,        LSFT_T(KC_DEL),  KC_LCTL,  TD(TD_GG),      KC_LEFT,  KC_DOWN,  KC_UP,    RSFT_T(KC_RGHT),  RCTL_T(KC_WH_U), RCTL(KC_BSPC),
      KC_LSFT,   _______,  KC_BSPC,        KC_BSPC,         _______,  LCTL(KC_LEFT),  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,          KC_WH_D,         _______,
      _______,   _______,  _______,        _______,         _______,  KC_BTN1,        KC_BTN1,  KC_BTN3,  _______,  _______,          _______,         _______
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
                 // NOTE: Could maybe access rec2 by double-tapping?
                 // NOTE: could also mabye use leader key for creating macros?
      DM_PLY1,   DM_REC1,  _______,  _______,  _______, _______,   _______,  _______,    CTLSFTI,     _______,      LSFT(KC_INS), CTLALTDEL,
      UR_CAPS,   _______,  KC_SYRQ,  _______,  _______, _______,   _______,  TO(_CAMEL), TO(_SNAKE),  TO(_KEBAB),   UR_CONSTANT,  _______,
      _______,   _______,  _______,  CW_TOGG,  _______, _______,   _______,  _______,    _______,     _______,      _______,      _______,
      _______,   _______,  _______,  _______,  _______, _______,   _______,  _______,    _______,     _______,      _______,      _______
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
  ),

  /* camelCase
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |Oneshot shift|      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_CAMEL] = LAYOUT_planck_grid(
      _______,   _______,  _______,  _______,  _______,  _______,        _______,        _______,  _______,  _______,  _______,  _______,
      TO(_BASE), _______,  _______,  _______,  _______,  _______,        _______,        _______,  _______,  _______,  _______,  _______,
      _______,   _______,  _______,  _______,  _______,  _______,        _______,        _______,  _______,  _______,  _______,  _______,
      _______,   _______,  _______,  _______,  _______,  OSM(MOD_LSFT),  OSM(MOD_LSFT),  _______,  _______,  _______,  _______,  _______
  ),

  /* snake_case
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |  underscore |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_SNAKE] = LAYOUT_planck_grid(
      _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      TO(_BASE), _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,   _______,  _______,  _______,  _______,  SE_UNDS,  SE_UNDS,  _______,  _______,  _______,  _______,  _______
  ),

  /* kebab-case
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |    minus    |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_KEBAB] = LAYOUT_planck_grid(
      _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      TO(_BASE), _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,   _______,  _______,  _______,  _______,  SE_MINS,  SE_MINS,  _______,  _______,  _______,  _______,  _______
  ),
};

// Per key settings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NAVSPC: 
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Ensure that hold action is prioritized for layer keys
    // This ensures that it's possible to roll to these layers without accidentally triggering the tap action.
    // case RAISE:
    case LOWER:
      return true;
    default:
      return false;
  }
}


// Backlight
#define RGB_BASE {0x49, 0x67, 0x13}
#define RGB_LBASE {0x03, 0x04, 0x01}
// #define RGB_LBASE {0xFF, 0x00, 0x00}

#define RGB_LOWER {0x58, 0x8c, 0x69}
#define RGB_LLOWER {0x28, 0x5c, 0x39}

#define RGB_RAISE {0x38, 0x8c, 0x6e}
#define RGB_LRAISE {0x08, 0x5c, 0x3e}

#define RGB_NAV {0x58, 0x8c, 0x69}
#define RGB_LNAV {0x38, 0x6c, 0x49}

#define RGB_CMD {0x58, 0x8c, 0x69}
#define RGB_LCMD {0x38, 0x6c, 0x49}

#define RGB_ADJST {0x58, 0x8c, 0x69}
#define RGB_LADJST {0x38, 0x6c, 0x49}

/*
[_LAYER] = {
  RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP,
  RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP,
  RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP,
  RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP, RGB_TMP
},
*/

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
  [_BASE] = {
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,      RGB_LBASE,     RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE
  },
  /*
  [_BASE] = {
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,
    RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE,      RGB_LBASE,     RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE, RGB_BASE
  },

  [_LOWER] = {
    RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER,
    RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER,
    RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER,
    RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER,      RGB_LLOWER,      RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER, RGB_LOWER
  },

  [_RAISE] = {
    RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE,
    RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE,
    RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE,
    RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE,       RGB_LRAISE,     RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE, RGB_RAISE
  },

  [_NAVIGATION] = {
    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV,
    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV,
    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV,
    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV,      RGB_LNAV,    RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV, RGB_NAV
  },

  [_COMMAND] = {
    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD,
    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD,
    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD,
    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD,      RGB_LCMD,    RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD, RGB_CMD
  },

  [_ADJUST] = {
    RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST,
    RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST,
    RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST,
    RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST,       RGB_LADJST,     RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST, RGB_ADJST
  }
  */
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][i][0]),
      .g = pgm_read_byte(&ledmap[layer][i][1]),
      .b = pgm_read_byte(&ledmap[layer][i][2]),
    };
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

bool rgb_matrix_indicators_user(void) {
  set_layer_color(_BASE);
  return false;
  // if (g_suspend_state || disable_layer_color) { return; }
  /*
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      set_layer_color(_BASE);
      break;
    case _LOWER:
      set_layer_color(_LOWER);
      break;
    case _RAISE:
      set_layer_color(_RAISE);
      break;
    case _NAVIGATION:
      set_layer_color(_NAVIGATION);
      break;
    case _COMMAND:
      set_layer_color(_COMMAND);
      break;
    case _ADJUST:
      set_layer_color(_ADJUST);
      break;
  }
    return false;
  */
}

// Misc
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _COMMAND);
}

// Caps management
bool is_caps_enabled = false;
void toggle_caps(void) {
  is_caps_enabled = !is_caps_enabled;
  tap_code16(KC_CAPS);
}

void disable_caps(void) {
  caps_word_off();

  if(is_caps_enabled) {
    tap_code16(KC_CAPS);
    is_caps_enabled = false;
  }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
      // Keycodes that continue Caps Word, with shift applied.
      case KC_MINS:
        return true;
      case KC_A ... KC_Z:
      case SE_ARNG:
      case SE_ADIA:
      case SE_ODIA:
        add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
        return true;

      // Keycodes that continue Caps Word, without shifting.
      case KC_1 ... KC_0:
      case KC_BSPC:
      case KC_DEL:
      case KC_UNDS:
        return true;
      
      // Disable Caps Word
      default:
        return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_dynamic_macros.md#dynamic_macro_user_call
	uint16_t macro_kc = ((keycode == NAVESQ) ? DM_RSTP : keycode);

	if (!process_dynamic_macro(macro_kc, record)) {
    disable_caps();
		return false;
	}

  switch (keycode) {
    /* LAYER MANAGEMENT */

    // Workaround for adding oneshot shift on tap to layer switch key for raise
    // Raise will act as oneshot shift when tapped
    case RAISE: 
      // When tapping RAISE, trigger a oneshot shift modifier.
      if (record->tap.count && record->event.pressed) {
        add_oneshot_mods(MOD_BIT(KC_LSFT));
        return false;        
      } 
      break;
    // Custom management of navigation layer / escape key when caps is enabled
    // If caps is enabled, escape will disable it automatically
    case NAVESQ: 
      if (record->tap.count && record->event.pressed) {
        clear_mods();

        if (is_caps_enabled) {
          disable_caps();
          return false;
        }

        return true;
      }
      break;
    // Enter CONSTANT_CASE layer by moving to snake_case layer with shift modifier activated
    case UR_CONSTANT: 
      if (record->event.pressed) {
        layer_move(_SNAKE);
        register_mods(MOD_BIT(KC_LSFT));
      }

      return false;
      break;

    // Make sure mods are cleared when moving to base layer
    case TO(_BASE):
      if (record->event.pressed) {
        clear_mods();
      }

      return true;
      break;
    /* CUSTOM KEYCODES */

    // Manually manage caps to easily keep track of caps state
    case UR_CAPS: 
      if (record->event.pressed) {
        toggle_caps();
      }
      return false;
    // Make it easier to send ~, ` and ^ on swedish layouts
    case UR_TILD: 
      if (record->event.pressed) {
        SEND_STRING("~");
      }
      return false;
    case UR_GRV: 
      if (record->event.pressed) {
        SEND_STRING("`");
      }
      return false;
    case UR_CIRC: 
      if (record->event.pressed) {
        SEND_STRING("^");
      }
      return false;
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

void leader_end_user(void) {
  // Modifiers
  //  C + S + T => Ctrl + Shift + T
  if(leader_sequence_three_keys(KC_C, KC_S, KC_T)) {
    tap_code16(LCTL(LSFT(KC_T)));
  } else 
  // C + T => Ctrl + T
  if(leader_sequence_two_keys(KC_C, KC_T)) {
    tap_code16(LCTL(KC_T));
  } else 
  // D => Delete
  if(leader_sequence_one_key(KC_D)) {
    tap_code16(KC_DEL);
  } else 
  // G + U => Commit and push basic git updates
  // NOTE: Mostly used for note-taking and writing repos, not code.
  if(leader_sequence_two_keys(KC_G, KC_U)) {
    SEND_STRING("git add .; git commit -m \"update\"; git push");
  }
}
