#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

enum custom_keycodes {
    DVOR,
    QWER,
    FUNC,
    MY_QUOT=SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVOR] = LAYOUT_jp(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, JP_COLN, JP_CIRC, JP_YEN, KC_DEL,
        KC_TAB, MY_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SCLN, JP_LBRC,
        LM(QWER, MOD_LCTL), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, JP_RBRC, KC_ENT,
        KC_LSFT, KC_SLSH, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, JP_BSLS, KC_UP, KC_RSFT,
        MO(FUNC), TG(QWER), LM(QWER, MOD_LGUI), KC_LALT, LGUI(KC_SPC), LSFT_T(KC_SPC), KC_ENT, KC_BSPC, KC_RALT, MO(FUNC), KC_LEFT, KC_DOWN, KC_RGHT),
    [QWER] = LAYOUT_jp(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, JP_CIRC, JP_YEN, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, JP_AT, JP_LBRC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, JP_COLN, JP_RBRC, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, JP_BSLS, KC_UP, KC_RSFT,
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

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch(keycode){
        static bool lshift = false;
        static bool rshift = false;
        case MY_QUOT:
            if(record->event.pressed){
                lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
                rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
                if(lshift){
                    register_code(KC_2);
                    unregister_code(KC_2);
                } else if(rshift){
                    register_code(KC_2);
                    unregister_code(KC_2);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_7);
                    unregister_code(KC_7);
                    unregister_code(KC_LSFT);
                }
            }
            return false;
            break;

        case KC_2:
            if(record->event.pressed){
                lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
                rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
                if(lshift){
                    unregister_code(KC_LSFT);
                    register_code(JP_AT);
                    unregister_code(JP_AT);
                    register_code(KC_LSFT);
                } else if(rshift){
                    unregister_code(KC_LSFT);
                    register_code(JP_AT);
                    unregister_code(JP_AT);
                    register_code(KC_LSFT);
                } else {
                    register_code(KC_2);
                    unregister_code(KC_2);
                }
            }
            return false;
            break;

        case KC_0:
            if(record->event.pressed){
                lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
                rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
                if(lshift){
                    register_code(JP_AT);
                    unregister_code(JP_AT);
                } else if(rshift){
                    register_code(JP_AT);
                    unregister_code(JP_AT);
                } else {
                    register_code(KC_0);
                    unregister_code(KC_0);
                }
            }
            return false;
            break;
    }
    return true;
}
