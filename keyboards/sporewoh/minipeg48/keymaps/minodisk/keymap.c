/* Copyright 2015-2021 Jack Humbert
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

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define L2_ESC   LT(_LOWER,KC_ESC)
#define L3_SPC   LT(_RAISE,KC_SPC)
#define SC_SLEEP LAG(KC_PWR)
#define SC_IME   G(KC_SPC)
#define SC_SPOT  A(KC_SPC)
#define SC_SSF   LSG(KC_4)
#define SC_SSC   G(C(S(KC_4)))
#define SC_EMO   G(C(KC_SPC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------.
 * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Ctl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Shift|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  \  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Ja  | Scr | Alt | Bs  | Cmd | Esc |Space| Ctl |Enter|Shift| Emo | En  |
 * `-----------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
  KC_LNG1, SC_SSF,  KC_LALT, KC_BSPC, KC_LGUI, L2_ESC,  L3_SPC,  KC_RCTL, KC_ENT,  KC_RSFT, SC_EMO,  KC_LNG2
),

/* Lower
 * ,-----------------------------------------------------------------------.
 * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  =  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |  ←  |  ↑  |  ↓  |  →  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |  [  |  ]  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |HYPR1|HYPR2|HYPR3|HYPR4|HYPR5|     |     |HYPR6|HYPR7|HYPR8|HYPR9|HYPR0|
 * `-----------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
  _______,    _______,    _______,    _______,    _______,    _______, KC_LEFT, KC_DOWN,    KC_UP,      KC_RIGHT,   _______,    _______,
  _______,    _______,    _______,    _______,    _______,    _______, _______, _______,    KC_LBRC,    KC_RBRC,    _______,    _______,
  HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5), XXXXXXX, MO(4),   HYPR(KC_6), HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), HYPR(KC_0)
),

/* Raise
 * ,-----------------------------------------------------------------------.
 * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |  +  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |  ←  |  ↓  |  ↑  |  →  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |  {  |  }  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_PLUS,
  _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,    _______,
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LCBR,    KC_RCBR,    _______,    _______,
  HYPR(KC_A), HYPR(KC_B), HYPR(KC_C), HYPR(KC_D), HYPR(KC_E), MO(4),      XXXXXXX,    HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_I), HYPR(KC_J)
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------.
 * |     | Fn1 | Fn2 | Fn3 | Fn4 | Fn5 | Fn6 | Fn7 | Fn8 | Fn9 | Fn10|Power|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     | Prev| Vol-| Vol+| Next|     |Sleep|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     | Boot|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_PWR,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, KC_MPRV, KC_VOLD,    KC_VOLU,    KC_MNXT,    XXXXXXX,    SC_SLEEP,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, KC_MPLY, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    QK_BOOT,
  HYPR(KC_K), HYPR(KC_L), HYPR(KC_M), HYPR(KC_N), HYPR(KC_O), XXXXXXX, XXXXXXX, HYPR(KC_P), HYPR(KC_Q), HYPR(KC_R), HYPR(KC_S), HYPR(KC_T)
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
