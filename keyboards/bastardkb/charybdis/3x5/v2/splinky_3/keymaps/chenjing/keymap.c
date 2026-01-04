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

// Minimal skeleton: VIA manages the actual keymap at runtime.
// - 이 파일의 배열은 플래시 직후 안전한 기본 레이아웃(백업용)만 제공합니다.
// - 실제 사용 레이아웃/레이어는 VIA에서 편집하세요.
#include QMK_KEYBOARD_H

// Single safe fallback layer only; no tap/hold callbacks.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        /* Miryoku (Colemak-DH) style base */
        KC_Q, KC_W, KC_F, KC_P, KC_B,       KC_J, KC_L, KC_U, KC_Y, KC_SCLN,
        KC_A, KC_R, KC_S, KC_T, KC_G,       KC_M, KC_N, KC_E, KC_I, KC_O,
        KC_Z, KC_X, KC_C, KC_D, KC_V,       KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
                            KC_SPC, KC_BSPC, KC_ESC, KC_ENT, QK_BOOT  // QK_BOOT: 부트로더 진입(플래시용)
    ),
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
//  - D: MT(MOD_LGUI, KC_D)
//  - F: MT(MOD_LSFT, KC_F)
//  - J: MT(MOD_LSFT | MOD_RSFT, KC_J)
//  - K: MT(MOD_LGUI | MOD_RGUI, KC_K)
//  - L: LALT_T(KC_L)

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
const uint16_t PROGMEM df_combo[] = { MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), COMBO_END };

// S + D + F => Caps Word Toggle (3-key chord)
const uint16_t PROGMEM sdf_combo[] = { LALT_T(KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), COMBO_END };
// S(ㄴ) + D(ㅇ) => `
const uint16_t PROGMEM sd_combo[]  = { LALT_T(KC_S), MT(MOD_LGUI, KC_D), COMBO_END };
// M + , => [    , + . => ]
const uint16_t PROGMEM m_comm_combo[]   = { KC_M, KC_COMM, COMBO_END };
const uint16_t PROGMEM comm_dot_combo[] = { KC_COMM, KC_DOT, COMBO_END };

// J + K => (   K + L => )
const uint16_t PROGMEM jk_open_combo[]  = { MT(MOD_LSFT | MOD_RSFT, KC_J), MT(MOD_LGUI | MOD_RGUI, KC_K), COMBO_END };
const uint16_t PROGMEM kl_close_combo[] = { MT(MOD_LGUI | MOD_RGUI, KC_K), LALT_T(KC_L), COMBO_END };
// J(ㅓ) + K(ㅏ) + L(ㅣ) => \(backslash)
const uint16_t PROGMEM jkl_combo[]     = { MT(MOD_LSFT | MOD_RSFT, KC_J), MT(MOD_LGUI | MOD_RGUI, KC_K), LALT_T(KC_L), COMBO_END };

// L(ㅣ) + '(Ctrl Mod-Tap apostrophe) => ;(semicolon)
const uint16_t PROGMEM l_quot_combo[]   = { LALT_T(KC_L), MT(MOD_LCTL | MOD_RCTL, KC_QUOT), COMBO_END };

combo_t key_combos[] = {
    [DF_CAPS]          = COMBO(df_combo, KC_CAPS),
    [SDF_CW]           = COMBO(sdf_combo, CW_TOGG),
    [SD_GRV]           = COMBO(sd_combo, KC_GRAVE),
    [JK_LPRN]          = COMBO(jk_open_combo, S(KC_9)),
    [KL_RPRN]          = COMBO(kl_close_combo, S(KC_0)),
    [JKL_BSLS]         = COMBO(jkl_combo, KC_BSLS),
    [M_COMM_LBRC]      = COMBO(m_comm_combo, KC_LBRC),
    [COMM_DOT_RBRC]    = COMBO(comm_dot_combo, KC_RBRC),
    [L_QUOT_SCLN]      = COMBO(l_quot_combo, KC_SCLN),
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
// 레이어 전환 키(LT(layer, kc))는 다음 키 입력에 즉시 적용되도록
// 퍼미시브 홀드를 해당 키들에만 한정해 활성화합니다.
// - 전역 PERMISSIVE_HOLD는 롤링 시 오타를 유발할 수 있어 비활성화 상태 유지
// - config.h에서 PERMISSIVE_HOLD_PER_KEY가 정의되어 있어야 합니다.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // QK_LAYER_TAP 범위: LT(layer, kc) 등 레이어-탭 키
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return true;  // 레이어 전환을 즉시(탭텀 대기 없이) 적용
    }

    // 홈로우 쉬프트(Mod-Tap)는 VIA에서 어떤 쉬프트 조합을 쓰더라도 즉시 홀드 처리합니다.
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        uint8_t  mods   = QK_MOD_TAP_GET_MODS(keycode);
        uint16_t tap_kc = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

        if ((mods & MOD_MASK_SHIFT) && (tap_kc == KC_F || tap_kc == KC_J)) {
            return true;
        }
    }

    return false;
}
