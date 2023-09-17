#include "orthodox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN		1
#define _LOWER  2
#define _RAISE  3
#define _ADJUST	16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};


#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_FN	MO(_FN)
#define KC_LOWR	LOWER
#define KC_RASE RAISE
#define KC_RST	RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                                                                  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   `  |\/\/\/| Esc  |                                        | Win  |\/\/\/| Alt  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  | LOWER| Space|  FN  |                                        | Del  | Space| RAISE|   N  |   M  |   ,  |   .  |   /  | Enter|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_GRV,  XXXXXXX, KC_ESC,          KC_LGUI, XXXXXXX, KC_LALT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LOWR, KC_SPC,  KC_FN,           KC_DEL,  KC_SPC,  KC_RASE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT }
},

/* Nav layer
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Tab  |      |      |  Up  |      |      |                                                                                  |      | Home | PgUp | Ins  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * | Shift|      | Left | Down | Right|      |   `  |\/\/\/| Esc  |                                        | Win  |\/\/\/| Alt  |      | End  | PgDn |PrtScn|      |      |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      |  FN  |                                        | Del  |      |      |      |      |      |      |      | Enter|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */

[_NAV] = {
  {_______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,                                                               XXXXXXX, KC_HOME, KC_PGUP, KC_INS,  XXXXXXX, _______},
  {_______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, XXXXXXX, _______,         _______, XXXXXXX, _______, XXXXXXX, KC_END,  KC_PGDN, KC_PSCR, XXXXXXX, XXXXXXX},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,         _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______}
},

/* Lower
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |                                                                                  |      |   !  |   @  |   #  |   $  | Bksp |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * | Shift|   6  |   7  |   8  |   9  |   0  |   `  |\/\/\/| Esc  |                                        | Win  |\/\/\/| Alt  |      |   %  |   ^  |   &  |   *  |   "  |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F1  |  F2  |      |  F5  | F12  | LOWER| Space|  FN  |                                        | Del  | Space| RAISE|      |      |   ,  |   .  |   /  | Enter|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                                  XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______},
  {_______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, XXXXXXX, _______,         _______, XXXXXXX, _______, XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______},
  {_______, KC_F1,   KC_F2,   XXXXXXX, KC_F5,   KC_F12,  _______, _______, _______,         _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______}
},

/* Raise
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |                                                                                  |      |   (  |   )  |   _  |   +  | Bksp |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * | Shift|  F5  |  F6  |  F7  |  F8  |      |   `  |\/\/\/| Esc  |                                        | Win  |\/\/\/| Alt  |      |   {  |   }  |   -  |   =  |   "  |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F9  | F10  | F11  | F12  |      | LOWER| Space|  FN  |                                        | Del  | Space| RAISE|      |   [  |   ]  |   \  |   |  | Enter|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                                                               XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, _______, XXXXXXX, _______,         _______, XXXXXXX, _______, XXXXXXX, KC_LCBR, KC_RCBR, KC_MINS, KC_EQL,  _______},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______, _______, _______,         _______, _______, _______, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, _______}
},

/* Menu
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * |      |      |      |      |      |      |                                                                                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |\/\/\/|      |                                        |      |\/\/\/|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | LOWER|      |      |                                        |      |      | RAISE|      |      |      |      |      | Reset|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */
[_MENU] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET  }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
      	layer_clear();
      	clear_keyboard();
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      break;
  }
  return true;
}