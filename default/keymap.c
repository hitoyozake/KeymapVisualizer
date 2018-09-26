#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define DRAW 3 // oekai
#define DRAW2 4
#define DRAW_CTRL_LAYER 6
#define DRAW_CTRL_FILE 7
#define FUNCTION 5 //HHKB FUNC

#define EPRM M(1) // Macro 1: Reset EEPROM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  a L2  |   1  |   2  |   3  |   4  |   5  | 6    |           | ALT  |   7  |   8  |   9  |   0  |   -  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB   |   Q  |   W  |   E  |   R  |   T   |  ALT  |          |  ALT |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ENTER   |   A  |   S  |   D  |   F  |   G |------|           |------|   H  |   J  |   K  |   L  |;     |  ENTER |
 * |--------+------+------+------+------+------|MO(FNC)|          | Mouse|------+------+------+------+------+--------|
 * | SHIFT    |   Z  |   X  |   C  |   V  |   B  |      |                  |   N  |   M  |   ,  |   .  | / | SIHFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L1    |  DEL | WIN  | ALT  |MO(FNC)|                                      |MO(FNC)| UP |   [  |   ]  | '" |
 *   `----------------------------------'                                       `-------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | L1   |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |BcSpc | Home |       | PgUp |        |      |
 *                                 | Space|      |------|       |------| Enter  |Space |
 *                                 | Ctrl |/Shift| `~   |       | IME  |  /Shift| /Ctrl|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] =KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,           KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,       KC_Q,          KC_W,   KC_E,   KC_R,   KC_T,   TG(DRAW),
        KC_ENT,       KC_A,          KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_PGUP,
        KC_LGUI, KC_ESC, KC_LGUI,  KC_LALT,MO(FUNCTION),
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              TG(SYMB),
                                     CTL_T(KC_SPC),SFT_T(KC_BSPC),KC_GRV,
        // right hand
             KC_LALT,   KC_7,   KC_8,   KC_9,   KC_0,  KC_MINS,  KC_EQL,
             KC_LALT ,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_ENT,
             KC_PGDN,    KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_LSFT,
                          MO(FUNCTION),  KC_UP,TG(SYMB),KC_RBRC,           KC_QUOT,
             TG(SYMB),        CTL_T(KC_ESC),
             TG(DRAW),
             KC_LALT, SFT_T(KC_ENT), CTL_T(KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |  F6    |         |      |  F7  |  F8  |  F9  |  F10 | F11  |  F12      |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |TWEETY      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          KC_TRNS,RESET,EPRM,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      | volup|voldown|mute|      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      | WhD  |MsUp  |  WhU |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |     |      |      | Lclk | Rclk |                                       |leftclck| rightclick | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_WH_D, KC_MS_U, KC_WH_U, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_BTN1, KC_BTN2, KC_TRNS,KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: Oekaki and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      | save |選択解除|再選択|      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |   Y  |  U   | I    |  O   |  P   |DRAW_CTRL|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|   H  |  J   |  K   |  L   |      |DRAW_CTRL|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  N   |  M   | ,    | .    |CTRL(/)| MO(DRAW2)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |     |      |      | Lclk | Rclk |                                        |Lclk  |Rclk | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// DRAW MAP OEKAKI
[DRAW] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,       KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_ENT,       KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_LSFT,       KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   MO(FUNCTION),
        KC_TRNS, KC_ESC, KC_LGUI,  KC_LALT,MO(FUNCTION),
                                              KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                               CTL_T(KC_SPC),SFT_T(KC_BSPC),KC_GRV,
        // right hand
             KC_LALT,   KC_7,   KC_8,   KC_9,   KC_0,  KC_MINS,  KC_EQL,
             KC_LALT ,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             MO(DRAW_CTRL_LAYER),
                          KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),MO(DRAW_CTRL_FILE),
             TG(MDIA),    KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   MO(DRAW2),
                          MO(FUNCTION),  KC_UP,TG(SYMB),KC_RBRC,           KC_QUOT,
             TG(SYMB),        CTL_T(KC_ESC),
             KC_PGDN,
             LALT(KC_GRV), KC_ENT, KC_BSPC
    ),

/* Keymap 3: OEKAKI DRAW 右手にqwertyの左手部分を持ってきた
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |   Q  | w    |  E   |  R   |   T  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|   A  |  S   |  D   |  F   |   G  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   Z  |  X   | C(レイヤ複製) |  V   |  B   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |     |      |      | Lclk | Rclk |                                       | save(c-s)|up |      |      | '    |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[DRAW2] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,       KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_ENT,       KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_LSFT,       KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_ESC, KC_LGUI,  KC_LALT,MO(FUNCTION),
                                              KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                               CTL_T(KC_SPC),SFT_T(KC_BSPC),KC_GRV,
        // right hand
             KC_LALT,   KC_1,   KC_2,   KC_3,   KC_4,  KC_5,  KC_6,
             KC_LALT ,   KC_Q,   KC_W,   KC_R,   KC_T,   KC_Y,  KC_BSLS,
                          KC_A,   KC_S,   KC_D,   KC_F,   KC_G, KC_TRNS,
             TG(MDIA),    KC_Z,   KC_X,   KC_C,KC_V, KC_B,   KC_TRNS,
                          LCTL(KC_S),  KC_UP,TG(SYMB),KC_RBRC,           KC_QUOT,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //保存系
[DRAW_CTRL_FILE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,       KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_ENT,       KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_LSFT,       KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_ESC, KC_LGUI,  KC_LALT,MO(FUNCTION),
                                              KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                               CTL_T(KC_SPC),SFT_T(KC_BSPC),KC_GRV,
        // right hand
             KC_LALT,   KC_1,   KC_2,   KC_3,   KC_4,  KC_5,  KC_6,
             KC_LALT ,   KC_Q,   KC_W,   KC_R,   KC_T,   KC_Y,  KC_BSLS,
                          KC_A,   LCTL(KC_S),   KC_D,   KC_F,   KC_G, KC_TRNS,
             TG(MDIA),    KC_Z,   KC_X,   KC_C,KC_V, KC_B,   KC_TRNS,
                          LCTL(KC_S),  KC_UP,TG(SYMB),KC_RBRC,           KC_QUOT,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
    ),
 [DRAW_CTRL_LAYER] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,       KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_ENT,       KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_LSFT,       KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_ESC, KC_LGUI,  KC_LALT,MO(FUNCTION),
                                              KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                               CTL_T(KC_SPC),SFT_T(KC_BSPC),KC_GRV,
        // right hand
             KC_LALT,   KC_1,   KC_2,   KC_3,   KC_4,  KC_5,  KC_6,
             KC_LALT ,   KC_Q,   KC_W,   KC_R,   KC_T,   KC_Y,  KC_BSLS,
                          KC_A,   LCTL(KC_S),   KC_D,   KC_F,   KC_G, KC_TRNS,
             TG(MDIA),    KC_Z,   KC_X,   KC_C,KC_V, KC_B,   KC_TRNS,
                          LCTL(KC_S),  KC_UP,TG(SYMB),KC_RBRC,           KC_QUOT,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
    ),
 
 /* Keymap 3: SUB BASE LAYER(momentary)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  2    |  3  | 4     |  5  |   6  |           |      |   F7 |  F8  |  9    |F10  | F11  | F12    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |clickL| MsUp |clickR|      |      |           |      | (    |  )  |   UP |  [   |   ]  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | `~   |MsLeft|MsDown|MsRght|TAB   |------|           |------|    * |Left  |Down  | Rght |  '"  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      | IME  |      |      |           |      |   &  | IME  |  -   |   =  |      |  `~    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |     |      |      | Lclk  |MO(TRNS) |                                    |MO(TRNS)|Rclk | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |DELETE|------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */



// FUNCTION LAYER
[FUNCTION] = KEYMAP(
       KC_TRNS, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS, KC_MINS,  KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
       KC_TRNS, LSFT(KC_GRV),KC_4, KC_5, KC_6, KC_TAB,
       KC_TRNS, KC_EQL, KC_1, KC_2, KC_3, KC_0, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, SFT_T(KC_DELT), KC_TRNS,
    // right hand  
       KC_TRNS,  KC_F7,      KC_F8,        KC_F9,   KC_F10,    KC_F11,  KC_F12,
       KC_TRNS,  LSFT(KC_9), LSFT(KC_0),   KC_UP,   KC_LBRC,   KC_RBRC, KC_TRNS,
                 LSFT(KC_8), KC_LEFT,      KC_DOWN, KC_RIGHT,  KC_QUOT, KC_GRV,
       KC_TRNS,  LSFT(KC_7), LALT(KC_GRV), KC_MINS, KC_EQL,    KC_TRNS, KC_TRNS,
                 KC_TRNS , KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
