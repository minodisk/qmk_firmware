#include QMK_KEYBOARD_H
#include "keymap_jp.h"

enum layers{
    BASE, 
    _RAISE0, 
    _RAISE1, 
};

#define RAISE0 MO(_RAISE0)
#define RAISE1 MO(_RAISE1)
#define CAPT   G(S(C(KC_4)))
#define G_SPC  G(KC_SPC)
#define A_SPC  A(KC_SPC)
#define C_SPC  C(KC_SPC)
#define KAO    G(C(KC_SPC))

/* modify this keymap to customize. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    /* Left */                                                  /* Right */
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
      G_SPC,     KAO, KC_LALT, KC_LGUI,  KC_ESC,  RAISE0,        RAISE1, KC_BSPC,  KC_ENT, KC_LALT,    CAPT,   A_SPC
  ),
  [_RAISE0] = LAYOUT(
    /* Left */                                                  /* Right */
    KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PLUS,
    _______, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),       KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_SCLN, _______,
    _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B),       G(KC_N), G(KC_M), KC_LBRC, KC_RBRC, KC_SLSH, _______,
    KC_WAKE, _______, _______, _______, _______, XXXXXXX,         G_SPC, _______, _______, _______, _______, _______
  ), 
  [_RAISE1] = LAYOUT(
    /* Left */                                                  /* Right */
 A(KC_TILD), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_EQL,
    _______, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),       KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_COLN,  KC_DQT,
    _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B),       G(KC_N), G(KC_M), KC_LCBR, KC_RCBR, KC_QUES, KC_PIPE,
    EEP_RST,   RESET, _______, _______, _______,   A_SPC,       XXXXXXX, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_SLEP
  ), 
};

static bool raise0_pressed = false;
static bool raise1_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RAISE0:
            if (record->event.pressed) {
                raise0_pressed = true;
                layer_on(_RAISE0);
                update_tri_layer(_RAISE0, _RAISE1, BASE);
            } else {
                layer_off(_RAISE0);
                update_tri_layer(_RAISE0, _RAISE1, BASE);
                if (raise0_pressed) {
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
                raise0_pressed = false;
            }
            return false;
            break;
        case RAISE1:
            if (record->event.pressed) {
                raise1_pressed = true;
                layer_on(_RAISE1);
                update_tri_layer(_RAISE0, _RAISE1, BASE);
            } else {
                layer_off(_RAISE1);
                update_tri_layer(_RAISE0, _RAISE1, BASE);
                if (raise1_pressed) {
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
                raise1_pressed = false;
            }
            return false;
            break;
        default :
            if (record->event.pressed) {
                raise0_pressed = false;
                raise1_pressed = false;
            }
            break;
    }
    return true;
}


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
