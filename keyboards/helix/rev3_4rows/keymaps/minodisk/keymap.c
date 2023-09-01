/* Copyright 2020 yushakobo
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

#define L1_ESC   LT(1,KC_ESC)
#define L2_SPC   LT(2,KC_SPC)
#define GUI_SPC  GUI_T(KC_SPC)
#define GUI_EN   GUI_T(KC_LNG2)
#define ALT_EN   ALT_T(KC_LNG2)
#define CTL_JA   CTL_T(KC_LNG1)
#define ALT_JA   ALT_T(KC_LNG1)
#define SC_SLEP  G(A(KC_POWER))
#define SC_IME   G(KC_SPC)
#define SC_SPOT  A(KC_SPC)
#define SC_SSF   G(S(KC_4))
#define SC_SSC   G(C(S(KC_4)))
#define SC_EMO   G(C(KC_SPC))
#define SC_0     G(C(S(A(KC_0))))
#define SC_1     G(C(S(A(KC_1))))
#define SC_2     G(C(S(A(KC_2))))
#define SC_3     G(C(S(A(KC_3))))
#define SC_4     G(C(S(A(KC_4))))
#define SC_5     G(C(S(A(KC_5))))
#define SC_6     G(C(S(A(KC_6))))
#define SC_7     G(C(S(A(KC_7))))
#define SC_8     G(C(S(A(KC_8))))
#define SC_9     G(C(S(A(KC_9))))
#define SC_10    G(C(S(A(KC_LBRC))))
#define SC_11    G(C(S(A(KC_RBRC))))
#define SC_R     G(C(S(A(KC_R))))
#define SC_F     G(C(S(A(KC_F))))
#define SC_V     G(C(S(A(KC_V))))
#define SC_E     G(C(S(A(KC_E))))
#define SC_D     G(C(S(A(KC_D))))
#define SC_C     G(C(S(A(KC_C))))

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _MAC = 0,
  _WIN,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  EISU = SAFE_RANGE,
  KANA,
  ADJUST,
  RGBRST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAC] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
      SC_SSC,  SC_SSF,  SC_EMO,  CTL_JA,  ALT_EN,  GUI_SPC,  L1_ESC, L2_SPC,  KC_BSPC, KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
      ),

  [_WIN] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
      SC_SSC,  SC_SSF,  SC_EMO,  CTL_JA,  ALT_EN,  KC_SPC,  L1_ESC, L2_SPC,  KC_BSPC, KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
      ),

  [_LOWER] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
      _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_LBRC, KC_RBRC, _______, _______,
      _______, _______, _______, _______, SC_0,    SC_1,    XXXXXXX,   MO(3), SC_2,    SC_3,    KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
      ),

  [_RAISE] = LAYOUT(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
      _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
      _______, _______, _______, _______, _______, XXXXXXX,                   SC_SPOT, _______, KC_LCBR, KC_RCBR, _______, _______,
      _______, _______, _______, _______, SC_4,    SC_5,    MO(3),   XXXXXXX, SC_6,    SC_7,    KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
      ),

  [_ADJUST] =  LAYOUT(
      QK_BOOT, XXXXXXX, XXXXXXX, SC_E,    SC_R,    KC_VOLU,                   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_POWER,
      XXXXXXX, XXXXXXX, XXXXXXX, SC_D,    SC_F,    KC_VOLD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, SC_C,    SC_V,    KC_MPLY,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SC_SLEP,
      _______, _______, _______, _______, SC_8,    SC_9,    XXXXXXX, XXXXXXX, SC_10,   SC_11,   RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD
      )

};

void keyboard_post_init_user(void) {
  wait_ms(400);
  switch (detected_host_os()) {
    case OS_WINDOWS:
      layer_move(_WIN);
      break;
    case OS_MACOS:
    case OS_IOS:
      layer_move(_MAC);
      break;
    case OS_LINUX:
      layer_move(_WIN);
      break;
    default:
      layer_move(_WIN);
  }
}
