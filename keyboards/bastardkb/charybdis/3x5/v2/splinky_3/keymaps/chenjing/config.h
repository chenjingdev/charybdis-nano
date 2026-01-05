#pragma once

// 이 파일은 keymap(chenjing)에 한정된 동작/시간계수를 정의합니다.
// 실제 키배치는 VIA에서 관리합니다. 아래 값은 타건감(탭/홀드)과 보조 기능에만 영향합니다.

// ─────────────────────────── 탭/홀드(기본) ───────────────────────────
// TAPPING_TERM: 탭으로 인식되는 최대 시간(밀리초).
// - 짧을수록 빠른 반응, 길수록 실수 방지. (현재: 160ms)
#define TAPPING_TERM 180
#define AUTO_SHIFT_TIMEOUT 140

// QUICK_TAP_TERM: 홀드 중 짧게 떼도 탭으로 처리하는 유예시간(ms).
// - 0이면 기능 사실상 비활성화. 빠른 연타 탭 유지 위해 150~200ms 권장.
// #define QUICK_TAP_TERM 110
// 퍼키 미세조정 활성화(미구현 시 전역값 사용). get_quick_tap_term()로 제어 가능.
// #define QUICK_TAP_TERM_PER_KEY

// TAPPING_TERM_PER_KEY: 키별로 탭핑텀을 다르게 적용할 수 있게 허용합니다.
// - 구현은 keymap.c의 get_tapping_term()에서 수행됩니다(미구현 시 전역값 사용).
// #define TAPPING_TERM_PER_KEY

// ─────────────────────── 롤링 관련(비활성화 권장) ───────────────────────
// 아래 옵션은 롤링 시(연달아 굴려 누를 때) HOLD를 더 관대하게 판정하는 기능입니다.
// 오타(예→ㅇ메 등) 원인이 될 수 있어 기본 비활성화합니다.
// 강제 비활성화: 상위 레벨에서 켜져 있어도 이 키맵에서는 끕니다.
#undef PERMISSIVE_HOLD
// #define CHORDAL_HOLD        // 반대손 동시 입력 시 즉시 HOLD로 간주
// #define FLOW_TAP_TERM 150   // CHORDAL_HOLD 보조 파라미터(권장 140~170)
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY  // 특정 키만 위 동작 적용
// 레이어 전환 키(LT)를 즉시 활성화하기 위해 퍼키 적용 사용
#define PERMISSIVE_HOLD_PER_KEY

// ───────────────────── 동적 탭핑텀(선택 기능) ─────────────────────
// DT_* 키코드로 런타임에 탭핑텀을 조절할 때의 증분값(ms).
// - rules.mk에서 DYNAMIC_TAPPING_TERM_ENABLE = yes 필요.
#define DYNAMIC_TAPPING_TERM_INCREMENT 5

// ─────────────────────────── 원샷(보조) ───────────────────────────
// ONESHOT_TIMEOUT: 원샷 모드 유지 시간(ms). 너무 길면 의도치 않은 대문자/조합 발생.
// #define ONESHOT_TIMEOUT 250       // 250–400ms 권장
// ONESHOT_TAP_TOGGLE: 같은 키를 n번 탭하면 원샷을 토글(고정)합니다.
// #define ONESHOT_TAP_TOGGLE 2      // 두 번 탭 시 고정

// ────────────────────── VIA 동적 키맵 설정 ──────────────────────
// VIA에서 사용할 수 있는 레이어 수. JSON/키보드 정의와 일치해야 합니다.
#define DYNAMIC_KEYMAP_LAYER_COUNT 7


// ─────────────────────────── 자주 쓰는(선택) ───────────────────────────
// 필요한 경우 주석을 해제해서 사용하세요. (켜면 용량 증가 가능)

// FORCE_NKRO: 부팅 시 NKRO(무한 동시입력)를 기본 활성화.
// - KVM/구형 OS 일부와 호환 이슈가 있을 수 있음.
// #define FORCE_NKRO

// DEBOUNCE: 스위치 채터링(바운스) 억제 시간(ms). 기본값은 보드 설정을 따릅니다.
// - 키 오동작이 느껴지면 5~10 범위에서 조정.
#define DEBOUNCE 8

// RETRO_TAPPING: 탭-앤-홀드 키를 떼는 시점에 탭으로 판정.
// - 롤링 습관에 따라 의도치 않은 탭이 생길 수 있어 기본 비권장.
// 강제 비활성화: 상위 레벨에서 켜져 있어도 이 키맵에서는 끕니다.
#undef RETRO_TAPPING
// 필요 시 퍼키 설정 기능도 함께 차단
#undef RETRO_TAPPING_PER_KEY

// COMBO_TERM: 콤보(두 키 동시) 입력으로 인식되는 최대 시간(ms).
#define COMBO_TERM 30
// Mod/LT 키가 포함된 콤보는 '탭'일 때만 발동하도록 처리(오작동 방지)
#define COMBO_MUST_TAP_PER_COMBO

// CAPS_WORD_IDLE_TIMEOUT: Caps Word 자동 해제 시간(ms). (기능 사용 시)
// #define CAPS_WORD_IDLE_TIMEOUT 5000

// MOUSEKEY 관련 속도/가속 설정 (MouseKey 사용 시에만)
// #define MOUSEKEY_DELAY 16
// #define MOUSEKEY_INTERVAL 16
// #define MOUSEKEY_MAX_SPEED 6
// #define MOUSEKEY_TIME_TO_MAX 64

// ─────────────────────────── USB 폴링 ───────────────────────────
// USB_POLLING_INTERVAL_MS: USB 인터럽트 IN 폴링 간격을 1ms(1kHz)로 고정.
// - QMK 기본도 1ms이지만, 확실히 고정하기 위해 명시합니다.
// - 포인팅 디바이스 폴링(센서 스캔 간격)은 키보드 전역 설정에서 이미 1ms입니다.
#define USB_POLLING_INTERVAL_MS 1

// ─────────────────────── 포인팅/트랙볼(선택) ───────────────────────
// 아래 옵션들은 Charybdis 트랙볼 사용자에게 유용한 선택지입니다.
// 기본값은 키보드 레벨 설정을 따르며, 필요 시 이 파일에서 재정의/추가하세요.

// [각도 보정] 트랙볼 장착각 보정값. 기본은 키보드 레벨에서 -25.
// - 이 키맵에서는 -60도로 재정의하여 더 큰 보정을 적용합니다.
#undef ROTATIONAL_TRANSFORM_ANGLE
#define ROTATIONAL_TRANSFORM_ANGLE -60   // 키맵 수준 보정값(-60°)
#define SPLIT_TAPPING_TERM_ENABLE

// [축 반전] 포인터 축 반전. 기본 구성에서 X축 반전이 활성화되어 있을 수 있습니다.
// - 기본값을 끄려면 먼저 #undef로 해제한 후 재정의하지 마세요.
// #undef POINTING_DEVICE_INVERT_X   // 키보드 레벨 기본을 끄고 싶을 때
// #define POINTING_DEVICE_INVERT_X  // X축 반전 사용(활성화 예시)
// #define POINTING_DEVICE_INVERT_Y  // Y축 반전 사용
// 오른쪽 반쪽만 별도 적용:
// #define POINTING_DEVICE_INVERT_X_RIGHT
// #define POINTING_DEVICE_INVERT_Y_RIGHT

// [센서 회전] 90/180/270도 물리 회전 보정(한 가지만 선택).
// #define POINTING_DEVICE_ROTATION_90
// #define POINTING_DEVICE_ROTATION_180
// #define POINTING_DEVICE_ROTATION_270
// 오른쪽 반쪽만 별도 회전:
// #define POINTING_DEVICE_ROTATION_90_RIGHT
// #define POINTING_DEVICE_ROTATION_180_RIGHT
// #define POINTING_DEVICE_ROTATION_270_RIGHT

// [DPI 런타임 스케일] 기본 DPI 범위/스텝 조정.
// - 기본값(키보드 레벨)은 최저 400DPI입니다.
// - 이 키맵에서는 최저 1600DPI로 상향(기본 대비 4배 빠름), 스텝은 200DPI.
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 1000     // 기본 DPI 최저값(기본 400 → 1600)
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200   // 증감 스텝(단위: DPI)
// [스나이핑 DPI] 스나이핑 모드 DPI 범위/스텝 조정.
//  - 스나이핑(누르고 있는 동안)시 더 빠르게 쓰고 싶다면 기본보다 높은 값으로 설정
#define CHARYBDIS_MINIMUM_SNIPING_DPI 3000
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 200   // 2800, 3000, 3200, 3400

// [드래그 스크롤] 스크롤 방향/감도
// - 방향 반전(수평/수직)
// #define CHARYBDIS_DRAGSCROLL_REVERSE_X
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
// - 감도(버퍼 임계치): 기본 6 → 크게 할수록 스크롤이 느려짐
//   절반 정도로 줄이기 위해 12로 설정
#define CHARYBDIS_DRAGSCROLL_BUFFER_SIZE 12

// [확장 마우스 리포트] 큰 이동값도 끊김 없이(-32767~32767).
// #define MOUSE_EXTENDED_REPORT

// [설정 동기화(분할)] 좌/우 반쪽 상태 동기화(스나이핑/드래그 등).
// - 양쪽 모두 플래시 필요.
// #define CHARYBDIS_CONFIG_SYNC

// [오토 마우스 레이어] 마우스 활동 시 지정 레이어 자동 활성화.
// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #define AUTO_MOUSE_DEFAULT_LAYER 1   // 자동 전환할 레이어 번호
// #define AUTO_MOUSE_TIME 650          // 유지 시간(ms)
// #define AUTO_MOUSE_DELAY 175         // 키 입력 후 딜레이(기본: TAPPING_TERM)
// #define AUTO_MOUSE_DEBOUNCE 25       // 디바운스(ms)
// #define AUTO_MOUSE_THRESHOLD 10      // 민감도(가속 임계치)

// (펌웨어 레벨 포인터 가속 비사용: VIA의 DPI 조정만 사용)

// ───────────────────────── 점프 전용(옵션) ─────────────────────────
// JUMP_BUILD 활성 시 점프 보드의 시리얼 통신 핀을 재정의합니다.
#ifdef JUMP_BUILD
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN GP10
#endif
