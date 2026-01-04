## Charybdis Nano (3x5) — chenjing 키맵(VIA 중심)

이 키맵은 VIA에서 동적 키맵을 관리하는 전제로 구성되어 있습니다. QMK의 `keymap.c` 내용은 기본 안전값만 유지하고, 실제 키 배치/레이어는 VIA에서 편집하세요.

### 빌드/플래시
- 빌드: `qmk compile -kb bastardkb/charybdis/3x5/v2/splinky_3 -km chenjing`
- 산출물: `.build/bastardkb_charybdis_3x5_v2_splinky_3_chenjing.uf2`
- 플래시: 보드를 부트로더 모드 → UF2 파일 드래그 복사

### VIA 사용(요약)
- VIA 활성화 및 7개 레이어: `DYNAMIC_KEYMAP_LAYER_COUNT 7`
- VID/PID는 VIA `vendorProductId`와 일치하도록 설정됨(0xA8F8:0x1832)
- 플래시 후 VIA가 자동 인식되지 않으면 Design 탭에서 JSON을 수동 로드하세요.

---

## 주요 기능/옵션

### 탭/홀드(기본)
- 현재 설정: `TAPPING_TERM 160`(ms)
- 빠른 연타 안정화: `QUICK_TAP_TERM_PER_KEY` 활성(전역 QUICK_TAP_TERM 미사용)
- 키별 조정 허용: `TAPPING_TERM_PER_KEY`(필요시 `get_tapping_term()`에서 제어)
- 동적 탭핑텀: `DYNAMIC_TAPPING_TERM_ENABLE = yes`, 증분 `5ms`

### 원샷(One Shot)
- `ONESHOT_TIMEOUT 250`: 일정 시간 내 다음 입력 없으면 자동 해제
- `ONESHOT_TAP_TOGGLE 2`: 같은 키 두 번 탭 시 고정(토글)
- VIA에서 `OSM(MOD_*)`, `OSL(layer)` 배치로 활용하세요.

### 롤링 관련(선택 적용)
- 전역 보정은 비활성 유지: `CHORDAL_HOLD`, `FLOW_TAP_TERM`, `HOLD_ON_OTHER_KEY_PRESS_PER_KEY`는 주석 처리(비활성)로 오타 방지.
- 레이어 전환만 즉시 적용: `PERMISSIVE_HOLD_PER_KEY`를 활성화하고 `get_permissive_hold()`에서 `LT(layer, kc)`에만 적용하여, 탭텀 대기 없이 다음 키에 레이어가 바로 반영되도록 설정했습니다.

### USB/폴링
- `USB_POLLING_INTERVAL_MS 1`로 USB 폴링 1ms 고정(기본도 1ms이나 명시)
- 트랙볼 스캔 간격은 키보드 전역에서 1ms로 설정됨

### 포인팅 디바이스(트랙볼)
- 각도 보정: 기본 각도는 키보드 레벨에서 `ROTATIONAL_TRANSFORM_ANGLE -25`입니다. 이 키맵에서는 `-60`으로 재정의되어 있습니다.
- 축 반전: `POINTING_DEVICE_INVERT_X`, `POINTING_DEVICE_INVERT_Y`(오른쪽만: `_RIGHT` 접미사)
- 센서 회전: `POINTING_DEVICE_ROTATION_90/180/270`(오른쪽만: `_RIGHT`)
- DPI 런타임 스케일: 기본/스나이핑 DPI를 런타임에 증감
  - 기본 DPI 스텝(현재): `CHARYBDIS_MINIMUM_DEFAULT_DPI 1600`, `CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200`
  - 스나이핑 DPI 스텝: `CHARYBDIS_MINIMUM_SNIPING_DPI`, `CHARYBDIS_SNIPING_DPI_CONFIG_STEP`
  - VIA 키: `DPI_MOD/DPI_RMOD`, `S_D_MOD/S_D_RMOD`
- 스나이핑 모드: 정밀 제어 모드 ON/OFF
  - VIA 키: `SNIPING`, `SNP_TOG`
- 드래그 스크롤: 볼 스크롤 모드
  - VIA 키: `DRGSCRL`, `DRG_TOG`
  - 방향 반전: `CHARYBDIS_DRAGSCROLL_REVERSE_X/Y`
- 확장 마우스 리포트: `MOUSE_EXTENDED_REPORT`로 큰 포인터 이동값도 끊김 없이 전달
- 설정 동기화(분할): `CHARYBDIS_CONFIG_SYNC`로 좌/우 반쪽 상태 동기화(양쪽 모두 플래시 필요)
- 오토 마우스 레이어(선택): 마우스 동작 시 지정 레이어 자동 활성화
  - `POINTING_DEVICE_AUTO_MOUSE_ENABLE`
  - `AUTO_MOUSE_DEFAULT_LAYER`, `AUTO_MOUSE_TIME`, `AUTO_MOUSE_DELAY/DEBOUNCE/THRESHOLD`

### RGB Matrix
- `RGB_MATRIX_ENABLE = yes`로 RM_* 키코드 사용 가능(`RM_TOGG`, `RM_NEXT`, `RM_PREV`, `RM_HUEU/VALD` 등)
- MCU 용량을 아낄 필요가 있으면 `no`로 꺼도 됩니다.

---

## VIA 배치 팁(예시)
- 엄지에 원샷/레이어/모드 토글 배치: OSM(Shift), OSL(숫자), `SNP_TOG`, `DRG_TOG`
- 포인터 조정: `DPI_MOD/DPI_RMOD`를 좌우 쉬프트 혹은 펑션 레이어에 배치
- RGB: `RM_TOGG`, `RM_NEXT`, `RM_HUEU/D`, `RM_VALU/D`

## 트러블슈팅
- 롤링 시 오타(예→ㅇ메) 발생: 위 롤링 관련 옵션은 비활성 유지 권장. 필요시 `TAPPING_TERM`을 140–200ms 범위에서 단계적으로 조정해 보세요(현재 120ms).
- VIA 키맵 초기화: `EE_CLR`(EEPROM 초기화)나 레이어 수/VID/PID 변경 시 레이아웃이 초기화될 수 있습니다.
