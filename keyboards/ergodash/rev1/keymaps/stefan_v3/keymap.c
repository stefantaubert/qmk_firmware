#include QMK_KEYBOARD_H
#include <sendstring_german.h>
#include <passwords.h>

#define DE_TILDE ALGR(KC_NONUS_BSLASH)

enum {
    BASIS = 0,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
};

enum {
	PW_1 = SAFE_RANGE,
	PW_2,
	PW_3,
	PW_4,
	PW_5,
};

// Layout: http://www.keyboard-layout-editor.com/#/gists/be93346f76d04119b2444437a7243970

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASIS] = LAYOUT( \
        KC_F1,          KC_F2,          KC_F3,          KC_F4,              KC_F5,              KC_F6,                      KC_ESC,                                         KC_MEDIA_PLAY_PAUSE,    KC_F7,              KC_F8,              KC_F9,                  KC_F10,                 KC_F11,                 KC_F12,  \
        KC_SLASH,       KC_K,           KC_U,           KC_LBRACKET,        KC_DOT,             KC_QUOTE,                   KC_AUDIO_VOL_UP,                                KC_MEDIA_NEXT_TRACK,    KC_V,               KC_G,               KC_C,                   KC_L,                   KC_J,                   KC_F,       \
        KC_DEL,         KC_H,           KC_I,           KC_E,               KC_A,               KC_O,                       KC_AUDIO_VOL_DOWN,                              KC_MEDIA_PREV_TRACK,    KC_D,               KC_T,               KC_R,                   KC_N,                   KC_S,                   KC_BSPACE,   \
        KC_TAB,         KC_X,           KC_Z,           KC_SCOLON,          KC_COMMA,           KC_Q,                       XXXXXXX,                                        XXXXXXX,                KC_B,               KC_P,               KC_W,                   KC_M,                   KC_Y,                   KC_MINUS,    \
        KC_LCTRL,       KC_LWIN,        KC_LALT,                            MO(LAYER3),         MO(LAYER1),                 KC_LSHIFT,          KC_SPACE,       KC_ENT,     KC_RSHIFT,              MO(LAYER2),         MO(LAYER4),                                 KC_RALT,                KC_LWIN,                KC_RCTRL    \
    ),

    [LAYER1] = LAYOUT( \
        _______,        _______,        _______,        _______,            _______,            _______,                _______,                                            _______,                _______,            _______,            _______,                _______,                _______,                _______, \
        XXXXXXX,        LCTL(KC_Z),     LCTL(KC_Y),     LCTL(LSFT(KC_C)),   LCTL(LSFT(KC_V)),   XXXXXXX,                XXXXXXX,                                            XXXXXXX,                KC_EXCLAIM,         KC_NONUS_BSLASH,    LSFT(KC_NONUS_BSLASH),  KC_RIGHT_PAREN,         KC_CIRCUMFLEX,          ALGR(KC_E), \
        _______,        LCTL(KC_S),     LCTL(KC_X),     LCTL(KC_C),         LCTL(KC_V),         KC_ENT,                 XXXXXXX,                                            XXXXXXX,                KC_UNDERSCORE,      KC_ASTERISK,        KC_LEFT_PAREN,          KC_SLASH,               KC_RIGHT_ANGLE_BRACKET, _______, \
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,            LCTL(KC_F),         XXXXXXX,                XXXXXXX,                                            _______,                KC_RBRACKET,        KC_PERCENT,         KC_AT,                  LSFT(KC_NONUS_HASH),    KC_LEFT_ANGLE_BRACKET,  ALGR(KC_Q), \
        _______,        _______,        _______,                            _______,            _______,                _______,                _______,        _______,    _______,                _______,            _______,                                    _______,                _______,                _______  \
    ),

    [LAYER2] = LAYOUT( \
        _______,        _______,        _______,        _______,            _______,            _______,                _______,                                            _______,                _______,            _______,            _______,                _______,                _______,                _______, \
        KC_TILDE,       UC(0x2026),     KC_QUESTION,    ALGR(KC_8),         ALGR(KC_9),         KC_GRAVE,               XXXXXXX,                                            XXXXXXX,                XXXXXXX,            XXXXXXX,            XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX, \
        _______,        ALGR(KC_MINUS), KC_AMPERSAND,   ALGR(KC_7),         ALGR(KC_0),         KC_RIGHT_CURLY_BRACE,   XXXXXXX,                                            XXXXXXX,                XXXXXXX,            XXXXXXX,            XXXXXXX,                XXXXXXX,                XXXXXXX,                _______, \
        _______,        KC_NONUS_HASH,  KC_DOLLAR,      DE_TILDE,           ALGR(KC_RBRACKET),  KC_PLUS,                _______,                                            _______,                XXXXXXX,            XXXXXXX,            XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX, \
        _______,        _______,        _______,                            _______,            _______,                _______,                _______,        _______,    _______,                _______,            _______,                                    _______,                _______,                _______  \
    ),

    [LAYER3] = LAYOUT( \
        _______,        _______,        _______,        _______,            _______,            _______,                _______,                                            _______,                _______,            _______,            _______,                _______,                _______,                _______, \
        XXXXXXX,        PW_1,           PW_2,           PW_3,               PW_4,               PW_5,                   RGB_TOG,                                            XXXXXXX,                KC_KP_SLASH,        KC_7,               KC_8,                   KC_9,                   KC_RBRACKET,            KC_SLASH, \
        _______,        RGB_HUI,        RGB_VAI,        RGB_SAI,            BL_INC,             RGB_MOD,                BL_TOGG,                                            XXXXXXX,                KC_KP_ASTERISK,     KC_4,               KC_5,                   KC_6,                   KC_COMMA,               _______, \
        RESET,          RGB_HUD,        RGB_VAD,        RGB_SAD,            BL_DEC,             BL_BRTG,                _______,                                            _______,                KC_RIGHT_PAREN,     KC_1,               KC_2,                   KC_3,                   KC_DOT,                 KC_RIGHT_ANGLE_BRACKET, \
        _______,        _______,        _______,                            _______,            _______,                _______,                _______,        KC_0,       _______,                _______,            _______,                                    _______,                _______,                _______  \
    ),

    [LAYER4] = LAYOUT( \
        _______,        _______,        _______,        _______,            _______,            _______,                _______,                                            _______,                _______,            _______,            _______,                _______,                _______,                _______, \
        XXXXXXX,        XXXXXXX,        KC_PGUP,        KC_UP,              KC_PGDOWN,          XXXXXXX,                XXXXXXX,                                            XXXXXXX,                XXXXXXX,            XXXXXXX,            XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX, \
        _______,        KC_HOME,        KC_LEFT,        KC_DOWN,            KC_RIGHT,           KC_END,                 XXXXXXX,                                            XXXXXXX,                XXXXXXX,            XXXXXXX,            XXXXXXX,                XXXXXXX,                XXXXXXX,                _______, \
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,            XXXXXXX,            XXXXXXX,                _______,                                            _______,                XXXXXXX,            XXXXXXX,            XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX, \
        _______,        _______,        _______,                            _______,            _______,                _______,                _______,        _______,    _______,                _______,            _______,                                    _______,                _______,                _______  \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case PW_1:
				SEND_STRING(PWD1 SS_TAP(X_ENTER));
				break;

			case PW_2:
				SEND_STRING(PWD2 SS_TAP(X_ENTER));
				break;

			case PW_3:
				SEND_STRING(PWD3 SS_TAP(X_ENTER));
				break;

			case PW_4:
				SEND_STRING(PWD4 SS_TAP(X_ENTER));
				break;

			case PW_5:
				SEND_STRING(PWD5 SS_TAP(X_ENTER));
				break;
		}
	}

  	return true;
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
