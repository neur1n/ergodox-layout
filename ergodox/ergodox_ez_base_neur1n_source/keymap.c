#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"

#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_CAPS,                                        TT(1),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_HOME,                                        KC_END,         KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_QUOTE,
    KC_LEFT_CTRL,   KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_MINUS,
    KC_LEFT_ALT,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LBRC,                                        KC_RBRC,        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_EQUAL,
    KC_ESCAPE,      KC_PAGE_UP,     KC_PGDN,        KC_DELETE,      KC_BSPC,                                                                                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_LEFT_GUI,
                                                                                                    KC_WWW_REFRESH, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
                                                                                                                    KC_PSCR,        KC_INSERT,
                                                                                    KC_SPACE,       KC_LEFT_SHIFT,  KC_PC_COPY,     KC_PC_PASTE,    KC_RIGHT_SHIFT, KC_ENTER
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_F11,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_0,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_TRANSPARENT, KC_NUM,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_ASTERISK, KC_KP_MINUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_DOT,      KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_SLASH,    KC_KP_PLUS,
    KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP
  ),
};








bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  }
  return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    uint8_t layer = biton(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

