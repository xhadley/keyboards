#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _GAME	1
#define _NAV    2
#define _LOWER  3
#define _RAISE  4
#define _MENU   16

enum custom_keycodes {
  EXIT = SAFE_RANGE,
  LOWER,
  RAISE
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_GAME TG(_GAME)
#define KC_NAV  MO(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | GAME | Win  | ALT  | Lower| NAV  | Space| Raise| MPRV | MPLY | MNXT | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_ESC,  KC_GAME, KC_LGUI, KC_LALT, LOWER,   KC_NAV,  KC_SPC,  RAISE,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE}
},

/* Game
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | GAME | Win  | ALT  | Lower| Space| NAV  | Raise| MPRV | MPLY | MNXT | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, KC_SPC,  KC_NAV,  _______, _______, _______, _______, _______}
},

/* Nav layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |  Up  |      |      |      | Home | PgUp | Ins  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      | Left | Down |Right |      |      | End  | PgDn |PrntSc|      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |  F5  |      |      |      |      |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Win  | Alt  |      | NAV  | NAV  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = {
  {_______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_INS,  XXXXXXX, _______},
  {_______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_END,  KC_PGDN, KC_PSCR, XXXXXXX, KC_DEL },
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |      |   !  |   @  |   #  |   $  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   6  |   7  |   8  |   9  |   0  |      |   =  |   +  |   -  |   *  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F12 |      |      |      |   `  |      |      |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  | Win  | Alt  | Lower| Space| Space| Raise|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______},
  {_______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR, KC_DEL },
  {_______, KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, _______},
  {KC_F1,   KC_F2,   _______, _______, _______, KC_SPC,  KC_SPC,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |      |   (  |   )  |   _  |   %  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F5  |  F6  |  F7  |  F8  |      |      |   {  |   }  |   \  |   ^  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F9  |  F10 |  F11 |  F12 |      |      |   [  |   ]  |   |  |   &  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Win  | Alt  | Lower| Space| Space| Raise|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, KC_PERC, _______},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS, KC_CIRC, KC_DEL },
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_PIPE, KC_AMPR, _______},
  {XXXXXXX, XXXXXXX, _______, _______, _______, KC_SPC,  KC_SPC,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Menu
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Lower|      |      | Raise|      |      |      | Reset|
 * `-----------------------------------------------------------------------------------'
 */
[_MENU] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, RESET  }
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EXIT:
      if (record->event.pressed) {
        layer_clear();
        clear_keyboard();
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      }
      break;
  }
  return true;
}