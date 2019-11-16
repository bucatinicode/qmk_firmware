#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "bucatini.h"

enum keymap_layer {
  KL_MAIN,
  KL_SUB,
  KL_FN,
  KL_INSTANT_NUMPAD,
  KL_NUMPAD,
  KL_MOUSE,
  KL_JP_MAIN,
  KL_JP_SUB,
  KL_JP_FN,
  KL_JP_INSTANT_NUMPAD,
  KL_JP_SHIFT,
  KL_JP_SUB_SHIFT,
  KL_JP_FN_SHIFT,
  KL_JP_INSTANT_NUMPAD_SHIFT,
  KL_SWITCH,
};

#define LT_SWAP LT(KL_SWITCH, KC_APP)
#define MO_SUB  MO(KL_SUB           )
#define MO_FN   MO(KL_FN            )
#define MO_JSUB MO(KL_JP_SUB        )
#define MO_JFN  MO(KL_JP_FN         )
#define MO_JSFT MO(KL_JP_SHIFT      )
#define DF_MAIN DF(KL_MAIN          )
#define DF_NUM  DF(KL_NUMPAD        )
#define DF_MS   DF(KL_MOUSE         )
#define DF_JP   DF(KL_JP_MAIN       )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Main
   * ,-----------------------------------------------------------------------------------.
   * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  BS  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ESC~ |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    KC_GESC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, MO_FN  , MO_SUB , KC_SPC , KC_SPC , MO_SUB , MO_FN  , KC_RSFT, LT_SWAP, KC_RCTL
  ),

  /* Sub
   * ,-----------------------------------------------------------------------------------.
   * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   `  |PRTSC |SCRLK |PAUSE |      | INS  | LEFT | DOWN |  UP  |RIGHT |   [  |   ]  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      |      |      | DEL  | HOME | PGDN | PGUP | END  |   \  |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_SUB] = LAYOUT_ortho_4x12(
    KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,
    CK_GER , KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, KC_INS , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_LBRC, KC_RBRC,
    _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL , KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Function
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | F13  | F14  | F15  | F16  | F17  | F18  | F19  | F20  | F21  | F22  | F23  | F24  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      | BRI- | BRI+ |      |      | VOL- | VOL+ | MUTE |      |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_FN] = LAYOUT_ortho_4x12(
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 ,
    _______, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Instant Numpad
   * ,-----------------------------------------------------------------------------------.
   * | TAB  |      |      |      |      |      |NUMLK |   7  |   8  |   9  |   /  |   *  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ESC  |      |      |      |      |      |      |   4  |   5  |   6  |   -  |   +  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      |      |      |      |      |   1  |   2  |   3  |ENTER |  BS  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |      |      |    SPACE    |   0  |   =  |   .  |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_INSTANT_NUMPAD] =  LAYOUT_ortho_4x12(
    KC_TAB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PSLS, KC_PAST,
    KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PMNS, KC_PPLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_ENT , KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______, KC_P0  , KC_PEQL, KC_PDOT, _______, _______
  ),

  /* Numpad
   * ,-----------------------------------------------------------------------------------.
   * | TAB  |      |      |      |      |      |NUMLK |   7  |   8  |   9  |   /  |   *  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ESC  |      |      |      |      |      |      |   4  |   5  |   6  |   -  |   +  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      |      |      |      |      |   1  |   2  |   3  |ENTER |  BS  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |      |      |    SPACE    |   0  |   =  |   .  |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_NUMPAD] =  LAYOUT_ortho_4x12(
    KC_TAB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PSLS, KC_PAST,
    KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PMNS, KC_PPLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_ENT , KC_BSPC,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, KC_P0  , KC_PEQL, KC_PDOT, _______, _______
  ),

  /* Mouse
   * ,-----------------------------------------------------------------------------------.
   * | TAB  |      | MS_U |      |      |      |      | BTN4 | BTN5 |      |      |  BS  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ESC  | MS_L | MS_D | MS_R |      |      |      |BTN_L |BTN_M |BTN_R |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      |      |      |      | WH_L | WH_D | WH_U | WH_R |      |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |      |      |    SPACE    | ACL0 | ACL1 | ACL2 |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_MOUSE] =  LAYOUT_ortho_4x12(
    KC_TAB , XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, KC_BSPC,
    KC_ESC , KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, KC_ENT ,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______
  ),

  /* JP Main
   * ,-----------------------------------------------------------------------------------.
   * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  BS  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ESC  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_JP_MAIN] = LAYOUT_ortho_4x12(
    _______, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , JP_SCLN, JP_QUOT,
    MO_JSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , JP_COMM, JP_DOT , JP_SLSH, _______,
    _______, _______, _______, MO_JFN , MO_JSUB, _______, _______, MO_JSUB, MO_JFN , MO_JSFT, _______, _______
  ),

  /* JP Sub
   * ,-----------------------------------------------------------------------------------.
   * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   `  |PRTSC |SCRLK |PAUSE |      | INS  | LEFT | DOWN |  UP  |RIGHT |   [  |   ]  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT | CAPS |      |      |      | DEL  | HOME | PGDN | PGUP | END  |   \  |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_JP_SUB] = LAYOUT_ortho_4x12(
    KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , JP_MINS, JP_EQL ,
    JP_GRV , KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, KC_INS , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, JP_LBRC, JP_RBRC,
    _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL , KC_HOME, KC_PGDN, KC_PGUP, KC_END , JP_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* JP Function
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | F13  | F14  | F15  | F16  | F17  | F18  | F19  | F20  | F21  | F22  | F23  | F24  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      | BRI- | BRI+ |      |      | VOL- | VOL+ | MUTE |      |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_JP_FN] = LAYOUT_ortho_4x12(
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 ,
    _______, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* JP Instant Numpad
   * ,-----------------------------------------------------------------------------------.
   * | TAB  |      |      |      |      |      |NUMLK |   7  |   8  |   9  |   /  |   *  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ESC  |      |      |      |      |      |      |   4  |   5  |   6  |   -  |   +  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      |      |      |      |      |   1  |   2  |   3  |ENTER |  BS  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |      |      |    SPACE    |   0  |   =  |   .  |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_JP_INSTANT_NUMPAD] =  LAYOUT_ortho_4x12(
    KC_TAB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PSLS, KC_PAST,
    KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PMNS, KC_PPLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_ENT , KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______, KC_P0  , KC_PEQL, KC_PDOT, _______, _______
  ),

  /* JP Shift
   * ,-----------------------------------------------------------------------------------.
   * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  BS  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   ~  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_JP_SHIFT] = LAYOUT_ortho_4x12(
    _______, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T)  , S(KC_Y)  , S(KC_U), S(KC_I), S(KC_O), S(KC_P), S(KC_BSPC),
    JP_TILD, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G)  , S(KC_H)  , S(KC_J), S(KC_K), S(KC_L), JP_COLN, JP_DQT    ,
    _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B)  , S(KC_N)  , S(KC_M), JP_LT  , JP_GT  , JP_QUES, _______   ,
    _______, _______, _______, _______, _______, S(KC_SPC), S(KC_SPC), _______, _______, _______, _______, _______
  ),

  /* JP Sub Shift
   * ,-----------------------------------------------------------------------------------.
   * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |   +  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ESC  |PRTSC |SCRLK |PAUSE |      | INS  | LEFT | DOWN |  UP  |RIGHT |   {  |   }  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT | CAPS |      |      |      | DEL  | HOME | PGDN | PGUP | END  |   |  |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_JP_SUB_SHIFT] = LAYOUT_ortho_4x12(
    JP_EXLM  , JP_AT     , JP_HASH   , JP_DLR    , JP_PERC, JP_CIRC  , JP_AMPR   , JP_ASTR   , JP_LPRN   , JP_RPRN   , JP_UNDS, JP_PLUS,
    S(KC_ESC), S(KC_PSCR), S(KC_SLCK), S(KC_PAUS), XXXXXXX, S(KC_INS), S(KC_LEFT), S(KC_DOWN), S(KC_UP)  , S(KC_RGHT), JP_LCBR, JP_RCBR,
    _______  , S(KC_CAPS), XXXXXXX   , XXXXXXX   , XXXXXXX, S(KC_DEL), S(KC_HOME), S(KC_PGDN), S(KC_PGUP), S(KC_END) , JP_PIPE, _______,
    _______  , _______   , _______   , _______   , _______, _______  , _______   , _______   , _______   , _______   , _______, _______
  ),

  /* JP Function Shift
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | F13  | F14  | F15  | F16  | F17  | F18  | F19  | F20  | F21  | F22  | F23  | F24  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      | BRI- | BRI+ |      |      | VOL- | VOL+ | MUTE |      |ENTER |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |  FN  | SUB  |    SPACE    | SUB  |  FN  |SHIFT |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_JP_FN_SHIFT] = LAYOUT_ortho_4x12(
    S(KC_F1 ), S(KC_F2 ), S(KC_F3 ), S(KC_F4 ) , S(KC_F5 ) , S(KC_F6 ), S(KC_F7 ), S(KC_F8 ) , S(KC_F9 ) , S(KC_F10) , S(KC_F11), S(KC_F12),
    S(KC_F13), S(KC_F14), S(KC_F15), S(KC_F16) , S(KC_F17) , S(KC_F18), S(KC_F19), S(KC_F20) , S(KC_F21) , S(KC_F22) , S(KC_F23), S(KC_F24),
    _______,   XXXXXXX  , XXXXXXX  , S(KC_BRID), S(KC_BRIU), XXXXXXX  , XXXXXXX  , S(KC_VOLD), S(KC_VOLU), S(KC_MUTE), XXXXXXX  , _______  ,
    _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______   , _______   , _______   , _______  , _______
  ),

  /* JP Instant Numpad Shift
   * ,-----------------------------------------------------------------------------------.
   * | TAB  |      |      |      |      |      |NUMLK |   7  |   8  |   9  |   /  |   *  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ESC  |      |      |      |      |      |      |   4  |   5  |   6  |   -  |   +  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |SHIFT |      |      |      |      |      |      |   1  |   2  |   3  |ENTER |  BS  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CTRL | GUI  | Alt  |      |      |    SPACE    |   0  |   =  |   .  |SW/APP| CTRL |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_JP_INSTANT_NUMPAD_SHIFT] =  LAYOUT_ortho_4x12(
    S(KC_TAB) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_NLCK), S(KC_P7) , S(KC_P8)  , S(KC_P9)  , (KC_PSLS), S(KC_PAST),
    S(KC_ESC) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , S(KC_P4) , S(KC_P5)  , S(KC_P6)  , (KC_PMNS), S(KC_PPLS),
    _______   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , S(KC_P1) , S(KC_P2)  , S(KC_P3)  , (KC_ENT) , S(KC_BSPC),
    _______   , _______, _______, _______, _______, _______, _______   , S(KC_P0) , S(KC_PEQL), S(KC_PDOT), _______, _______
  ),

  /* Switch
   * ,-----------------------------------------------------------------------------------.
   * |RESET |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  JP  |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      | MAIN | NUM  |MOUSE |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |    MAIN     |      |      |      |APP/SW|      |
   * `-----------------------------------------------------------------------------------'
   */
  [KL_SWITCH] = LAYOUT_ortho_4x12(
    RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF_JP  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF_MAIN, DF_NUM , DF_MS  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF_MAIN, DF_MAIN, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX
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
  state = update_tri_layer_state(state, KL_SUB              , KL_FN      , KL_INSTANT_NUMPAD         );
  state = update_tri_layer_state(state, KL_JP_SUB           , KL_JP_FN   , KL_JP_INSTANT_NUMPAD      );
  state = update_tri_layer_state(state, KL_JP_SUB           , KL_JP_SHIFT, KL_JP_SUB_SHIFT           );
  state = update_tri_layer_state(state, KL_JP_FN            , KL_JP_SHIFT, KL_JP_FN_SHIFT            );
  state = update_tri_layer_state(state, KL_JP_INSTANT_NUMPAD, KL_JP_SHIFT, KL_JP_INSTANT_NUMPAD_SHIFT);
  return state;
}
