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
  _MAC,
  _WIN,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define MO_ADJ   MO(_ADJUST)
#define SC_SLEEP LAG(KC_PWR)

#define MA_PRSC  LSG(KC_4)
#define WI_PRSC  LSG(KC_S)

#define MA_EMO   G(C(KC_SPC))
#define WI_EMO   G(KC_DOT)

#define MA_SPOT  A(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Mac
 * ,-----------------------------------------------------------------------.
 * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Ctl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Shift|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  \  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |PrScr|PrTab|NxTab|AltJa|CmdBs|LoEsc|RaEnt|CtlSp|SftEn|PrWin|NxWin| Emo |
 * `-----------------------------------------------------------------------'
 */
[_MAC] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,            KC_R,            KC_T,               KC_Y,               KC_U,           KC_I,            KC_O,    KC_P,    KC_MINS,
  KC_LCTL, KC_A,    KC_S,    KC_D,            KC_F,            KC_G,               KC_H,               KC_J,           KC_K,            KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,            KC_V,            KC_B,               KC_N,               KC_M,           KC_COMM,         KC_DOT,  KC_SLSH, KC_BSLS,
  MA_PRSC, _______, _______, LALT_T(KC_LNG1), LGUI_T(KC_BSPC), LT(_LOWER, KC_ESC), LT(_RAISE, KC_ENT), RCTL_T(KC_SPC), RSFT_T(KC_LNG2), _______, _______, MA_EMO
),

/* Win
 * ,-----------------------------------------------------------------------.
 * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Ctl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Shift|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  \  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |PrScr|PrTab|NxTab|AltJa|CtlBs|LoEsc|RaEnt|GuiSp|SftEn|     | Emo | Emo  |
 * `-----------------------------------------------------------------------'
 */
[_WIN] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______,         _______, _______, _______,        _______, _______, _______, _______, _______,
  _______, _______, _______, _______,         _______, _______, _______,        _______, _______, _______, _______, _______,
  _______, _______, _______, _______,         _______, _______, _______,        _______, _______, _______, _______, _______,
  WI_PRSC, _______, _______, _______, LCTL_T(KC_BSPC), _______, _______, RGUI_T(KC_SPC), _______, _______, DF(_GAME), WI_EMO
),

/* Game
 * ,-----------------------------------------------------------------------.
 * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Ctl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Shift|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  \  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |PrScr|PrTab|NxTab|AltJa|CtlBs|LoEsc|RaEnt|GuiSp|SftEn|     | Emo | Emo  |
 * `-----------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_BSPC, _______, _______, KC_SPC,  _______, _______, DF(_WIN), _______
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
  HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5), XXXXXXX, MO_ADJ,  HYPR(KC_6), HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), HYPR(KC_0)
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
  HYPR(KC_A), HYPR(KC_B), HYPR(KC_C), HYPR(KC_D), HYPR(KC_E), MO_ADJ,     XXXXXXX,    HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_I), HYPR(KC_J)
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

bool process_detected_host_os_kb(os_variant_t detected_os) {
  if (!process_detected_host_os_user(detected_os)) {
    return false;
  }
  switch (detected_os) {
    case OS_MACOS:
    case OS_IOS:
      layer_move(_MAC);
      break;
    default:
      layer_move(_WIN);
      break;
  }
  return true;
}
