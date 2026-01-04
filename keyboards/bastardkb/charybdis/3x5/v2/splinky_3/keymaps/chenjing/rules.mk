# 이 파일은 특정 keymap(chenjing)에만 적용되는 QMK 컴파일 옵션입니다.
# 실제 키배치는 VIA에서 관리하며, 여기서는 펌웨어 기능/용량/디버그 옵션을 다룹니다.

# LTO_ENABLE: 링크 타임 최적화. 펌웨어 용량을 줄이고 일부 최적화가 적용됩니다.
# - 장점: 용량 절감(특히 기능 많이 켤 때 유용), 성능/전력 약간 개선
# - 단점: 빌드 시간이 소폭 늘 수 있음, 디버깅 심볼이 줄어듦
LTO_ENABLE = yes

# RGB_MATRIX_ENABLE: RGB Matrix 엔진과 RM_* 키코드 사용(RM_TOGG, RM_NEXT 등).
# - 이 보드는 RGB Matrix를 지원(키보드 레벨 설정)하므로, VIA에서 RGB 페이지를 사용할 수 있습니다.
# - 용량을 아끼고 싶으면 'no'로 끄세요. (RGB 효과/키코드 비활성화)
RGB_MATRIX_ENABLE = yes

# DYNAMIC_TAPPING_TERM_ENABLE: DT_UP/DT_DOWN/DT_PRNT 키코드로 런타임에 TAPPING_TERM 조절.
# - 빠르게 타건/롤링 습관에 맞춰 즉시 값 미세 조정 가능
# - EEPROM 영구 저장은 아니며, 재부팅 시 기본값으로 복귀할 수 있음
DYNAMIC_TAPPING_TERM_ENABLE = yes

# CONSOLE_ENABLE: QMK 콘솔(시리얼) 디버깅 출력. print() 등으로 로그 확인 가능.
# - 디버깅 목적 외에는 끄는 것이 용량/보안 측면에서 유리
CONSOLE_ENABLE = no

# COMMAND_ENABLE: QMK 명령 모드(매트릭스 상태에서 특정 조합으로 진입) 기능.
# - 실사용 중 오작동/혼동을 줄이기 위해 기본 비활성화 권장
COMMAND_ENABLE = no

# VIA_ENABLE: VIA 앱을 통한 동적 키맵/레이어 편집을 활성화.
# - 펌웨어 재빌드 없이 키 변경 가능, 레이어 수는 config.h의 DYNAMIC_KEYMAP_LAYER_COUNT 참고
VIA_ENABLE = yes


# ──────────────────────────────────────────────────────────────────────────────
# 자주 쓰는(선택) 옵션들 — 필요할 때 주석을 해제하고 사용하세요.
# 켜는 옵션이 많을수록 펌웨어 용량이 커집니다.

# NKRO_ENABLE: N-Key Rollover(동시 입력 제한 해제) 활성화.
# - 일부 구형 KVM/OS에서 호환성 이슈가 있을 수 있음
# NKRO_ENABLE = yes

# EXTRAKEY_ENABLE: 시스템/미디어키(볼륨, 재생, 밝기 등) 사용.
# - 대부분 보드 기본값으로 켜져 있으나, 필요 시 강제 지정 가능
# EXTRAKEY_ENABLE = yes

# COMBO_ENABLE: 콤보 입력(두 키 동시 입력으로 별도 키 출력) 기능.
# - 빠른 한글/심볼 입력 등에 유용, 설정은 keymap 코드 또는 VIA로 관리
COMBO_ENABLE = yes

# TAP_DANCE_ENABLE: 탭댄스(같은 키를 탭 횟수/길이에 따라 다른 동작) 기능.
TAP_DANCE_ENABLE = yes

# KEY_OVERRIDE_ENABLE: 특정 조합 시 다른 키로 치환하는 오버라이드 기능.
# KEY_OVERRIDE_ENABLE = yes

# CAPS_WORD_ENABLE: 단어 단위 대문자 입력(토글형) 기능.
CAPS_WORD_ENABLE = yes

# AUTO_SHIFT_ENABLE: 일정 시간 이상 누르면 자동으로 Shift 입력 처리.
# - 롤링/모드탭과의 상호작용을 고려해 신중히 사용
AUTO_SHIFT_ENABLE = yes

# UNICODEMAP_ENABLE: 유니코드 문자 입력(매핑 기반) 기능.
# - OS별 입력 방식 설정 필요(UC_*)
# UNICODEMAP_ENABLE = yes

# DYNAMIC_MACRO_ENABLE: 런타임 매크로 기록/재생(DYN_REC_START 등) 기능.
# DYNAMIC_MACRO_ENABLE = yes

# LEADER_ENABLE: 리더 키 기반 단축 커맨드 기능.
# LEADER_ENABLE = yes

# WPM_ENABLE: 분당 타수(WPM) 계산 기능(표시/조건부 로직에 활용).
# WPM_ENABLE = yes

# MOUSEKEY_ENABLE: 키로 마우스 커서 이동/클릭 제어.
# - 이 보드는 포인팅 디바이스(트랙볼) 사용이 가능하므로 중복될 수 있음
# MOUSEKEY_ENABLE = no

# MOUSE_SHARED_EP: 마우스/키보드 HID 엔드포인트 통합 여부.
# - 일부 호스트/OS 호환성에 영향. 기본값 유지 권장
# MOUSE_SHARED_EP = no

# RGBLIGHT_ENABLE: RGB 라이트(언더글로우) 엔진. RGB Matrix와는 별도 기능.
# - 동시에 켤 필요는 거의 없음. 한 종류만 사용하는 것을 권장
# RGBLIGHT_ENABLE = no


# ─────────────────────────── 포인팅/트랙볼 참고 ───────────────────────────
# 포인팅 디바이스 관련 대부분의 설정은 config.h 매크로로 제어합니다.
# (이 rules.mk에서는 별도 설정이 필요하지 않습니다.)
#
# 자주 쓰는 config.h 매크로 예시:
# - ROTATIONAL_TRANSFORM_ANGLE      : 트랙볼 장착 각도 보정
# - POINTING_DEVICE_INVERT_X/Y     : 포인터 축 반전(오른쪽만은 *_RIGHT)
# - POINTING_DEVICE_ROTATION_90/180/270 : 센서 회전 보정
# - CHARYBDIS_*DPI*                : 기본/스나이핑 DPI 범위/스텝
# - CHARYBDIS_DRAGSCROLL_REVERSE_* : 드래그 스크롤 방향 반전
# - MOUSE_EXTENDED_REPORT          : 큰 이동값 리포트(±32767)
# - CHARYBDIS_CONFIG_SYNC          : 분할 상태 동기화(양쪽 플래시)
# - POINTING_DEVICE_AUTO_MOUSE_*   : 오토 마우스 레이어 설정
