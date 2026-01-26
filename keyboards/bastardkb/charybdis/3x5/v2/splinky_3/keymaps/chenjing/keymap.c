/********************************************************************************
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// VIA 동적 키맵은 EEPROM에 저장됩니다.
// - 이 배열은 EEPROM 초기화(또는 첫 플래시) 후 기본값으로 사용됩니다.
// - VIA 내보내기 JSON과 동일한 레이아웃을 유지하세요.
#include QMK_KEYBOARD_H

// VIA JSON의 CUSTOM(n) 코드를 키보드 전용 키코드 범위로 매핑합니다.
// (필요 시 QK_USER_0로 변경하세요.)
#ifndef CUSTOM
#    define CUSTOM(n) (QK_KB_0 + (n))
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), KC_G, KC_H, MT(MOD_LSFT, KC_J), MT(MOD_LGUI, KC_K), MT(MOD_LALT, KC_L), MT(MOD_LCTL, KC_QUOT), LT(4, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LT(4, KC_SLSH), LT(3, KC_CAPS), LT(2, KC_SPC), LT(1, KC_TAB), LT(6, KC_ENT), LT(5, KC_BSPC)),
    [1] = LAYOUT(KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_F12, S(KC_8), S(KC_7), S(KC_9), S(KC_0), KC_BSLS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_F11, KC_MINS, S(KC_4), S(KC_5), S(KC_6), KC_SCLN, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_F10, KC_EQL, S(KC_1), S(KC_2), S(KC_3), KC_SLSH, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_BSLS),
    [2] = LAYOUT(KC_GRV, LAG(KC_LEFT), G(KC_T), LAG(KC_RGHT), G(KC_W), KC_PGUP, G(KC_LEFT), KC_UP, G(KC_RGHT), KC_NO, G(KC_A), KC_LALT, KC_LGUI, KC_LSFT, G(KC_F), KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_DEL),
    [3] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, S(KC_8), KC_7, KC_8, KC_9, KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, KC_MINS, KC_4, KC_5, KC_6, KC_SCLN, KC_NO, KC_MS_BTN4, KC_ENT, KC_MS_BTN5, KC_NO, KC_EQL, KC_1, KC_2, KC_3, KC_SLSH, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_P0),
    [4] = LAYOUT(CUSTOM(1), CUSTOM(0), AS_DOWN, AS_RPT, AS_UP, DT_DOWN, DT_PRNT, DT_UP, CUSTOM(3), CUSTOM(2), KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, C(S(G(KC_4))), KC_NO, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS, CUSTOM(6), KC_MS_BTN2, KC_MS_BTN1, LSG(KC_4), KC_NO, KC_MS_BTN1, KC_MS_BTN2, CUSTOM(6), KC_TRNS, CUSTOM(4), KC_MS_BTN3, KC_NO, KC_MS_BTN5, KC_MS_BTN4),
    [5] = LAYOUT(KC_NO, RGB_RMOD, RGB_TOG, RGB_MOD, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F12, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [6] = LAYOUT(S(KC_LBRC), S(KC_7), S(KC_8), S(KC_9), S(KC_RBRC), KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, S(KC_SCLN), S(KC_4), S(KC_5), S(KC_6), S(KC_EQL), KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_BSLS), KC_NO, KC_NO, KC_NO, KC_NO, EE_CLR, S(KC_9), S(KC_0), S(KC_MINS), KC_TRNS, KC_NO),
};

#ifdef TAP_DANCE_ENABLE
// TAP_DANCE_ENABLE 활성화 시 요구되는 심볼. 탭댄스 항목이 없으므로 빈 테이블을 제공합니다.
tap_dance_action_t tap_dance_actions[] = {};
#endif

// (포인터 가속 등 펌웨어 레벨 보정 없음 — VIA로 DPI만 조정)

#ifdef COMBO_ENABLE
// ─────────────────────────── Combos ───────────────────────────
// 요청 (수정):
//  - D + F = Caps Lock
//  - J + K = (
//  - K + L = )
//  - M + , = [
//  - , + . = ]
//
// 주의: 홈로우는 Mod-Tap을 사용하므로 동일한 키코드로 매칭합니다.
//  - S: MT(MOD_LALT, KC_S)
//  - D: MT(MOD_LGUI, KC_D)
//  - F: MT(MOD_LSFT, KC_F)
//  - J: MT(MOD_LSFT, KC_J)
//  - K: MT(MOD_LGUI, KC_K)
//  - L: MT(MOD_LALT, KC_L)
//  - ': MT(MOD_LCTL, KC_QUOT)

enum chenjing_combos {
    DF_CAPS,
    SDF_CW,
    SD_GRV,
    JK_LPRN,
    KL_RPRN,
    JKL_BSLS,
    M_COMM_LBRC,
    COMM_DOT_RBRC,
    L_QUOT_SCLN,
};

// D + F => Caps Lock
const uint16_t PROGMEM df_combo[] = {MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), COMBO_END};

// S + D + F => Caps Word Toggle (3-key chord)
const uint16_t PROGMEM sdf_combo[] = {MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), COMBO_END};
// S(ㄴ) + D(ㅇ) => `
const uint16_t PROGMEM sd_combo[] = {MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), COMBO_END};
// M + , => [    , + . => ]
const uint16_t PROGMEM m_comm_combo[]   = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

// J + K => (   K + L => )
const uint16_t PROGMEM jk_open_combo[]  = {MT(MOD_LSFT, KC_J), MT(MOD_LGUI, KC_K), COMBO_END};
const uint16_t PROGMEM kl_close_combo[] = {MT(MOD_LGUI, KC_K), MT(MOD_LALT, KC_L), COMBO_END};
// J(ㅓ) + K(ㅏ) + L(ㅣ) => \(backslash)
const uint16_t PROGMEM jkl_combo[] = {MT(MOD_LSFT, KC_J), MT(MOD_LGUI, KC_K), MT(MOD_LALT, KC_L), COMBO_END};

// L(ㅣ) + '(Ctrl Mod-Tap apostrophe) => ;(semicolon)
const uint16_t PROGMEM l_quot_combo[] = {MT(MOD_LALT, KC_L), MT(MOD_LCTL, KC_QUOT), COMBO_END};

combo_t key_combos[] = {
    [DF_CAPS] = COMBO(df_combo, KC_CAPS), [SDF_CW] = COMBO(sdf_combo, CW_TOGG), [SD_GRV] = COMBO(sd_combo, KC_GRAVE), [JK_LPRN] = COMBO(jk_open_combo, S(KC_9)), [KL_RPRN] = COMBO(kl_close_combo, S(KC_0)), [JKL_BSLS] = COMBO(jkl_combo, KC_BSLS), [M_COMM_LBRC] = COMBO(m_comm_combo, KC_LBRC), [COMM_DOT_RBRC] = COMBO(comm_dot_combo, KC_RBRC), [L_QUOT_SCLN] = COMBO(l_quot_combo, KC_SCLN),
};

// Mod-Tap이 포함된 콤보는 '탭'일 때만 발동하게 해 오작동을 줄입니다.
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    uint16_t key;
    uint8_t  idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                return true; // 해당 콤보는 두 키 모두 '탭'일 때만 발동
        }
        idx++;
    }
    return false;
}

// (현재 COMBO_ACTION 사용 없음)
#endif // COMBO_ENABLE

// ────────────────────────── Tap-Hold 보정 ──────────────────────────
// 홈로우 쉬프트(Mod-Tap)는 다음 키 입력에 즉시 홀드로 처리합니다.
// - config.h에서 PERMISSIVE_HOLD_PER_KEY가 정의되어 있어야 합니다.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    (void)record;
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        uint8_t  mods   = QK_MOD_TAP_GET_MODS(keycode);
        uint16_t tap_kc = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

        if ((mods & MOD_MASK_SHIFT) && (tap_kc == KC_F || tap_kc == KC_J)) {
            return true;
        }
    }

    return false;
}

#ifdef QUICK_TAP_TERM_PER_KEY
// 홈로우 쉬프트는 연타 직후 홀드가 필요하므로 QUICK_TAP을 비활성화합니다.
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        uint8_t  mods   = QK_MOD_TAP_GET_MODS(keycode);
        uint16_t tap_kc = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

        if ((mods & MOD_MASK_SHIFT) && (tap_kc == KC_F || tap_kc == KC_J)) {
            return 0;
        }
    }

    return QUICK_TAP_TERM;
}
#endif
