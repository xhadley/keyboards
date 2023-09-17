#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE, KC_HOME,   KC_MPLY, \
        MO(1),   KC_UP,   RGB_MOD, \
        KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        RESET,   BL_STEP, KC_STOP, \
        _______, KC_HOME, RGB_MOD, \
        KC_MPRV, KC_END,  KC_MNXT \
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}