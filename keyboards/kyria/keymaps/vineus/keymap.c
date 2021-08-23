/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include <stdio.h>

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

#define KC_EMOJI LGUI(LCTL(KC_SPC))
#define KC_CLPB LGUI(LSFT(KC_V))
#define KC_EXPO LCTL(KC_UP)
#define KC_NOTIF LALT(KC_QUOT)
#define KC_LOCK LCTL(LGUI(KC_Q))

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Esc/Shft|   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |LShift|Expose|  |Notif |LShift|   N  |   M  | ,  < | . >  | /  ? | Enter  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |ScrSht| GUI  | Alt  |Lower |Space |  | Space| Raise|  `   | Del  | Emoji|
 *                        |      |      |      |      |      |  |      |      | Alt  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      MT(MOD_LSFT, KC_ESC) ,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT(MOD_LSFT, KC_QUOT),
      KC_LCTL,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT,   KC_EXPO,       KC_NOTIF, KC_CLPB, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                              KC_CPYP, KC_LGUI, KC_LOPT, MO(_LOWER), KC_SPC,      KC_SPC, TT(_RAISE), MT(MOD_RALT, KC_GRV),  KC_DEL, KC_EMOJI
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   ~    |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |   )  |   Bksp |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |   _  |  +   |  {   |   }  |   |    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Right|  |  Up  | Down |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |ScrSht|      |      | Clipb|      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_RGHT,   KC_UP, KC_DOWN, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                 KC_CAPP, _______, _______, _______, KC_CLPB, _______, _______, _______, _______, _______
    ),
/*
    * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              |      |   -  |   =  |   [  |   ]  |   \    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn| Left | Right|  |  Up  | Down | MLeft| Mdown| MUp  |MRight|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |      |      |      |  | Lock |      |      |      | Play |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_LEFT, KC_RGHT,   KC_UP, KC_DOWN, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
                                 KC_MUTE, _______, _______, _______, _______, KC_LOCK, _______, _______, _______, KC_MPLY
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef RGBLIGHT_LAYERS

const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 5, HSV_GREEN} );
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS( {15, 5, HSV_RED} );
const rgblight_segment_t PROGMEM my_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_YELLOW} );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_lower_layer,
    my_raise_layer,
    my_shift_layer
);


layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_scan_user(void) {
    uint8_t mods = get_mods();
    rgblight_set_layer_state(2, mods & MOD_MASK_SHIFT);
}

#endif


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_alan_logo(void) {
  static const char PROGMEM alan_logo_1[] = {
    0x40, 0xe0, 0x60, 0x40, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x00, 0x40, 0x60, 0xe0, 0x40
  };
  static const char PROGMEM alan_logo_2[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x19, 0x1b, 0x1b, 0x19, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(alan_logo_1, sizeof(alan_logo_1));
  oled_set_cursor(0, 1);
  oled_write_raw_P(alan_logo_2, sizeof(alan_logo_2));
}

static void render_shift(bool pressed)  {
    static const char PROGMEM shift_icon[] = {
      0x08, 0x0c, 0xf2, 0x81, 0x81, 0xf2, 0x0c, 0x08
    };
    static const char PROGMEM shift_icon_pressed[] = {
      0xf7, 0xf3, 0x05, 0x7e, 0x7e, 0x05, 0xf3, 0xf7
    };
    oled_write_raw_P(pressed ? shift_icon_pressed : shift_icon, 8);
}

static void render_ctrl(bool pressed)  {
    static const char PROGMEM ctrl_icon[] = {
      0x08, 0x04, 0x02, 0x01, 0x01, 0x02, 0x04, 0x08
    };
    static const char PROGMEM ctrl_icon_pressed[] = {
      0xf7, 0xfb, 0xfd, 0xfe, 0xfe, 0xfd, 0xfb, 0xf7
    };
    oled_write_raw_P(pressed ? ctrl_icon_pressed : ctrl_icon, 8);
}

static void render_option(bool pressed)  {
    static const char PROGMEM option_icon[] = {
      0x01, 0x01, 0x03, 0x1c, 0x60, 0x81, 0x81, 0x81
    };
    static const char PROGMEM option_icon_pressed[] = {
      0xfe, 0xfe, 0xfc, 0xe3, 0x9f, 0x7e, 0x7e, 0x7e
    };
    oled_write_raw_P(pressed ? option_icon_pressed : option_icon, 8);
}

static void render_cmd(bool pressed)  {
    static const char PROGMEM cmd_icon[] = {
      0x66, 0xa5, 0xff, 0x24, 0x24, 0xff, 0xa5, 0x66
    };
    static const char PROGMEM cmd_icon_pressed[] = {
      0x99, 0x5a, 0x00, 0xdb, 0xdb, 0x00, 0x5a, 0x99
    };
    oled_write_raw_P(pressed ? cmd_icon_pressed : cmd_icon, 8);
}

static void render_status(void) {
    render_alan_logo();
    oled_set_cursor(4, 1);
    oled_write_P(PSTR("Vineus\n"), false);
    oled_set_cursor(0, 4);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    oled_set_cursor(0, 6);
    uint8_t modifiers = get_mods();

    render_shift(modifiers & MOD_MASK_SHIFT);
    oled_advance_char();
    oled_advance_char();
    render_ctrl(modifiers & MOD_MASK_CTRL);
    oled_advance_char();
    oled_advance_char();
    render_option(modifiers & MOD_MASK_ALT);
    oled_advance_char();
    oled_advance_char();
    render_cmd(modifiers & MOD_MASK_GUI);
}

bool is_mandelbrot_computed = false;
#define MAX_ITERATION 10
#define DEFAULT_POSITION false
void render_mandelbrot(void) {
    if (is_mandelbrot_computed) {
        return;
    }
    double start_x = 0, start_y = 0, zoom = 1;
    if (!DEFAULT_POSITION) {
        start_x = (double) (100 - (rand() % 300)) / 100.0;
        start_y = (double) (100 - (rand() % 300)) / 100.0;
        zoom = (double) (rand() % 100) / 100.0 + 1;
    }
    for (unsigned int y = 0; y < OLED_DISPLAY_HEIGHT; ++y) {
        double p_i = (y - OLED_DISPLAY_HEIGHT / 2.0) / (0.5 * zoom * OLED_DISPLAY_HEIGHT) + start_y;
        for (unsigned int x = 0; x < OLED_DISPLAY_WIDTH; ++x) {
            double p_r = 1.5 * (x - OLED_DISPLAY_WIDTH / 2.0) / (0.5 * zoom * OLED_DISPLAY_WIDTH) + start_x;
            double new_r = 0, new_i = 0, old_r = 0, old_i = 0;
            uint16_t i = 0;
            while ((new_r * new_r + new_i * new_i) < 4.0 && i < MAX_ITERATION) {
                old_r = new_r;
                old_i = new_i;
                new_r = old_r * old_r - old_i * old_i + p_r;
                new_i = 2.0 * old_r * old_i + p_i;
                ++i;
            }
            oled_write_pixel(x, y, i % 2 == 1);
        }
    }
    is_mandelbrot_computed = true;
}

void keyboard_post_init_user(void) {
    srand(TCNT0);
    is_mandelbrot_computed = false;
#ifdef RGBLIGHT_LAYERS
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
#endif
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_mandelbrot();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDN);
                }
            }
            else if (index == 1) {
                if (clockwise) {
                    tap_code16(A(KC_LEFT));
                } else {
                    tap_code16(A(KC_RGHT));
                }
            }
            break;
        case _RAISE:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
            }
            else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_MPRV);
                } else {
                    tap_code(KC_MNXT);
                }
            }
            break;
        default:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
            }
            else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_LEFT);
                } else {
                    tap_code(KC_RIGHT);
                }
            }
    }
}
#endif



