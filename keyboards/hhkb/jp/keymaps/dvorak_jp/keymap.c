#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

enum keymap_layer {
    DVOR,
    QWER,
    FUNC,
};

enum custom_keycodes {
    // for Dvorak
    MY_2 = SAFE_RANGE, // 2 @
    MY_6, // 6 &
    MY_7, // 7 '
    MY_8, // 8 (
    MY_9, // 9 )
    MY_0, // 0 `
    MY_CIRC, // ^ ~
    MY_COLN, // : *
    MY_SCLN, // ; +
    MY_MINS, // - =
    MY_BSLS, // \ _
    // for QWERTY
    CS_2, // 2 "
    CS_AT, // @ `
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVOR] = LAYOUT_jp(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, MY_6, MY_7, MY_8, MY_9, MY_0, MY_COLN, MY_CIRC, KC_BSLS, KC_DEL,
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, MY_SCLN, KC_LBRC,
        LM(QWER, MOD_LCTL), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, MY_MINS, KC_RBRC, KC_ENT,
        KC_LSFT, KC_SLSH, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, MY_BSLS, KC_UP, KC_RSFT,
        MO(FUNC), TG(QWER), LM(QWER, MOD_LGUI), KC_LALT, LGUI(KC_SPC), LSFT_T(KC_SPC), KC_ENT, KC_BSPC, KC_RALT, MO(FUNC), KC_LEFT, KC_DOWN, KC_RGHT),
    [QWER] = LAYOUT_jp(
        KC_ESC, KC_1, CS_2, KC_3, KC_4, KC_5, MY_6, MY_7, MY_8, MY_9, MY_0, MY_MINS, MY_CIRC, KC_BSLS, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, CS_AT, KC_LBRC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, MY_SCLN, MY_COLN, KC_RBRC, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MY_BSLS, KC_UP, KC_RSFT,
        MO(FUNC), _______, KC_LGUI, KC_LALT, LGUI(KC_SPC), KC_SPC, KC_ENT, KC_BSPC, KC_RALT, MO(FUNC), KC_LEFT, KC_DOWN, KC_RGHT),

    [FUNC] = LAYOUT_jp(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, KC_PENT,
        _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t macro_id, uint8_t opt)
// {
//     return (const macro_t *)MACRO_NONE;
// }

void tap_cs(uint16_t kc, uint16_t shift_kc) {
    static bool lshift = false;
    static bool rshift = false;
    lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
    rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);

    if (lshift || rshift) {
        uint16_t shift = lshift ? KC_LSFT : KC_RSFT;
        unregister_code(shift);
        tap_code16(shift_kc);
        register_code(shift);
    } else {
        tap_code16(kc);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        switch (keycode)
        {
        // for Dvorak
        case MY_6:
            tap_cs(KC_6, KC_AMPR);
            break;
        case MY_7:
            tap_cs(KC_7, KC_QUOT);
            break;
        case MY_8:
            tap_cs(KC_8, KC_LPRN);
            break;
        case MY_9:
            tap_cs(KC_9, KC_RPRN);
            break;
        case MY_0:
            tap_cs(KC_0, KC_GRAVE);
            break;
        case MY_COLN:
            tap_cs(KC_COLN, KC_PAST);
            break;
        case MY_CIRC:
            tap_cs(KC_CIRC, KC_TILD);
            break;
        case MY_SCLN:
            tap_cs(KC_SCLN, KC_PPLS);
            break;
        case MY_MINS:
            tap_cs(KC_MINS, KC_EQL);
            break;
        case MY_BSLS:
            tap_cs(KC_BSLS, S(KC_MINS));
            break;
        // for QWERTY
        case CS_2:
            tap_cs(KC_2, S(KC_QUOT));
            break;
        case CS_AT:
            tap_cs(KC_AT, KC_GRAVE);
            break;
        default:
            return true;
        }
        return false;
    }
    return true;
}
