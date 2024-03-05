#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------.                  ,-----------------------------------------------.
      KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSPC,\
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     KC_LSFT,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                      KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,\
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                      KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,\
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     KC_LALT,  LOWER, KC_SPC,    KC_SPC,  RAISE,KC_LGUI \
                                  //`-----------------------'  `-----------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------.                  ,-----------------------------------------------.
     _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                    KC_EQL,KC_LPRN,KC_RPRN,KC_EXLM,  KC_AT,_______,\
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     _______,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,                   KC_AMPR,KC_LCBR,KC_RCBR,KC_HASH, KC_DLR, KC_DEL,\
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     _______, KC_DOT,KC_SLSH,KC_ASTR,KC_MINS,KC_PLUS,                   KC_PIPE,KC_LBRC,KC_RBRC,KC_PERC,KC_CIRC,_______,\
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,_______,   _______,_______,_______ \
                                  //`-----------------------'  `-----------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------.                  ,-----------------------------------------------.
     _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4, KC_GRV,                   KC_HOME,KC_PGDN,KC_PGUP, KC_END,KC_PSCR,_______,\
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     _______,  KC_F5,  KC_F6,  KC_F7,  KC_F8,KC_BSLS,                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT, KC_ESC, KC_DEL,\
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     _______,  KC_F9, KC_F10, KC_F11, KC_F12,KC_UNDS,                   KC_MUTE,KC_MPRV,KC_MPLY,KC_MNXT,XXXXXXX,_______,\
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,_______,   _______,_______,_______ \
                                  //`-----------------------'  `-----------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------.                  ,-----------------------------------------------.
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     NK_TOGG,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,QK_BOOT,\
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     XXXXXXX,_______,XXXXXXX,   XXXXXXX,_______,XXXXXXX \
                                  //`-----------------------'  `-----------------------'
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