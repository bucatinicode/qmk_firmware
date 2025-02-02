#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "bucatini.h"

enum keymap_layer {
  KL_BASE,
  KL_BASE_FN,
  KL_NUMPAD,
  KL_NUMPAD_FN,
  KL_MOUSE,
  KL_MOUSE_FN,
  KL_JP,
  KL_JP_FN,
  KL_JP_SHIFT,
  KL_JP_FN_SHIFT,
  KL_SWITCH,
};

#define LT_FNBC LT( KL_BASE_FN  , KC_CAPS)
#define LT_FNNC LT( KL_NUMPAD_FN, KC_CAPS)
#define LT_FNMC LT( KL_MOUSE_FN , KC_CAPS)
#define LT_FNJC LT( KL_JP_FN    , KC_CAPS)
#define LT_SWAP LT( KL_SWITCH   , KC_APP )
#define MO_FNB  MO( KL_BASE_FN  )
#define MO_FNN  MO( KL_NUMPAD_FN)
#define MO_FNM  MO( KL_MOUSE_FN )
#define MO_FNJ  MO( KL_JP_FN    )
#define MO_SFTJ MO( KL_JP_SHIFT )
#define DF_BASE DF( KL_BASE     )
#define DF_NUM  DF( KL_NUMPAD   )
#define DF_MS   DF( KL_MOUSE    )
#define DF_JP   DF( KL_JP       )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap: Base Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |  ESC~  | 1    |  2    |  3    |  4    |  5    |  6    |  7    |  8    |  9    |  0    |  -    |  =    |   BACKSPACE   |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  Q    |  W    |  E    |  R    |  T    |  Y    |  U    |  I    |  O    |  P    |  [    |  ]    |  \        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CAPS/FN    |  A    |  S    |  D    |  F    |  G    |  H    |  J    |  K    |  L    |  ;    |  '    |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |      SHIFT      |  Z    |  X    |  C    |  V    |  B    |  N    |  M    |  ,    |  .    |  /    |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_BASE] = LAYOUT_60_ansi(
    KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,          KC_BSPC,
    KC_TAB ,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
    LT_FNBC,          KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT,
    KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC ,                            KC_RALT, LT_SWAP,          MO_FNB , KC_RCTL
  ),

  /* Keymap: Base Function Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |   `    | F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |     DEL       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  F13  |  F14  |  F15  |  F16  |       | BRI-  | BRI+  |  INS  |       | PRTSC | SCRLK | PAUSE |   PLAY    |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CAPS/FN    |  F17  |  F18  |  F19  |  F20  |       | LEFT  | DOWN  |  UP   | RIGHT | VOL-  | VOL+  |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |      SHIFT      |  F21  |  F22  |  F23  |  F24  |       | HOME  | PGDN  | PGUP  |  END  | MUTE  |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_BASE_FN] = LAYOUT_60_ansi(
    CK_GER , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,          KC_DEL ,
    _______,          KC_F13 , KC_F14 , KC_F15 , KC_F16 , XXXXXXX, KC_BRID, KC_BRIU, KC_INS , XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, KC_MPLY,
    _______,          KC_F17 , KC_F18 , KC_F19 , KC_F20 , XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLD, KC_VOLU, _______,
    _______,          KC_F21 , KC_F22 , KC_F23 , KC_F24 , XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_MUTE,          _______,
    _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
  ),

  /* Keymap: Numpad Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |  ESC   | F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |   BACKSPACE   |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  F13  |  F14  |  F15  |  F16  |       | NUMLK |  P7   |  P8   |  P9   |  P/   |  P*   |  P=   |           |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |   CAPS/FN   |  F17  |  F18  |  F19  |  F20  |       |       |  P4   |  P5   |  P6   |  P-   |  P+   |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |      SHIFT      |  F21  |  F22  |  F23  |  F24  |       |  P0   |  P1   |  P2   |  P3   |  P.   |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_NUMPAD] = LAYOUT_60_ansi(
    KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,          KC_BSPC,
    _______,          KC_F13 , KC_F14 , KC_F15 , KC_F16 , XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PSLS, KC_PAST, KC_PEQL, XXXXXXX,
    LT_FNNC,          KC_F17 , KC_F18 , KC_F19 , KC_F20 , XXXXXXX, XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PMNS, KC_PPLS, _______,
    _______,          KC_F21 , KC_F22 , KC_F23 , KC_F24 , XXXXXXX, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PDOT,          _______,
    _______, _______,          _______,                   _______,                            _______, _______,          MO_FNN , _______
  ),

  /* Keymap: Function Numpad Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |  `     | 1    |  2    |  3    |  4    |  5    |  6    |  7    |  8    |  9    |  0    |  -    |  =    |      DEL      |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  Q    |  W    |  E    |  R    |  T    |  Y    |  U    |  I    |  O    |  P    |  [    |  ]    |  \        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |   CAPS/FN   |  A    |  S    |  D    |  F    |  G    |  H    |  J    |  K    |  L    |  ;    |  '    |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |      SHIFT      |  Z    |  X    |  C    |  V    |  B    |  N    |  M    |  ,    |  .    |  /    |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_NUMPAD_FN] = LAYOUT_60_ansi(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,          KC_DEL ,
    _______,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
    _______,          KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, _______,
    _______,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          _______,
    _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
  ),

  /* Keymap: Mouse Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |  ESC   | F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |   BACKSPACE   |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |       | MS_U  |       |       |       |       | BTN4  | BTN5  |       | ACL0  | ACL1  | ACL2  |           |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |   CAPS/FN   | MS_L  | MS_D  | MS_R  |       |       |       | BTN_L | BTN_M | BTN_R |       |       |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |      SHIFT      |       |       |       |       |       | WH_L  | WH_D  | WH_U  | WH_R  |       |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_MOUSE] = LAYOUT_60_ansi(
    KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,          KC_BSPC,
    _______,          XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,
    LT_FNMC,          KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, _______,
    _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,          _______,
    _______, _______,          _______,                   _______,                            _______, _______,          MO_FNM , _______
  ),

  /* Keymap: Function Mouse Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |  `     | 1    |  2    |  3    |  4    |  5    |  6    |  7    |  8    |  9    |  0    |  -    |  =    |      DEL      |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  Q    |  W    |  E    |  R    |  T    |  Y    |  U    |  I    |  O    |  P    |  [    |  ]    |  \        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CAPS/FN    |  A    |  S    |  D    |  F    |  G    |  H    |  J    |  K    |  L    |  ;    |  '    |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |      SHIFT      |  Z    |  X    |  C    |  V    |  B    |  N    |  M    |  ,    |  .    |  /    |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_MOUSE_FN] = LAYOUT_60_ansi(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,          KC_DEL ,
    _______,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
    _______,          KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, _______,
    _______,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          _______,
    _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
  ),

  /* Keymap: JP Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |  ESC   | 1    |  2    |  3    |  4    |  5    |  6    |  7    |  8    |  9    |  0    |  -    |  =    |   BACKSPACE   |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  Q    |  W    |  E    |  R    |  T    |  Y    |  U    |  I    |  O    |  P    |  [    |  ]    |  \        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CAPS/FN    |  A    |  S    |  D    |  F    |  G    |  H    |  J    |  K    |  L    |  ;    |  '    |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |     FNSHIFT     |  Z    |  X    |  C    |  V    |  B    |  N    |  M    |  ,    |  .    |  /    |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_JP] = LAYOUT_60_ansi(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , JP_MINS, JP_EQL ,          KC_BSPC,
    _______,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , JP_LBRC, JP_RBRC, JP_BSLS,
    LT_FNJC,          KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , JP_SCLN, JP_QUOT, KC_ENT ,
    MO_SFTJ,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , JP_COMM, JP_DOT , JP_SLSH,          MO_SFTJ,
    _______, _______,          _______,                   _______,                            _______, _______,          MO_FNJ , _______
  ),

  /* Keymap: JP Function Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |   `    | F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |     DEL       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  F13  |  F14  |  F15  |  F16  |       | BRI-  | BRI+  |  INS  |       | PRTSC | SCRLK | PAUSE |   PLAY    |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CAPS/FN    |  Z/H  |  MHEN |  HENK |       |       | LEFT  | DOWN  |  UP   | RIGHT | VOL-  | VOL+  |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |      SHIFT      |  EISU |  KANA |       |       |       | HOME  | PGDN  | PGUP  |  END  | MUTE  |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_JP_FN] = LAYOUT_60_ansi(
    JP_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,          KC_DEL ,
    _______,          KC_F13 , KC_F14 , KC_F15 , KC_F16 , XXXXXXX, KC_BRID, KC_BRIU, KC_INS , XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, KC_MPLY,
    _______,          JP_ZHTG, JP_MHEN, JP_HENK, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLD, KC_VOLU, _______,
    _______,          JP_MEISU,JP_MKANA,XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_MUTE,          _______,
    _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
  ),

  /* Keymap: JP Shift Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |   ~    | !    |  @    |  #    |  $    |  %    |  ^    |  &    |  *    |  (    |  )    |  _    |  +    |   BACKSPACE   |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  Q    |  W    |  E    |  R    |  T    |  Y    |  U    |  I    |  O    |  P    |  {    |  }    |  |        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CAPS/FN    |  A    |  S    |  D    |  F    |  G    |  H    |  J    |  K    |  L    |  :    |  "    |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |     FNSHIFT     |  Z    |  X    |  C    |  V    |  B    |  N    |  M    |  <    |  >    |  ?    |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_JP_SHIFT] = LAYOUT_60_ansi(
    JP_TILD, JP_EXLM, JP_AT  , JP_HASH, JP_DLR , JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_UNDS, JP_PLUS,          S(KC_BSPC),
    _______,          S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), JP_LCBR, JP_RCBR, JP_PIPE,
    _______,          S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), JP_COLN, JP_DQT , S(KC_ENT),
    _______,          S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), JP_LT  , JP_GT  , JP_QUES,          _______,
    _______, _______,          _______,                   S(KC_SPC),                          _______, _______,          _______, _______
  ),

  /* Keymap: JP Function Shift Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * |   `    | F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |     DEL       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |    TAB    |  F13  |  F14  |  F15  |  F16  |       | BRI-  | BRI+  |  INS  |       | PRTSC | SCRLK | PAUSE |   PLAY    |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CAPS/FN    |  Z/H  |  MHEN |  HENK |       |       | LEFT  | DOWN  |  UP   | RIGHT | VOL-  | VOL+  |     ENTER       |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |      SHIFT      |  EISU |  KANA |       |       |       | HOME  | PGDN  | PGUP  |  END  | MUTE  |        SHIFT        |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |  CTRL   |   GUI   |   ALT   |                      SPACE                      |   ALT   | APP/SW  |   FN    |  CTRL   |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_JP_FN_SHIFT] = LAYOUT_60_ansi(
    S(KC_ESC), S(KC_F1), S(KC_F2)   , S(KC_F3)   , S(KC_F4)  , S(KC_F5) , S(KC_F6), S(KC_F7)  , S(KC_F8)  , S(KC_F9)  , S(KC_F10) , S(KC_F11) , S(KC_F12) ,             S(KC_DEL),
    _______  ,           S(KC_F13)  , S(KC_F14)  , S(KC_F15) , S(KC_F16), XXXXXXX , S(KC_BRID), S(KC_BRIU), S(KC_INS) , XXXXXXX   , S(KC_PSCR), S(KC_SLCK), S(KC_PAUS), S(KC_MPLY),
    _______  ,           S(JP_ZHTG) , S(JP_MHEN) , S(JP_HENK), XXXXXXX  , XXXXXXX , S(KC_LEFT), S(KC_DOWN), S(KC_UP)  , S(KC_RGHT), S(KC_VOLD), S(KC_VOLU), _______   ,
    _______  ,           S(JP_MEISU), S(JP_MKANA), XXXXXXX   , XXXXXXX  , XXXXXXX , S(KC_HOME), S(KC_PGDN), S(KC_PGUP), S(KC_END) , S(KC_MUTE),             _______   ,
    _______  , _______ ,              _______,                            _______ ,                                     _______   , _______   ,             _______   , _______
  ),

  /* Keymap: Switch Layer
  * ,-----------------------------------------------------------------------------------------------------------------------.
  * | RESET  |      |       |       |       |       |       |       |       |       |       |       |       |               |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |           |       |       |       |       |       |       |       |       |       |       |       |       |           |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |             |       |       |       |       |       |       |  JP   |       |       |       |       |                 |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |                 |       |       |       |       | BASE  |  NUM  | MOUSE |       |       |       |                     |
  * |-----------------------------------------------------------------------------------------------------------------------|
  * |         |         |         |                      BASE                       |         | APP/SW  |         |         |
  * `-----------------------------------------------------------------------------------------------------------------------'
  */
  [KL_SWITCH] = LAYOUT_60_ansi(
    RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF_JP  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF_BASE, DF_NUM , DF_MS  , XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
    XXXXXXX, XXXXXXX,          XXXXXXX,                   DF_BASE,                            XXXXXXX, _______,          XXXXXXX, XXXXXXX
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case CK_GER:
      return process_grave_esc_reverse(keycode, record);
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, KL_JP_FN, KL_JP_SHIFT, KL_JP_FN_SHIFT);
  return state;
}
