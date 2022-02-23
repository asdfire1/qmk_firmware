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
enum custom_keycodes {
    M_CTRLAV = SAFE_RANGE,
    M_WINSHIFTS,
    M_WINPRINT,
    M_EMAIL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case M_CTRLAV:
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_A)SS_UP(X_A)SS_DOWN(X_V)SS_UP(X_V)SS_UP(X_LCTRL));
        return false; break;
      case M_WINSHIFTS:
        SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)"S"SS_UP(X_LGUI)SS_UP(X_LSFT));
        return false; break;
      case M_WINPRINT:
        SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_PSCR)SS_UP(X_LGUI));
        return false; break;
      case M_EMAIL:
        SEND_STRING("asdfirepl@gmail.com");
        return false; break;       
          }
    }
    return true;
};
// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _GAME,
  _E1
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SFTENT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|      | LGUI | LAlt | Lower| Space| Space| Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,     KC_Y,     KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,     KC_H,     KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,     KC_N,     KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_NO,   KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,   KC_SPC,   MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |SFTENT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|      | LGUI | LAlt | Lower| Space| Space| Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,       KC_G,     KC_J,     KC_L,       KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,       KC_D,     KC_H,     KC_N,       KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,     KC_K,     KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_NO,   KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,   KC_SPC,   MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower

 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_NUM,  KC_EXLM,    KC_AT,    KC_HASH,    KC_DLR,    KC_LPRN,    KC_RPRN,    KC_PLUS,    KC_7,    KC_8,    KC_9,    KC_BSPC,
    KC_CAPS,  KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LCBR,   KC_RCBR,   KC_MINS, KC_4,  KC_5, KC_6, KC_DEL,
    KC_LSFT, M_CTRLAV,   KC_UNDS,   KC_PIPE,   KC_BSLS,  KC_LBRC,  KC_RBRC,  KC_EQL, KC_1, KC_2, KC_3, KC_GRV,
    KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, TG(_COLEMAK), KC_TRNS, KC_0, KC_VOLD, KC_VOLU, KC_TILD
),
/* Raise

 */
[_RAISE] = LAYOUT_ortho_4x12(
    M_WINSHIFTS, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_PGUP, KC_HOME, KC_PSCR, KC_NO,    KC_NO,   KC_BRIU,  RESET,
    M_WINPRINT,  KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_PGDN, KC_END,  KC_NO,   KC_NO,    KC_NO,   KC_BRID,  EEP_RST,
    KC_LSFT,     KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_F13,  M_EMAIL, KC_NO,   KC_NO,    KC_NO,   KC_NO,    TG(_GAME),
    KC_TRNS,     KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MPLY, KC_TRNS, KC_MPRV,  KC_VOLD, KC_VOLU,  KC_MNXT
),

[_GAME] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,       KC_5,     KC_6,     KC_B,       KC_COMM,    KC_DOT,    KC_SLSH,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,     KC_Y,     KC_U,       KC_I,    KC_O,    KC_P, KC_QUOT,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,       KC_G,     KC_H,     KC_J,       KC_K,    KC_L,    KC_SCLN, KC_SFTENT,
    KC_LCTL, KC_Z,   KC_X, KC_C, KC_V, KC_SPC,   KC_SPC,   MO(_RAISE), KC_N, KC_M, KC_LALT,   KC_F1
),

[_E1] = LAYOUT_ortho_4x12(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
)


};
/*
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
*/
/*
/ UNCOMMENT FOR ROTARY ENCODER
/

static bool tabbing = false;
static uint16_t tabtimer;
#define TABBING_TIMER 750

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }
        tap_code(KC_TAB);
      } else {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }

        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
    } else {
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    }
  }
}

void matrix_scan_user(void) {
  if(tabbing) {
    if (timer_elapsed(tabtimer) > TABBING_TIMER) {
      unregister_code(KC_LALT);
      tabbing = false;
    }
  }
}

*/

void matrix_init_user(void) {

}
