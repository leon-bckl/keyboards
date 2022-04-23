// Copyright 2022 Leon Buckel (@Leon280698)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
 * ┌───┬───┬───┬───┐
 * │NLC│ / │ * │ = │
 * ├───┼───┼───┼───┤
 * │ 7 │ 8 │ 9 │ - │
 * ├───┼───┼───┼───┤
 * │ 4 │ 5 │ 6 │ + │
 * ├───┼───┼───┼───┤
 * │ 1 │ 2 │ 3 │   │
 * ├───┴───┼───┤Ent│
 * │   0   │ . │   │
 * └───────┴───┴───┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NLCK, KC_PSLS, KC_PAST, KC_EQL,  
        KC_P7,   KC_P8,   KC_P9,   KC_PMNS, 
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS, 
        KC_P1,   KC_P2,   KC_P3,   KC_PENT, 
        KC_P0,   KC_PDOT  
    )
};
