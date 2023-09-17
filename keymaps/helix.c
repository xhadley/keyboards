/* Copyright 2020 yushakobo
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
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif


enum layer_number {
    _QWERTY = 0,
    _NAV,
    _LOWER,
    _RAISE,
    _ADJUST
};


enum custom_keycodes {
  QWERTY = SAFE_RANGE
};


#define NAV MO(_NAV)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Enter|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Esc  |      | Win  | ALT  | Lower| NAV  | Space|   `  | Space| Raise| MPRV | MPLY | MNXT | Mute |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
      KC_ESC,  XXXXXXX, KC_LGUI, KC_LALT, LOWER,   NAV,     KC_SPC,  KC_GRV,  KC_SPC,  RAISE,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE  \
      ),

  /* Nav
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |      |      |  Up  |      |      |             |      | Home | PgUp | Ins  |      | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|      | Left | Down | Right|      |             |      | End  | PgDn |PrntSc|      | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |      |      |      |  F5  |      |             |      |      |      |      |      | Enter|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      | Win  | ALT  |      | NAV  | Space|      | Space|      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_NAV] = LAYOUT( \
      _______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_PGUP, KC_INS,  XXXXXXX, _______, \
      _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                   XXXXXXX, KC_END,  KC_PGDN, KC_PSCR, XXXXXXX, KC_DEL,  \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_F5,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   1  |   2  |   3  |   4  |   5  |             |      |   !  |   @  |   #  |   $  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |             |      |   =  |   +  |   -  |   *  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |      |  F1  |  F2  |  F12 |      |             |      |      |   ,  |   .  |   /  | Enter|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      | Win  | ALT  | Lower|      | Space|      | Space| Raise|      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, \
      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR, KC_DEL,  \
      _______, XXXXXXX, KC_F1,   KC_F2,   KC_F12,  XXXXXXX,                   XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, _______, \
      XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |  F1  |  F2  |  F3  |  F4  |      |             |      |   (  |   )  |   _  |   %  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|  F5  |  F6  |  F7  |  F8  |      |             |      |   {  |   }  |   \  |   ^  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |  F9  |  F10 |  F11 |  F12 |      |             |      |   [  |   ]  |   |  |   &  | Enter|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      | Win  | ALT  | Lower|      | Space|      | Space| Raise|      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                   XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, KC_PERC, _______, \
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS, KC_CIRC, KC_DEL,  \
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                   XXXXXXX, KC_LBRC, KC_RBRC, KC_PIPE, KC_AMPR, _______, \
      XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | NKRO |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      | Lower|      |      |      |      | Raise|      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, RESET    \
      )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
