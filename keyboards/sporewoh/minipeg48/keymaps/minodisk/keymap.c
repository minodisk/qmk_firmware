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

#define L2_SPC   LT(_LOWER,KC_SPC)
#define L3_ESC   LT(_RAISE,KC_ESC)
#define GUI_SPC  GUI_T(KC_SPC)
#define GUI_EN   GUI_T(KC_LNG2)
#define ALT_EN   ALT_T(KC_LNG2)
#define CTL_JA   CTL_T(KC_LNG1)
#define ALT_JA   ALT_T(KC_LNG1)
#define SC_SLEP  G(A(KC_PWR))
#define SC_IME   G(KC_SPC)
#define SC_SPOT  A(KC_SPC)
#define SC_SSF   G(S(KC_4))
#define SC_SSC   G(C(S(KC_4)))
#define SC_EMO   G(C(KC_SPC))

#define SC_1     G(C(S(A(KC_1))))
#define SC_2     G(C(S(A(KC_2))))
#define SC_3     G(C(S(A(KC_3))))
#define SC_4     G(C(S(A(KC_4))))
#define SC_5     G(C(S(A(KC_5))))
#define SC_6     G(C(S(A(KC_6))))
#define SC_7     G(C(S(A(KC_7))))
#define SC_8     G(C(S(A(KC_8))))
#define SC_9     G(C(S(A(KC_9))))
#define SC_0     G(C(S(A(KC_0))))

#define SC_A     G(C(S(A(KC_A))))
#define SC_B     G(C(S(A(KC_B))))
#define SC_C     G(C(S(A(KC_C))))
#define SC_D     G(C(S(A(KC_D))))
#define SC_E     G(C(S(A(KC_E))))
#define SC_F     G(C(S(A(KC_F))))
#define SC_G     G(C(S(A(KC_G))))
#define SC_H     G(C(S(A(KC_H))))
#define SC_I     G(C(S(A(KC_I))))
#define SC_J     G(C(S(A(KC_J))))

#define SC_K     G(C(S(A(KC_K))))
#define SC_L     G(C(S(A(KC_L))))
#define SC_M     G(C(S(A(KC_M))))
#define SC_N     G(C(S(A(KC_N))))
#define SC_O     G(C(S(A(KC_O))))
#define SC_P     G(C(S(A(KC_P))))
#define SC_Q     G(C(S(A(KC_Q))))
#define SC_R     G(C(S(A(KC_R))))
#define SC_S     G(C(S(A(KC_S))))
#define SC_T     G(C(S(A(KC_T))))

#define SC_U     G(C(S(A(KC_U))))
#define SC_V     G(C(S(A(KC_V))))
#define SC_W     G(C(S(A(KC_W))))
#define SC_X     G(C(S(A(KC_X))))
#define SC_Y     G(C(S(A(KC_Y))))
#define SC_Z     G(C(S(A(KC_Z))))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Screen| Ctrl | Shift|  Alt |  Cmd |  Spc |  Esc | BSPC | Enter|  En  |  Ja  |  Emo |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    SC_SSC,  KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, L2_SPC,  L3_ESC,  KC_BSPC, KC_ENT,  KC_LNG2, KC_LNG1, SC_EMO
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    _______, _______, _______, _______, _______, _______,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, KC_LBRC, KC_RBRC, _______, _______,
    SC_1,    SC_2,    SC_3,    SC_4,    SC_5,    XXXXXXX,   MO(4),   SC_6,    SC_7,    SC_8,    SC_9,    SC_0
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
    _______, _______, _______, _______, _______, _______,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
    _______, _______, _______, _______, _______, XXXXXXX,   SC_SPOT, _______, KC_LCBR, KC_RCBR, _______, _______,
    SC_A,    SC_B,    SC_C,    SC_D,    SC_E,    MO(4),     XXXXXXX, SC_F,    SC_G,    SC_H,    SC_I,    SC_J
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PWR,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY,   KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SC_SLEP,
    SC_K,    SC_L,    SC_M,    SC_N,    SC_O,    XXXXXXX,   XXXXXXX, SC_P,    SC_Q,    SC_R,    SC_S,    SC_T
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
