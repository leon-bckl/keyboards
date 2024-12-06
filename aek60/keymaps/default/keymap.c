// Copyright 2022 Leon Buckel (@Leon280698)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │Esc│1  │2  │3  │4  │5  │6  │7  │8  │9  │0  │-  │+  │Bspc   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │Tab  │Q  │W  │E  │R  │T  │Y  │U  │I  │O  │P  │[  │]  │\    │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │Caps  │A  │S  │D  │F  │G  │H  │J  │K  │L  │;  │'  │Enter   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┬──┴┐
 * │Shift   │Z  │X  │C  │V  │B  │N  │M  │,  │.  │/  │Del│↑  │Fn │
 * ├─────┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┴─┬─┴───┼───┼───┼───┤
 * │Ctrl │Alt │GUI  │Space                    │GUI  │←  │↓  │→  │
 * └─────┴────┴─────┴─────────────────────────┴─────┴───┴───┴───┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(1),   KC_UP,   KC_DEL,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MSTP, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______, KC_HOME, KC_PGUP, _______,
        _______, _______, _______,                            _______,                            KC_APP,  KC_END,  KC_PGDN, KC_INS
    )
};

void matrix_init_user(void) {
	DDRD |= (1 << 2);
	PORTD &= ~(1 << 2);
}

void led_set_kb(uint8_t usb_led) {
	if(usb_led & ( 1 << USB_LED_CAPS_LOCK)){
		PORTD |= (1 << 2);
	}else{
		PORTD &= ~(1 << 2);
	}
}
