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

// clang-format off

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

#define LT_C LT(_FN1,KC_C)
#define LT_V LT(_FN2,KC_V)
#define LT_B LT(_FN3,KC_B)
#define LT_N LT(_FN2,KC_N)
#define LT_M LT(_FN1,KC_M)

// Combos
enum combos {
    FD_TAB,
    JK_TAB,
    GF_BSPC,
    HJ_BSPC,
    FDS_ENT,
    JKL_ENT,
    GFD_DEL,
    HJK_DEL,
    VCX_PASTE,
    VC_PASTE,
    CX_COPY,
    XZ_CUT,
    SHIFTED_CAP
};

const uint16_t PROGMEM fd_combo[] = {MT_F, MT_D, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {MT_J, MT_K, COMBO_END};
const uint16_t PROGMEM gf_combo[] = {MT_G, MT_F, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {MT_H, MT_J, COMBO_END};
const uint16_t PROGMEM fds_combo[] = {MT_F, MT_D, MT_S, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {MT_J, MT_K, MT_L, COMBO_END};
const uint16_t PROGMEM gfd_combo[] = {MT_G, MT_F, MT_D, COMBO_END};
const uint16_t PROGMEM hjk_combo[] = {MT_H, MT_J, MT_K, COMBO_END};

const uint16_t PROGMEM vcx_combo[] = {LT_V, LT_C, KC_X, COMBO_END};
const uint16_t PROGMEM vc_combo[] = {LT_V, LT_C, COMBO_END};
const uint16_t PROGMEM cx_combo[] = {LT_C, KC_X, COMBO_END};
const uint16_t PROGMEM xz_combo[] = {KC_X, KC_Z, COMBO_END};

const uint16_t PROGMEM shift_cap_combo[] = {KC_LSFT, MT_ESC, COMBO_END};

combo_t key_combos[] = {
    [FD_TAB] = COMBO(fd_combo, KC_TAB),
    [JK_TAB] = COMBO(jk_combo, KC_TAB),
    [GF_BSPC] = COMBO(gf_combo, KC_BSPC),
    [HJ_BSPC] = COMBO(hj_combo, KC_BSPC),
    [FDS_ENT] = COMBO(fds_combo, KC_ENT),
    [JKL_ENT] = COMBO(jkl_combo, KC_ENT),
    [GFD_DEL] = COMBO(gfd_combo, KC_DEL),
    [HJK_DEL] = COMBO(hjk_combo, KC_DEL),
    [VCX_PASTE] = COMBO(vcx_combo, C(S(KC_V))),
    [VC_PASTE] = COMBO(vc_combo, C(KC_V)),
    [CX_COPY] = COMBO(cx_combo, C(KC_C)),
    [XZ_CUT] = COMBO(xz_combo, C(KC_X)),
    [SHIFTED_CAP] = COMBO(shift_cap_combo, KC_CAPS)
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // disbale combo if layer is __NMT (for game)
    return !layer_state_is(__NMT);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Home row mods disabled
    [__NMT] = LAYOUT_ansi_69(
        TD(TD_GRV_TILD), KC_1,    KC_2,    KC_3, KC_4,   KC_5, KC_6,     KC_7,     KC_8, KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MUTE,
        KC_TAB,          KC_Q,    KC_W,    KC_E, KC_R,   KC_T, KC_Y,     KC_U,     KC_I, KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PSCR,
        KC_ESC,          KC_A,    KC_S,    KC_D, KC_F,   KC_G,           KC_H,     KC_J, KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_DEL,
        KC_LSFT,                  KC_Z,    KC_X, KC_C,   KC_V, KC_B,     KC_B,     KC_N, KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL,         KC_LWIN, KC_LALT,       KC_SPC,       MO(_FN1), MO(_FN2),       KC_SPC,          KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT),
    // Home row mods enabled
    [__MT] = LAYOUT_ansi_69(
        TD(TD_GRV_TILD), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_MUTE,
        KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_PSCR,
        MT_ESC,          MT_A,    MT_S,    MT_D,    MT_F,    MT_G,             MT_H,    MT_J,    MT_K,    MT_L,    MT_SCLN, KC_QUOT, KC_ENT,          KC_DEL,
        KC_LSFT,         KC_Z,    KC_X,    LT_C,    LT_V,    LT_B,    LT_B,    LT_N,    LT_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        _______,         _______, _______,          _______,          _______, _______,          _______,          _______, KC_LEFT, KC_DOWN, KC_RGHT),
    // Function layer 1 (Home row numbers + F1-12 keys)
    [_FN1] = LAYOUT_ansi_69(
        KC_GRV,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          KC_MPLY,
        KC_TILD, KC_EXLM,  KC_AT,    RGB_HUI,  KC_HASH, KC_DLR,   KC_PERC,  KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,  KC_UNDS,  KC_PLUS,          _______,
        KC_GRV,  KC_1,     KC_2,     KC_3,     KC_4,    KC_5,               KC_6,    KC_7,     KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,           _______,
        _______,           _______,  _______,  _______, _______,  _______,  _______, NK_TOGG,  _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,            _______,           _______,  _______,           _______,           _______,            KC_HOME, KC_PGDN,  KC_END),
    // Function layer 2 (RGB controls)
    [_FN2] = LAYOUT_ansi_69(
        KC_GRV,  KC_F13,   KC_F14,   KC_F15,  KC_F16,  KC_F17,  KC_F18,   KC_F19,  KC_F20,  KC_F21,  KC_F22,   KC_F23,   KC_F24,   _______,          C(A(KC_F22)),
        _______, _______,  _______,  _______, _______, _______, _______,  KC_UP,   _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  KC_LALT,  KC_LSFT, KC_LCTL, KC_LSFT,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, KC_DOWN, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            KC_HOME, KC_PGDN, KC_END),
    // Function layer 3 (F13-24 keys)
    [_FN3] = LAYOUT_ansi_69(
        KC_TILD, KC_F13,   KC_F14,   KC_F15,  KC_F16,  KC_F17,  KC_F18,   KC_F19,  KC_F20,  KC_F21,  KC_F22,   KC_F23,   KC_F24,   _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [__NMT] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [__MT] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]   = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_FN2]   = {ENCODER_CCW_CW(C(S(KC_F22)), C(KC_F22))},
    [_FN3]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE
