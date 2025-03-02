/* Copyright 2021 Michał Szczepaniak
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

enum custom_keycodes {
    RELOAD = SAFE_RANGE,
    RESTART
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,               KC_3,    KC_4,  KC_5,
        KC_TAB,  KC_Q,    KC_W,               KC_E,    KC_R,  KC_T,
        KC_ESC,  KC_A,    KC_S,               KC_D,    KC_F,  KC_G,
        KC_LSFT, KC_Z,    KC_X,               KC_C,    KC_V,  KC_B,
        KC_LCTL, KC_LGUI, LCTL(LSFT(KC_GRV)), KC_LALT, MO(1), KC_SPC
    ),
    [1] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_TRNS, KC_F5,   RELOAD,  RESTART, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, NK_TOGG, QK_BOOT, KC_TRNS, KC_TRNS, KC_SPC
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RELOAD:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_F9) SS_DELAY(100) SS_TAP(X_ENT));
        }
        break;
    case RESTART:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_F10) SS_DELAY(100) SS_TAP(X_ENT));
        }
        break;
    }
    return true;
};
