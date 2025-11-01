#include QMK_KEYBOARD_H

bool spam_space;
bool spam_rmb;
uint16_t spam_timer = false;
uint16_t spam_interval = 50;
uint16_t spam_rmb_timer = false;
uint16_t spam_rmb_interval = 1600;
bool power_state = false;

enum planck_keycodes {
  KC_SPAMSPACE = SAFE_RANGE,
  KC_SPAMRMB,
  KC_THIS,
  KC_POWER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        // Default
        [0] = LAYOUT_ortho_5x12(
            KC_GRV,  KC_1,    KC_2,               KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
            KC_TAB,  KC_Q,    KC_W,               KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
            KC_ESC,  KC_A,    KC_S,               KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,               KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
            KC_LCTL, KC_LGUI, LCTL(LSFT(KC_GRV)), KC_LALT, MO(4),   KC_SPC,  KC_SPC,  MO(5),   KC_RALT, KC_MPLY, KC_PSCR, KC_ENT
        ),
        // esdf shift
        [1] = LAYOUT_ortho_5x12(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
            KC_TAB,  KC_R,    KC_Q,    KC_W,    KC_E,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
            KC_ESC,  KC_F,    KC_A,    KC_S,    KC_D,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
            KC_LCTL, KC_LGUI, KC_MYCM, KC_LALT, MO(4),   KC_SPC,  KC_SPC,  MO(5),   KC_RALT, KC_MPLY, KC_PSCR, KC_ENT
        ),
        // swtor
        [2] = LAYOUT_ortho_5x12(
            KC_GRV,  KC_1,    KC_2,         KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0, KC_BSPC,
            KC_TAB,  KC_Q,    KC_W,         KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P, KC_DEL,
            KC_ESC,  KC_A,    KC_S,         KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,         KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH, KC_RSFT,
            KC_LCTL, KC_LGUI, KC_SPAMSPACE, KC_LALT, MO(3),   KC_SPC,  KC_SPC,  MO(5),   KC_RALT, KC_SPAMRMB, KC_PSCR, KC_ENT
        ),
        // swtor left layer up
        [3] = LAYOUT_ortho_5x12(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PIPE, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_INS,
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS,
            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_THIS, KC_EQL,  KC_PLUS, KC_PAST, KC_BSLS, KC_TRNS,
            KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  KC_SPC,  MO(6),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
        // default left layer up
        [4] = LAYOUT_ortho_5x12(
            LSA(KC_GRAVE), LSA(KC_1),  LSA(KC_2),  LSA(KC_3),    LSA(KC_4),    LSA(KC_5), KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
            KC_TAB,        KC_LBRC,    KC_RBRC,    KC_LT,        KC_GT,        KC_AMPR,   KC_PIPE, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_INS,
            KC_ESC,        KC_LCBR,    KC_RCBR,    KC_LPRN,      KC_RPRN,      KC_MINS,   KC_UNDS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS,
            KC_LSFT,       C(S(KC_F)), C(S(KC_N)), S(KC_INS),    LALT(KC_INS), KC_DLR,    KC_THIS, KC_EQL,  KC_PLUS, KC_PAST, KC_BSLS, KC_TRNS,
            KC_LCTL,       KC_LGUI,    DF(7),      KC_LALT,      KC_TRNS,      KC_SPC,    KC_SPC,  MO(6),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
        // right layer up
        [5] = LAYOUT_ortho_5x12(
            KC_F1,       KC_F2,       KC_F3,       KC_F4,        KC_F5,        KC_F6,        KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, KC_F18,
            KC_F7,       KC_F8,       KC_F9,       KC_F10,       KC_F11,       KC_F12,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3), LSFT(KC_F4),  LSFT(KC_F5),  LSFT(KC_F6),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            LSFT(KC_F7), LSFT(KC_F8), LSFT(KC_F9), LSFT(KC_F10), LSFT(KC_F11), LSFT(KC_F12), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,      MO(6),        KC_TRNS,      KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS
        ),
        // both layers up
        [6] = LAYOUT_ortho_5x12(
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
            KC_TRNS, QK_BOOT, NK_TOGG, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, DF(0),   DF(2),
            KC_TRNS, KC_POWER, MU_NEXT,  AU_ON,   AU_OFF,   KC_TRNS,  KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, DF(1),   KC_WH_U,
            KC_TRNS, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,   MI_ON,    MI_OFF,  RGB_TOG, KC_BTN3, KC_TRNS, KC_TRNS, KC_WH_D,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
        // left handed
        [7] = LAYOUT_ortho_5x12(
            KC_GRV,  KC_1,    KC_2,               KC_3,    KC_4,    KC_5,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_TAB,  KC_Q,    KC_W,               KC_E,    KC_R,    KC_T,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_ESC,  KC_A,    KC_S,               KC_D,    KC_F,    KC_G,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_LSFT, KC_Z,    KC_X,               KC_C,    KC_V,    KC_B,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_LCTL, KC_LGUI, LCTL(LSFT(KC_GRV)), KC_LALT, MO(9),   LT(8, KC_SPC), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        ),
        // left handed alt
	    [8] = LAYOUT_ortho_5x12(
            KC_BSPC, KC_0,    KC_9,    KC_8,    KC_7,   KC_6,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_DEL,  KC_P,    KC_O,    KC_I,    KC_U,   KC_Y,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_QUOT, KC_SCLN, KC_L,    KC_K,    KC_J,   KC_H,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_RSFT, KC_SLSH, KC_DOT,  KC_COMM, KC_M,   KC_N,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_ENT,  KC_PSCR, KC_MPLY, KC_RALT, KC_NO,  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        ),
        // left handed left layer up
        [9] = LAYOUT_ortho_5x12(
            LSA(KC_GRAVE), LSA(KC_1),  LSA(KC_2),  LSA(KC_3),    LSA(KC_4),    LSA(KC_5), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_TAB,        KC_LBRC,    KC_RBRC,    KC_LT,        KC_GT,        KC_AMPR,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_ESC,        KC_LCBR,    KC_RCBR,    KC_LPRN,      KC_RPRN,      KC_MINS,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_LSFT,       C(S(KC_F)), C(S(KC_N)), S(KC_INS),    LALT(KC_INS), KC_DLR,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_LCTL,       KC_LGUI,    DF(0),      KC_LALT,      KC_TRNS,      KC_SPC,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        ),
        // left handed right layer up
        [10] = LAYOUT_ortho_5x12(
            KC_BSPC, KC_RPRN, KC_LPRN, KC_ASTR, KC_AMPR, KC_CIRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_INS,  KC_PGUP, KC_END,  KC_UP,   KC_HOME, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_PLUS, KC_PGDN, KC_RGHT, KC_DOWN, KC_LEFT, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_ENT,  KC_BSLS, KC_PAST, KC_PLUS, KC_EQL,  KC_THIS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_MNXT, KC_MPRV, KC_VOLU, KC_VOLD, KC_TRNS, KC_SPC,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_SPAMSPACE:
        if (record->event.pressed) {
            spam_space ^= 1;
            spam_timer = timer_read();
        }
        return false;
        break;
    case KC_SPAMRMB:
        if (record->event.pressed) {
            spam_rmb ^= 1;
            spam_rmb_timer = timer_read();
        }
        return false;
        break;
    case KC_THIS:
        if (record->event.pressed) {
            SEND_STRING("$this->");
        }
        return false;
        break;
    case KC_POWER:
        if (record->event.pressed && power_state == false) {
            gpio_set_pin_output(GP15);
            power_state = true;
        } else if (!record->event.pressed && power_state == true) {
            gpio_set_pin_input(GP15);
            power_state = false;
        }
        return false;
        break;
    }

    return true;
}

void matrix_scan_user(void) {
    if (spam_space && timer_elapsed(spam_timer) >= spam_interval) {
         spam_timer = timer_read();
         spam_interval = 50 + (rand() % 50);
         SEND_STRING(SS_TAP(X_SPACE));
    }
    if (spam_rmb && timer_elapsed(spam_rmb_timer) >= spam_rmb_interval) {
         spam_rmb_timer = timer_read();
         SEND_STRING(SS_TAP(X_MS_BTN2));
    }
}
