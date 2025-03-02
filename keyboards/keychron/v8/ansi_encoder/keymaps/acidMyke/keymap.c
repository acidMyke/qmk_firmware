/* Copyright 2022 @ Keychron (https://www.keychron.com)
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
#include "./password.h"
// clang-format off

// Custom Keycodes
enum {
    SS_PASS_1 = SAFE_RANGE,
    SS_PASS_2,
    SS_PASS_3,
    SS_PASS_4,
    SS_PASS_5,
    SS_PASS_6,
    SS_PASS_7,
    SS_PASS_8,
    SS_PASS_9,
    SS_PASS_0,
};

// Tap dance definitions
enum {
    TD_GRV_TILD,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_GRV_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
};

enum layers{
    __NMT,
    __MT,
    _FN1,
    _FN2,
    _FN3
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// Taps (Mod Tap & Layer Tap)

#define MT_ESC MT(MOD_LCTL, KC_ESC)
#define MT_A MT(MOD_LGUI, KC_A) // Pinky Key
#define MT_S MT(MOD_LALT, KC_S)
#define MT_D MT(MOD_LSFT, KC_D)
#define MT_F MT(MOD_LCTL, KC_F) //Guide Key
#define MT_G MT(MOD_LSFT, KC_G)

#define MT_H MT(MOD_RSFT, KC_H)
#define MT_J MT(MOD_RCTL, KC_J) //Guide Key
#define MT_K MT(MOD_RSFT, KC_K)
#define MT_L MT(MOD_RALT, KC_L)
#define MT_SCLN MT(MOD_RGUI, KC_SCLN) // Pinky Key

#define LT_B LT(_FN3,KC_B)

#define LT_LSPC LT(_FN2, KC_SPC)
#define LT_FN1 LT(_FN1, KC_BSPC) 
#define LT_FN2 LT(_FN2, KC_ENT) 
#define LT_RSPC LT(_FN1, KC_SPC)

// Combos
enum combos {
    FD_TAB,
    JK_BSPC,
    FDS_ENT,
    JKL_DEL,
    VCX_PASTE,
    VC_PASTE,
    CX_COPY,
    XZ_CUT,
    SHIFTED_CAP,
};

const uint16_t PROGMEM fd_combo[] = {MT_F, MT_D, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {MT_J, MT_K, COMBO_END};
const uint16_t PROGMEM fds_combo[] = {MT_F, MT_D, MT_S, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {MT_J, MT_K, MT_L, COMBO_END};

const uint16_t PROGMEM vcx_combo[] = {KC_V, KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM vc_combo[] = {KC_V, KC_C, COMBO_END};
const uint16_t PROGMEM cx_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM xz_combo[] = {KC_X, KC_Z, COMBO_END};

const uint16_t PROGMEM shift_cap_combo[] = {KC_LSFT, MT_ESC, COMBO_END};
combo_t key_combos[] = {
    [FD_TAB] = COMBO(fd_combo, KC_TAB),
    [JK_BSPC] = COMBO(jk_combo, KC_TAB),
    [FDS_ENT] = COMBO(fds_combo, KC_ENT),
    [JKL_DEL] = COMBO(jkl_combo, KC_ENT),
    [VCX_PASTE] = COMBO(vcx_combo, C(S(KC_V))),
    [VC_PASTE] = COMBO(vc_combo, C(KC_V)),
    [CX_COPY] = COMBO(cx_combo, C(KC_C)),
    [XZ_CUT] = COMBO(xz_combo, C(KC_X)),
    [SHIFTED_CAP] = COMBO(shift_cap_combo, KC_CAPS), 
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // disbale combo if layer is __NMT (for game)
    return !layer_state_is(__NMT);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Home row mods disabled
    [__NMT] = LAYOUT_ansi_69(
        KC_GRV,  KC_1,    KC_2,    KC_3, KC_4,   KC_5, KC_6,   KC_7,     KC_8, KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T, KC_Y,   KC_U,     KC_I, KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PSCR,
        KC_ESC,  KC_A,    KC_S,    KC_D, KC_F,   KC_G,         KC_H,     KC_J, KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_DEL,
        KC_LSFT,          KC_Z,    KC_X, KC_C,   KC_V, KC_B,   KC_B,     KC_N, KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT,       KC_SPC,       LT_FN1, LT_FN2,       KC_SPC,          KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT),
    // Home row mods enabled
    [__MT] = LAYOUT_ansi_69(
        KC_GRV,  KC_1,    KC_2,    KC_3, KC_4,    KC_5, KC_6,   KC_7,   KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,    KC_T, KC_Y,   KC_U,   KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_PSCR,
        MT_ESC,  KC_A,    MT_S,    MT_D, MT_F,    MT_G,         MT_H,   MT_J, MT_K,    KC_L,    MT_SCLN, KC_QUOT, KC_ENT,          KC_DEL,
        KC_LSFT,          KC_Z,    KC_X, KC_C,    KC_V, LT_B,   LT_B,   KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        _______, _______, _______,       LT_LSPC,       LT_FN1, LT_FN2,       LT_RSPC,          _______,          KC_LEFT, KC_DOWN, KC_RGHT),
    // Function layer 1 (Home row numbers + F1-12 keys)
    [_FN1] = LAYOUT_ansi_69(
        KC_GRV,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          KC_MPLY,
        KC_TILD, KC_EXLM,  KC_AT,    RGB_HUI,  KC_HASH, KC_DLR,   KC_PERC,  KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,  KC_UNDS,  KC_PLUS,          _______,
        KC_GRV,  KC_1,     KC_2,     KC_3,     KC_4,    KC_5,               KC_6,    KC_7,     KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,           _______,
        _______,           C(KC_Z),  C(KC_X),  C(KC_C), C(KC_V),  C(KC_B),  _______, NK_TOGG,  _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,            KC_SPC,            _______,  _______,           KC_SPC,            _______,            KC_HOME, KC_PGDN,  KC_END),
    // Function layer 2 (VIM Nav & F13-24 keys)
    [_FN2] = LAYOUT_ansi_69(
        KC_GRV,  KC_F13,   KC_F14,   KC_F15,  KC_F16,  KC_F17,  KC_F18,   KC_F19,  KC_F20,  KC_F21,  KC_F22,   KC_F23,   KC_F24,   _______,          C(A(KC_F22)),
        _______, _______,  _______,  _______, _______, _______, _______,  KC_UP,   _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  KC_LALT,  KC_LSFT, KC_LCTL, KC_LSFT,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______,  _______,  _______,          _______,
        _______,           C(KC_Z),  C(KC_X), C(KC_C), C(KC_V), C(KC_B),  _______, _______, _______, KC_DOWN,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           KC_SPC,           _______,  _______,           KC_SPC,           _______,            KC_HOME, KC_PGDN, KC_END),
    // Function layer 3 (F13-24 keys)
    [_FN3] = LAYOUT_ansi_69(
        KC_TILD, SS_PASS_1, SS_PASS_2, SS_PASS_3, SS_PASS_4, SS_PASS_5, SS_PASS_6, SS_PASS_7, SS_PASS_8, SS_PASS_9, SS_PASS_0, RM_SPDD,  RM_SPDU,   _______,         RGB_TOG,
        RM_ON,   RM_NEXT,   RM_HUEU,   RM_SATU,   RM_VALU,   RM_SPDU,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,          _______,
        RM_OFF,  RM_PREV,   RM_HUED,   RM_SATD,   RM_VALD,   RM_SPDD,              _______,   _______,   _______,   _______,   _______,  _______,  _______,          _______,
        _______,            _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______, _______,
        _______, _______,   _______,              _______,              _______,   _______,              _______,              _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [__NMT] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [__MT] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]   = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_FN2]   = {ENCODER_CCW_CW(C(S(KC_F22)), C(KC_F22))},
    [_FN3]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU)}
};
#endif // ENCODER_MAP_ENABLE

// #define DIM_RGB_AZURE       153-80, 245-80, 255-80
// #define DIM_RGB_BLUE        0, 0, 255-80
// #define DIM_RGB_CHARTREUSE  128-80, 255-80, 0
// #define DIM_RGB_CORAL       255-80, 124-80, 77-80
// #define DIM_RGB_CYAN        0, 255-80, 255-80
// #define DIM_RGB_GOLD        255-80, 217-80, 0
// #define DIM_RGB_GOLDENROD   217-80, 165-80, 33-80
// #define DIM_RGB_GREEN       0, 255-80, 0
// #define DIM_RGB_MAGENTA     255-80, 0, 255-80
// #define DIM_RGB_ORANGE      255-80, 128-80, 0
// #define DIM_RGB_PINK        255-80, 128-80, 191-80
// #define DIM_RGB_PURPLE      122-80, 0, 255-80
// #define DIM_RGB_RED         255-80, 0, 0
// #define DIM_RGB_SPRINGGREEN 0, 255-80, 128-80
// #define DIM_RGB_TEAL        0, 128-80, 128-80
// #define DIM_RGB_TURQUOISE   71-80, 110-80, 106-80
// #define DIM_RGB_WHITE       255-80, 255-80, 255-80
// #define DIM_RGB_YELLOW      255-80, 255-80, 0

#define DIM_RGB_AZURE       73, 165, 175
#define DIM_RGB_BLACK       0, 0, 0
#define DIM_RGB_BLUE        0, 0, 175
#define DIM_RGB_CHARTREUSE  48, 175, 0
#define DIM_RGB_CORAL       175, 44, 0
#define DIM_RGB_CYAN        0, 175, 175
#define DIM_RGB_GOLD        175, 137, 0
#define DIM_RGB_GOLDENROD   137, 85, 0
#define DIM_RGB_GREEN       0, 175, 0
#define DIM_RGB_MAGENTA     175, 0, 175
#define DIM_RGB_ORANGE      175, 48, 0
#define DIM_RGB_PINK        175, 38, 95
#define DIM_RGB_PURPLE      42, 0, 175
#define DIM_RGB_RED         175, 0, 0
#define DIM_RGB_SPRINGGREEN 0, 175, 48
#define DIM_RGB_TEAL        0, 48, 48
#define DIM_RGB_TURQUOISE   0, 30, 26
#define DIM_RGB_WHITE       175, 175, 175
#define DIM_RGB_YELLOW      175, 175, 0

bool rgb_matrix_indicators_user() {
    // if (layer_state_is(_FN1)) {
    //     for (int i = 16; i < 28; i++) 
    //         rgb_matrix_set_color(i, DIM_RGB_MAGENTA);
    //     for (int i = 31; i < 41; i++) 
    //         rgb_matrix_set_color(i, DIM_RGB_PINK);
    //     for (int i = 41; i < 43; i++) 
    //         rgb_matrix_set_color(i, DIM_RGB_MAGENTA);
    // } 
    if (layer_state_is(_FN2)) {
        for (int i = 32; i < 36; i++) 
            rgb_matrix_set_color(i, DIM_RGB_SPRINGGREEN);
        for (int i = 36; i < 40; i++) 
            rgb_matrix_set_color(i, DIM_RGB_CORAL);
        rgb_matrix_set_color(22, DIM_RGB_CORAL); // U
        rgb_matrix_set_color(53, DIM_RGB_CORAL); // ,
    } 
    if (!layer_state_cmp(default_layer_state, __NMT)) {
        rgb_matrix_set_color(44, RGB_BLACK);
        rgb_matrix_set_color(58, RGB_BLACK);
        rgb_matrix_set_color(59, RGB_BLACK);
        // rgb_matrix_set_color(60, RGB_BLACK);
        rgb_matrix_set_color(65, RGB_BLACK);
    }
    
    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_A:
        case MT_S:
        case MT_K:
        case MT_L:
            return 300;
        default:
            return TAPPING_TERM;
    }
}

#ifndef PASSWORD_1
#define PASSWORD_1 ""
#endif
#ifndef PASSWORD_2
#define PASSWORD_2 ""
#endif
#ifndef PASSWORD_3
#define PASSWORD_3 ""
#endif
#ifndef PASSWORD_4
#define PASSWORD_4 ""
#endif
#ifndef PASSWORD_5
#define PASSWORD_5 ""
#endif
#ifndef PASSWORD_6
#define PASSWORD_6 ""
#endif
#ifndef PASSWORD_7
#define PASSWORD_7 ""
#endif
#ifndef PASSWORD_8
#define PASSWORD_8 ""
#endif
#ifndef PASSWORD_9
#define PASSWORD_9 ""
#endif
#ifndef PASSWORD_0
#define PASSWORD_0 ""
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_PASS_1:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_1, 17);
                return false;
            }
        case SS_PASS_2:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_2, 17);
                return false;
            }
        case SS_PASS_3:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_3, 17);
                return false;
            }
        case SS_PASS_4:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_4, 17);
                return false;
            }
        case SS_PASS_5:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_5, 17);
                return false;
            }
        case SS_PASS_6:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_6, 17);
                return false;
            }
        case SS_PASS_7:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_7, 17);
                return false;
            }
        case SS_PASS_8:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_8, 17);
                return false;
            }
        case SS_PASS_9:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_9, 17);
                return false;
            }
        case SS_PASS_0:
            if (record->event.pressed) {
                SEND_STRING_DELAY(PASSWORD_0, 17);
                return false;
            }
    }

    return true;
}