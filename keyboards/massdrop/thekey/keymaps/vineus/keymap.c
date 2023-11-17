#include QMK_KEYBOARD_H

enum layers {
    _COPY_PASTE = 0,
    _NAV,
    _SEARCH,
    _DEBUG,
    _BOOKMARK
};

enum leds {
    _LED_V = 0,
    _LED_RIGHT,
    _LED_LEFT,
    _LED_SO,
    _LED_C
};


#define KC_CLPB G(S(KC_V))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COPY_PASTE] = LAYOUT(TD(0),   G(KC_C),     KC_CLPB),
    [_NAV]        = LAYOUT(TD(0),   G(KC_LBRC),  G(KC_RBRC)),
    [_SEARCH]     = LAYOUT(TD(0),   G(S(KC_G)),  G(KC_G)),
    [_BOOKMARK]   = LAYOUT(TD(0),   A(KC_F3),    A(G(KC_F3))),
    [_DEBUG]      = LAYOUT(TD(0),   KC_F7,       KC_F8)
};

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_OFF);
}

void dance_layers(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count != 1) {
    rgblight_sethsv_noeeprom(HSV_OFF);
  }
  switch (state->count)
  {
      case 1:
        if (state->pressed) {
          rgblight_sethsv_noeeprom(HSV_OFF);
          layer_move(_COPY_PASTE);
        } else {
          tap_code(KC_ESC);
        }
        break;
      case 2:
        rgblight_sethsv_at(HSV_GREEN, _LED_LEFT);
        rgblight_sethsv_at(HSV_GREEN, _LED_RIGHT);
        layer_move(_DEBUG);
        break;
      case 3:
        rgblight_sethsv_at(HSV_PURPLE, _LED_C);
        layer_move(_SEARCH);
        break;
      case 4:
        rgblight_sethsv_at(HSV_YELLOW, _LED_V);
        layer_move(_BOOKMARK);
        break;
      case 5:
        rgblight_sethsv_at(HSV_BLUE, _LED_SO);
        layer_move(_NAV);
        break;
  }
}
qk_tap_dance_action_t tap_dance_actions[] = {
        [0] = ACTION_TAP_DANCE_FN(dance_layers)
};
