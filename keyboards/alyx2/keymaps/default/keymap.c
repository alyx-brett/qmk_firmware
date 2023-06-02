#include QMK_KEYBOARD_H

enum custom_keycodes {
    SAVE_MACRO = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            KC_B,         KC_Y,         KC_O,         KC_U,         KC_L,         KC_D,         KC_W,         KC_V,
            KC_C,         KC_I,         KC_E,         KC_A,         KC_H,         KC_T,         KC_S,         KC_N,
            KC_G,         KC_X,         KC_J,         KC_K,         KC_R,         KC_M,         KC_F,         KC_P,
                                      LT(2,KC_ENT), LSFT_T(KC_SPC),  LT(1,KC_BSPC), LT(3,KC_ESC)),
    [1] = LAYOUT(
            KC_NO,        KC_GRV,       KC_BSLS,      KC_SLSH,        KC_1,       KC_2,         KC_3,         KC_4,
            KC_QUOT,      KC_MINS,      KC_COMM,      KC_DOT,         KC_5,       KC_6,         KC_7,         KC_8,
            KC_EQL,       KC_SCLN,      KC_LBRC,      KC_RBRC,        KC_9,       KC_0,         KC_Z,         KC_Q,
                                        SAVE_MACRO,   LSFT_T(KC_TAB), KC_NO,      KC_NO),
    [2] = LAYOUT(
            KC_NO,        KC_NO,        KC_NO,        KC_NO,         KC_F1,       KC_F2,        KC_F3,        KC_F4,
            KC_HOME,      KC_PGDN,      KC_PGUP,      KC_END,        KC_F5,       KC_F6,        KC_F7,        KC_F8,
            KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,       KC_F9,       KC_F10,       KC_F11,       KC_F12,
                                        KC_NO,        KC_NO,         KC_DEL,      KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SAVE_MACRO:
        if (record->event.pressed) {
            // vim/spacemacs save macro
            SEND_STRING(SS_RSFT(SS_TAP(X_SCLN)) SS_DELAY(50) SS_TAP(X_W) SS_DELAY(50) SS_TAP(X_ENT));
        }
        break;
    }
    return true;
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)){
    case  0:
        tap_code16(clockwise ? KC_WH_U : KC_WH_D);
        break;
    default:
        tap_code16(clockwise ? KC_VOLD : KC_VOLU);
        break;
    }
    return false;
};

const uint16_t PROGMEM lgui_combo[] = {KC_C, KC_B, COMBO_END};
const uint16_t PROGMEM lalt_combo[] = {KC_I, KC_Y, COMBO_END};
const uint16_t PROGMEM lsft_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM lctl_combo[] = {KC_A, KC_U, COMBO_END};
const uint16_t PROGMEM rctl_combo[] = {KC_H, KC_L, COMBO_END};
const uint16_t PROGMEM rsft_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM ralt_combo[] = {KC_S, KC_W, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_N, KC_V, COMBO_END};
const uint16_t PROGMEM larrow_combo[] = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM darrow_combo[] = {KC_I, KC_X, COMBO_END};
const uint16_t PROGMEM uarrow_combo[] = {KC_E, KC_J, COMBO_END};
const uint16_t PROGMEM rarrow_combo[] = {KC_A, KC_K, COMBO_END};
const uint16_t PROGMEM lmouse_combo[] = {LT(2,KC_ENT),   LSFT_T(KC_SPC), COMBO_END};
const uint16_t PROGMEM mmouse_combo[] = {LT(1,KC_BSPC),  LT(3,KC_ESC), COMBO_END};

combo_t key_combos[] = {
    COMBO(lgui_combo, KC_LGUI),
    COMBO(lalt_combo, KC_LALT),
    COMBO(lsft_combo, KC_LSFT),
    COMBO(lctl_combo, KC_LCTL),
    COMBO(rctl_combo, KC_RCTL),
    COMBO(rsft_combo, KC_RSFT),
    COMBO(ralt_combo, KC_LALT),
    COMBO(rgui_combo, KC_RGUI),
    COMBO(larrow_combo, KC_LEFT),
    COMBO(uarrow_combo, KC_UP),
    COMBO(darrow_combo, KC_DOWN),
    COMBO(rarrow_combo, KC_RIGHT),
    COMBO(lmouse_combo, KC_BTN3),
    COMBO(mmouse_combo, KC_BTN3),
};
