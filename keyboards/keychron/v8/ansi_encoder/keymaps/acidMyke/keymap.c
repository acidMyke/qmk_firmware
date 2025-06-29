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
#include "./colors.h"
#include "./tapdance.h"
#include "./password.h"
// clang-format off

// Custom Keycodes
enum {
    SS_SYSTEM = SAFE_RANGE_AFTER_SS_PASS,
    CTL_F,
    CTL_G,
};

// Tap dance definitions
enum {
    ALT_CLAYER,
    TD_GRV_TILD,
};

bool process_record_password(uint16_t keycode, keyrecord_t *record);
void alt_clayer_finished(tap_dance_state_t *state, void *user_data);
void alt_clayer_reset(tap_dance_state_t *state, void *user_data);

tap_dance_action_t tap_dance_actions[] = {
    [ALT_CLAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_clayer_finished, alt_clayer_reset),
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

/// Home row - mods
#define MT_ESC MT(MOD_LCTL, KC_ESC)

#define MT_S MT(MOD_LALT, KC_S)
#define MT_D MT(MOD_LSFT, KC_D)
#define MT_F MT(MOD_LCTL, KC_F) //Guide Key
#define MT_G MT(MOD_LSFT, KC_G)

#define MT_H MT(MOD_RSFT, KC_H)
#define MT_J MT(MOD_RCTL, KC_J) //Guide Key
#define MT_K MT(MOD_RSFT, KC_K)
#define MT_L MT(MOD_RALT, KC_L)
#define MT_SCLN MT(MOD_RGUI, KC_SCLN) // Pinky Key

#define MT2_F MT(MOD_LCTL, KC_F) //F on _FN2 //Guide Key
#define MT2_G MT(MOD_LSFT, KC_G) //G on _FN2

// Bottom row 
#define LT_B LT(_FN3,KC_B)

#define TD_LALT TD(ALT_CLAYER)
#define LT_LSPC LT(_FN1, KC_SPC)
#define LT_FN1 LT(_FN2, KC_BSPC)
#define LT_FN2 LT(_FN1, KC_ENT) 
#define LT_RSPC LT(_FN2, KC_SPC)


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
    ASD_SYS,
    GRAVE_F1
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
const uint16_t PROGMEM asd_combo[] = {KC_A, MT_S, MT_D, COMBO_END};
const uint16_t PROGMEM grave_f1_combo[] = {KC_GRV, KC_1, COMBO_END};

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
    [ASD_SYS] = COMBO(asd_combo, SS_SYSTEM),
    [GRAVE_F1] = COMBO(grave_f1_combo, KC_F1),
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
        KC_LCTL, KC_LWIN, KC_LALT,       KC_SPC,       LT_FN1, LT_FN2,       KC_SPC,          KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),
    // Home row mods enabled
    [__MT] = LAYOUT_ansi_69(
        KC_GRV,  KC_1,    KC_2,    KC_3, KC_4,    KC_5, KC_6,   KC_7,   KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,    KC_T, KC_Y,   KC_U,   KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PSCR,
        MT_ESC,  KC_A,    MT_S,    MT_D, MT_F,    MT_G,         MT_H,   MT_J, MT_K,    KC_L,    MT_SCLN, KC_QUOT, KC_ENT,           KC_DEL,
        KC_LSFT,          KC_Z,    KC_X, KC_C,    KC_V, LT_B,   LT_B,   KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        _______, _______, TD_LALT,       LT_LSPC,       LT_FN1, LT_FN2,       LT_RSPC,          _______,          KC_LEFT, KC_DOWN, KC_RGHT),
    // Function layer 1 (VIM Nav & F1-12 keys)
    [_FN1] = LAYOUT_ansi_69(
        KC_GRV,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,   _______,          KC_MPLY,
        KC_TAB,  _______,  KC_UP,   _______, _______, _______,  C(KC_Y),  KC_UP,   _______, _______, _______,  _______,  _______,  KC_PLUS,          KC_INS,
        MT_ESC,  KC_LEFT,  KC_DOWN, KC_RGHT, MT_F,    MT_G,               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______,  _______,  KC_EQL,           _______,
        _______,           C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  C(KC_B),  _______, _______, _______, KC_DOWN,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  TD_LALT,          LT_LSPC,           LT_FN1,   LT_FN2,           LT_RSPC,           _______,            KC_HOME, KC_PGDN,  KC_END),
    // Function layer 2 (RTL)
    [_FN2] = LAYOUT_ansi_69(
        KC_GRV,  KC_F1,    KC_F2,   KC_F3,   KC_F4,    KC_F5,      KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,   _______,          C(A(KC_F22)),
        KC_TAB,  _______,  KC_PGUP, _______, _______,  _______,    _______,  KC_PGUP, _______, _______, _______, _______,  _______,  _______,          _______,
        MT_ESC,  KC_HOME,  KC_PGDN, KC_END,  MT_F,     MT_G,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,  _______,  _______,          _______,
        _______,           C(KC_Z), C(KC_X), C(KC_T),  C(S(KC_O)), C(KC_P),  _______, _______, _______, KC_PGDN, _______,  _______,  _______,  KC_PGUP,
        _______, _______,  TD_LALT,          LT_LSPC,              LT_FN1,   LT_FN2,           LT_RSPC,          _______,            KC_HOME, KC_PGDN, KC_END),
    // Function layer 3 (F13-24 keys)
    [_FN3] = LAYOUT_ansi_69(
        KC_TILD, SS_PASS_1, SS_PASS_2, SS_PASS_3, SS_PASS_4, SS_PASS_5, SS_PASS_6, SS_PASS_7, SS_PASS_8, SS_PASS_9, SS_PASS_0, RM_SPDD,  RM_SPDU,  _______,         RGB_TOG,
        RM_ON,   RM_NEXT,   RM_HUEU,   RM_SATU,   RM_VALU,   RM_SPDU,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,          _______,
        RM_OFF,  RM_PREV,   RM_HUED,   RM_SATD,   RM_VALD,   RM_SPDD,              _______,   _______,   _______,   _______,   _______,  _______,  _______,          _______,
        _______,            _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______, _______,
        _______, _______,   TD_LALT,              _______,              _______,   _______,              _______,              _______,            _______, _______, _______)
    // [TEMPLATE] = LAYOUT_ansi_69(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
    //     _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,  _______,  _______,          _______,
    //     _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,
    //     _______, _______, _______,          _______,          _______, _______,          _______,          _______,            _______, _______, _______)
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

bool rgb_matrix_indicators_user() {
    uint8_t layer = biton32(default_layer_state);
    if (layer_state_is(_FN1) || layer == _FN1) {
        rgb_matrix_set_color(34, DIM_RGB_SPRINGGREEN);
        rgb_matrix_set_color(35, DIM_RGB_SPRINGGREEN);
        for (int i = 36; i < 40; i++) 
            rgb_matrix_set_color(i, DIM_RGB_CORAL);
        rgb_matrix_set_color(22, DIM_RGB_CORAL); // U
        rgb_matrix_set_color(53, DIM_RGB_CORAL); // ,
        rgb_matrix_set_color(17, DIM_RGB_CORAL); // W
        rgb_matrix_set_color(31, DIM_RGB_CORAL); // A
        rgb_matrix_set_color(32, DIM_RGB_CORAL); // S
        rgb_matrix_set_color(33, DIM_RGB_CORAL); // D
    }
    
    if (layer_state_is(_FN2) || layer == _FN2) {
        rgb_matrix_set_color(34, DIM_RGB_SPRINGGREEN);
        rgb_matrix_set_color(35, DIM_RGB_SPRINGGREEN);
        for (int i = 36; i < 40; i++) 
            rgb_matrix_set_color(i, DIM_RGB_RED);
        rgb_matrix_set_color(22, DIM_RGB_RED); // U
        rgb_matrix_set_color(53, DIM_RGB_RED); // ,
        rgb_matrix_set_color(17, DIM_RGB_RED); // W
        rgb_matrix_set_color(31, DIM_RGB_RED); // A
        rgb_matrix_set_color(32, DIM_RGB_RED); // S
        rgb_matrix_set_color(33, DIM_RGB_RED); // D

        rgb_matrix_set_color(47, DIM_RGB_MAGENTA); // C
        rgb_matrix_set_color(48, DIM_RGB_MAGENTA); // V
        rgb_matrix_set_color(49, DIM_RGB_MAGENTA); // B 
    }

    if (layer >= __NMT && layer <= _FN3) {
        rgb_matrix_set_color(layer, DIM_RGB_TURQUOISE);
    }
    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_LALT:
            return 100;
    }
    return TAPPING_TERM;
}

static bool inactive_timer_started = false;
static uint16_t inactive_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t current_layer = get_highest_layer(layer_state);

    if (inactive_timer_started) {
        inactive_timer = timer_read();
    }

    if (!process_record_password(keycode, record)) {
        return false;
    }

    if (!record->event.pressed && keycode == SS_SYSTEM) {
        SEND_STRING_DELAY("SYSTEM", 10);
        return false;
    }

    switch (keycode) {
        case SS_SYSTEM: 
            if (!record->event.pressed) {
                SEND_STRING_DELAY("SYSTEM", 10);
                return false;
            }
        break;
        case MT_G:
            if (current_layer == _FN2 && record->tap.count && record->event.pressed) {
                tap_code16(C(KC_G));
                return false;
            }
        break;
        case MT_F:
            if (current_layer == _FN2 && record->tap.count && record->event.pressed) {
                tap_code16(C(KC_F));
                return false;
            }
        break;
        case LT_RSPC:
            if (current_layer == _FN2 && record->tap.count && record->event.pressed) {
                tap_code16(A(KC_SPC));
                return false;
            }
        break;
    }

    return true;
}

static bool is_mod_tap_layer = false;

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        is_mod_tap_layer = active;
        default_layer_set(1UL << (active ? 1 : 0));
    } 
    return false;
}

// ALT CLAYER
static td_tap_t alt_clayer_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void alt_clayer_finished(tap_dance_state_t *state, void *user_data) {
    // // if shift is detected as pressed, by pass everything and hold alt as well
    // if (get_mods() & MOD_BIT(KC_LSFT)) {
    //     register_mods(MOD_BIT(KC_LALT));
    // }

    uint8_t current_default = biton32(default_layer_state);
    uint8_t offset = 0;

    alt_clayer_state.state = cur_dance(state, true);
    switch (alt_clayer_state.state) {
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        
        case TD_TRIPLE_TAP:
            default_layer_set(1UL << 1);
            inactive_timer_started = false;

        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_SINGLE_TAP:
            offset++;
            default_layer_set(1UL << (__MT + ((current_default - __MT + offset) % 2)));
            inactive_timer_started = true;
            inactive_timer = timer_read();
            break;

        default: break;
    }
}

void alt_clayer_reset(tap_dance_state_t *state, void *user_data) {
    unregister_mods(MOD_BIT(KC_LALT));
    alt_clayer_state.state = TD_NONE;
}

void matrix_scan_user(void) {
    if (inactive_timer_started && timer_elapsed(inactive_timer) > 10000) {
        // set it back to default
        default_layer_set(1UL << (is_mod_tap_layer ? 1 : 0));
        inactive_timer_started = false;
    }
}


