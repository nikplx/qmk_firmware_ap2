 /* Copyright 2021 OpenAnnePro community
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

#define LT1(kc) LT(_FN1_LAYER, kc)
#define LT2(kc) LT(_FN2_LAYER, kc)

enum anne_pro_layers {
  _QWERTZ,
  _WORKMAN,
  _GAME,
  _FN1_LAYER,
  _FN2_LAYER,
};

enum custom_keycodes {
    QWERTZ = SAFE_RANGE,
    WORKMAN,
    GAME,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QWERTZ:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTZ);
        }

        return false;
    case WORKMAN:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_WORKMAN);
        }

        return false;
    case GAME:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_GAME);
        }

        return false;
    };

    return true;
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _QWERTZ
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    | R a | L s |  d  |  f  |  g  |  h  |  j  |  k  |  l  | R ; |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*/
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTZ] = LAYOUT( /* Base */
    KC_CAPS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), LT2(KC_A), LT1(KC_S), KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT1(KC_SCLN), KC_QUOT, RCTL_T(KC_ENT),
    KC_LSFT, KC_Y, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT1(KC_LEFT), LT2(KC_DOWN), RCTL_T(KC_RGHT)
),
/*
* Layer _WORKMAN
* ,-----------------------------------------------------------------------------------------.
* | Caps|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  d  |  r  |  w  |  b  |  j  |  f  |  u  |  p  |  ;  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Ctl/Esc | R a | L s |  h  |  t  |  g  |  y  |  n  |  e  |  o  | R i |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  m  |  c  |  v  |  k  |  l  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*/
 [_WORKMAN] = LAYOUT( /* Base */
    KC_CAPS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_J, KC_F, KC_U, KC_P, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), LT2(KC_A), LT1(KC_S), KC_H, KC_T, KC_G, KC_Y, KC_N, KC_E, KC_O, LT1(KC_I), KC_QUOT, RCTL_T(KC_ENT),
    KC_LSFT, KC_Z, KC_X, KC_M, KC_C, KC_V, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT1(KC_LEFT), LT2(KC_DOWN), RCTL_T(KC_RGHT)
),
/*
* Layer _QWERTZ
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |   a |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*/
 [_GAME] = LAYOUT(
    KC_CAPS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, RCTL_T(KC_ENT),
    KC_LSFT, KC_Y, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT1(KC_LEFT), LT2(KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Caps|  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q   | w  |  e  |  r  |  t  |  z  |  ü  |  i  |  ö  | p  |  [  |   ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Ctl/Esc |  ä  |  ß  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  `  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  y  |  b  |  n  |  m  |  ,  |  .  |  ~  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  *
  */ 
 [_FN1_LAYER] = LAYOUT( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______, RALT(KC_Y), _______, RALT(KC_P), _______, _______, _______, _______,
    _______, RALT(KC_Q), RALT(KC_S), KC_DEL, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, KC_GRV, _______,
    _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, _______, KC_TILD, _______,
    _______, _______, _______, _______, _______, _______, MO(_FN2_LAYER), _______
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Caps| BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON|LEINT+| VOL- | VOL+|   Bksp  |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    | QWE |  w  |  e  | WOR |  t  |  z  |  7  |  8  |  9  |  p  | MPREV | MNEXT| PLAY|
  * |-----------------------------------------------------------------------------------------+
  * | Esc    | a   | s  | d   |  f  | GAM |  h  |  4  |  5  |  6  | PGUP | PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  y  |  x  |  c  |  v  |  b  |  n  |  m  |  1  |   2  |  3  |    Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = LAYOUT( /* Base */
    _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_VAI, KC_VOLD, KC_VOLU, _______,
    KC_TAB,  QWERTZ, KC_UP, _______, WORKMAN, _______, _______, KC_7, KC_8, KC_9, _______, KC_MPRV, KC_MNXT, KC_MPLY,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, GAME, _______, KC_4, KC_5, KC_6, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, _______, _______,
    _______, _______, _______, _______, _______, MO(_FN1_LAYER), MO(_FN2_LAYER), _______
 ),
};

const uint16_t keymaps_size = sizeof(keymaps);

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}
 
/**
 * Called after RBG effect render.
 */
void rgb_matrix_indicators_user() {
    switch(get_highest_layer(layer_state|default_layer_state)) {
	case _QWERTZ:
        rgb_matrix_set_color_all(_QWERTZ_COLOR);
	    break;
	case _WORKMAN:
        rgb_matrix_set_color_all(_WORKMAN_COLOR);
	    break;
	case _GAME:
        rgb_matrix_set_color_all(_GAME_COLOR);
	    break;
    case _FN1_LAYER:
        rgb_matrix_set_color_all(_LAYER_1_COLOR); 
        break;
    case _FN2_LAYER:
        rgb_matrix_set_color_all(_LAYER_2_COLOR); 
        break;
    default:
        break;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_ESC, _INDICATOR_COLOR); 
    }
}
