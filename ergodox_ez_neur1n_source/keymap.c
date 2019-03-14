#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,LGUI(KC_SPACE),KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_MEH,KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LALT,KC_Z,KC_X,KC_C,KC_V,KC_B,LCA_T(KC_NO),KC_ESCAPE,KC_CAPSLOCK,KC_HOME,KC_END,KC_BSPACE,TG(1),TT(2),LCTL(KC_V),KC_SPACE,KC_DELETE,LCTL(KC_C),KC_MS_BTN3,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSLASH,KC_LBRACKET,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_MINUS,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_EQUAL,KC_RBRACKET,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_QUOTE,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_LGUI,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_PSCREEN,KC_INSERT,KC_LSHIFT,KC_ENTER),

  [1] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,LGUI(KC_SPACE),KC_TAB,KC_QUOTE,KC_COMMA,KC_DOT,KC_P,KC_Y,KC_MEH,KC_LCTRL,KC_A,KC_O,KC_E,KC_U,KC_I,KC_LALT,KC_SCOLON,KC_Q,KC_J,KC_K,KC_X,LCA_T(KC_NO),KC_ESCAPE,KC_CAPSLOCK,KC_HOME,KC_END,KC_BSPACE,KC_TRANSPARENT,TT(2),LCTL(KC_V),KC_SPACE,KC_DELETE,LCTL(KC_C),KC_MS_BTN3,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSLASH,KC_LBRACKET,KC_F,KC_G,KC_C,KC_R,KC_L,KC_MINUS,KC_D,KC_H,KC_T,KC_N,KC_S,KC_EQUAL,KC_RBRACKET,KC_B,KC_M,KC_W,KC_V,KC_Z,KC_SLASH,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_LGUI,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_PSCREEN,KC_INSERT,KC_LSHIFT,KC_ENTER),

  [2] = LAYOUT_ergodox(KC_F11,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RESET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_V),KC_MS_BTN1,KC_MS_BTN2,LCTL(KC_C),KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F12,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_WH_UP,KC_MS_WH_DOWN),

};

bool suspended = false;
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

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
