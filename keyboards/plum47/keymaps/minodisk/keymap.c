/* Copyright 2020 Masayuki Takagi
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
    _QWERTY,
    _LOWER,
    _RAISE
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

// #define PERMISSIVE_HOLD
// #define RETRO_TAPPING
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LWR   LT(LOWER,KC_ESC)
#define RSE   LT(RAISE,KC_BSPC)
#define CAPT  G(S(C(KC_4)))
#define IME   G(KC_SPC)
#define SPOT  A(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  //,-----------------------------------------------------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
          IME, KC_LALT,  KC_ESC, KC_LGUI,   LOWER,     KC_SPC      ,   RAISE,  KC_ENT, KC_BSPC,    CAPT,    SPOT
  //,-----------------------------------------------------------------------------------------------------------.
),
[_LOWER] = LAYOUT(
  //,-----------------------------------------------------------------------------------------------------------.
      KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PPLS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G), KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), G(KC_N), G(KC_M), KC_LBRC, KC_RBRC, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,       IME       , _______, _______, _______, _______, _______
  //,-----------------------------------------------------------------------------------------------------------.
),
[_RAISE] = LAYOUT(
  //,-----------------------------------------------------------------------------------------------------------.
   A(KC_TILD), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G), KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,S(KC_SCLN),S(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), G(KC_N), G(KC_M),S(KC_LBRC),S(KC_RBRC),S(KC_SLSH),S(KC_BSLS),
  //|--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,       SPOT      , _______, _______, _______, _______, _______
  //,-----------------------------------------------------------------------------------------------------------.
)

};

static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                lower_pressed = true;
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _QWERTY);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _QWERTY);
                if (lower_pressed) {
                    register_code(KC_ESC);
                    unregister_code(KC_ESC);
                }
                lower_pressed = false;
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                raise_pressed = true;
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _QWERTY);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _QWERTY);
                if (raise_pressed) {
                    register_code(KC_BSPC);
                    unregister_code(KC_BSPC);
                }
                raise_pressed = false;
            }
            return false;
            break;
        default :
            if (record->event.pressed) {
                lower_pressed = false;
                raise_pressed = false;
            }
            break;
    }
    return true;
}
