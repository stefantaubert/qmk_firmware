#include QMK_KEYBOARD_H

#define _QWERTY 0

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    KC_A,  KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,                           KC_A,   KC_A,    KC_A,    KC_A,     KC_A,    KC_A,    KC_A, \
    KC_A,  KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,                           KC_A ,  KC_A,    KC_A,    KC_A,     KC_A,    KC_A,    KC_A, \
    KC_A,  KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,                           KC_A,   KC_A,    KC_A,    KC_A,     KC_A,    KC_A,    KC_A, \
    KC_A,  KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,                           KC_A ,  KC_A,    KC_A,    KC_A,     KC_A,    KC_A,    KC_A, \
    KC_A,  KC_A,    KC_A,    KC_A,             KC_A,    KC_A,   KC_A,         KC_A,     KC_A ,  KC_A,             KC_A,     KC_A,    KC_A,    KC_A  \
  ),
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
