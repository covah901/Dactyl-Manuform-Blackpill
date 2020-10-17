#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
#define _QWERTY 0
#define _FN 2
#define _FN2 3
#define _LOWER 4
#define _RAISE 5
#define _ADJUST 6


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define F_FN2 LT(_FN2, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    F_FN2,   KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT ,
    KC_LCTL, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  FN,      FN,       KC_SPC,   KC_SPC,  RAISE,   KC_LEFT, KC_RGHT,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_DOWN, KC_LEFT,  KC_RGHT,  KC_NO,   KC_NO,   KC_NO,   KC_NO
),

[_LOWER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, S(KC_NUHS), S(KC_NUBS),_______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______,  KC_MNXT, KC_TRNS, KC_VOLU, KC_VOLD,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_A,    KC_B,    KC_MPLY,  KC_MNXT,  KC_NO,   KC_NO,   KC_NO,   KC_NO
),

[_RAISE] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_NUHS,  KC_NUBS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______,  KC_MNXT, KC_TRNS, KC_VOLU, KC_MPLY,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLU, KC_VOLD, KC_A,     KC_B,     KC_NO,   KC_NO,   KC_NO,   KC_NO
),

[_FN] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______,  KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______,  KC_NUHS,  KC_PGUP, KC_PGDN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______,  KC_MNXT, KC_TRNS, KC_VOLU, KC_MPLY,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_PGDN,  KC_PGUP,  KC_NO,   KC_NO,   KC_NO,   KC_NO
),

[_FN2] = LAYOUT(
    _______, _______, _______, _______, _______, KC_NO,   KC_NO,    KC_NO,    KC_UP,   KC_NO,   KC_PSCR, KC_NO,
    _______, _______, _______, _______, _______, _______, KC_NO,    KC_LEFT,  KC_DOWN, KC_RGHT, KC_NO,   KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   _______,
    _______, _______, _______, _______, _______, _______, _______,  _______,  KC_NO,   KC_TRNS, KC_VOLU, KC_VOLD, 
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLU, KC_VOLD, KC_VOLD,  KC_VOLU,  KC_NO,   KC_NO,   KC_NO,   KC_NO
),

[_ADJUST] =  LAYOUT(
    RESET,   RGB_TOG, _______, _______, _______, _______, RGB_TOG,  RGB_MOD,  RGB_RMOD,RGB_M_G, RESET,   _______,
    _______, _______, _______, _______, _______, _______, RGB_HUI,  RGB_SAI,  RGB_VAI, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, RGB_HUD,  RGB_SAD,  RGB_VAD, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_A,    KC_B,    KC_A,     KC_B,     KC_NO,   KC_NO,   KC_NO,   KC_NO
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    switch(get_highest_layer(layer_state)){
      case 0: //Layer 0
        if (!clockwise) { // Remove ! to reverse direction
          tap_code(KC_PGUP);
        } else {
          tap_code(KC_PGDN);
        }
        break;
      case 5: //Layer 4
        if (!clockwise) {
          tap_code(KC_WH_L);
        } else {
          tap_code(KC_WH_R);
        }
        break;
      case 2: //Layer 2
        if (!clockwise) {
          tap_code(KC_PGUP);
        } else {
          tap_code(KC_PGDN);
        }
        break;
      default:
        if (!clockwise) {
          tap_code(KC_PGUP);
        } else {
          tap_code(KC_PGDN);
        }
        break;
    }
  } else if (index == 1) { /* Second encoder */
        switch(get_highest_layer(layer_state)){
      case 0: //Layer 0
        if (!clockwise) { // Remove ! to reverse direction
          tap_code16(C(KC_RGHT));
        } else {
          tap_code16(C(KC_LEFT));
        }
        break;
      case 4: //Layer 4
        if (!clockwise) {
          tap_code(KC_WH_L);
        } else {
          tap_code(KC_WH_R);
        }
        break;
      case 2: //Layer 2
        if (!clockwise) {
          tap_code(KC_PGUP);
        } else {
          tap_code(KC_PGDN);
        }
        break;
      default:
        if (!clockwise) {
          tap_code16(C(KC_RGHT));
        } else {
          tap_code16(C(KC_LEFT));
        }
        break;
    }
  }
}
/* Turns on blue led */
void keyboard_post_init_user(void) {
    setPinOutput(C13);
    writePinLow(C13);
}
