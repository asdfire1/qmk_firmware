/* Copyright 2020 Victor Lucachi
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,---------------------------.
 * |  PREV|  Play|  Next|SCR   |
 * |------+------+------+------|
 * |   4  |   5  |   6  | ESC  |
 * |------+------+------+------|
 * |   1  |   2  |   3  | TAB  |
 * |------+------+------+------|
 * |  FN1 |   0  |   .  |ENTER |
 * `---------------------------'
 */
[_BASE] = LAYOUT_ortho_4x4(
    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_PSCR,
    KC_F13,    KC_F14,    KC_F15,    KC_DEL,
    KC_F16,    KC_F17,    KC_F18,    KC_END,
    KC_F19, KC_F20,    KC_F21,  TG(_FN1)
),

/* FN1
 * ,---------------------------.
 * | RESET|      |      |      |
 * |------+------+------+------|
 * |      |      |      |   +  |
 * |------+------+------+------|
 * |      |      |      |   -  |
 * |------+------+------+------|
 * |      |      |      |   =  |
 * `---------------------------'
 */
[_FN1] = LAYOUT_ortho_4x4(
    KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
    KC_P4,    KC_P5,    KC_P6,    KC_PMNS,
    KC_P1,    KC_P2,    KC_P3,    KC_ENTER,
    RESET, KC_P0,    KC_PDOT,  KC_TRNS
),

/* FN2
 * ,---------------------------.
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * `---------------------------'
 */
[_FN2] = LAYOUT_ortho_4x4(
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
),

/* FN3
 * ,---------------------------.
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * `---------------------------'
 */
[_FN3] = LAYOUT_ortho_4x4(
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
)
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}