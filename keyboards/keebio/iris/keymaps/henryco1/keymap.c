#include QMK_KEYBOARD_H

//========================================
// Constant Defines
//========================================

// Layer Defines
#define _QWERTY   0
#define _NAVIGATE 1
#define _NUMPAD   2
#define _SYMBOL   3
#define _HOMEMOD  4
#define _SHORTCUT 5

// Layer Shortcuts
#define L_QWRTY      TO(_QWERTY)                // Toggle for base layer
#define SPC_NAV      LT(_NAVIGATE, KC_SPC)      // Tap for Space, hold for the Navigate layer
#define BSPC_NUM     LT(_NUMPAD, KC_BSPC)       // Tap for Backspace, hold for the Numpad layer
#define L_SYMB_TT    TT(_SYMBOL)                // Tap Toggle for the Symbol layer
#define L_SYMB_TO    TO(_SYMBOL)                // Tap Toggle for the Symbol layer
#define L_HOME       TT( _HOMEMOD)              // Tap Toggle for the Homemod layer
#define L_SHRT       MO(_SHORTCUT)              // Tap twice to toggle the Shortcut layer, otherwise hold and release to activate Shortcut layer

// Keycode Shortcuts
#define G_TAB        G(KC_TAB)   
#define S_TAB        S(KC_TAB)
#define C_TAB        C(KC_TAB)    
#define CS_TAB       C(S(KC_TAB))

// Layer Enums
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAVIGATE,
  NUMPAD,
  SYMBOL,
  HOMEMOD,
  SHORTCUT,
};

//========================================
// Keymap Declaration
//========================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    L_SYMB_TO,        KC_RGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, L_SYMB_TO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHRT,  SPC_NAV, L_HOME,                    L_SYMB_TT,BSPC_NUM,KC_ENT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAVIGATE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, CS_TAB,  G_TAB,   C_TAB,   _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, S_TAB,   KC_LALT, KC_TAB,  _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, L_SYMB_TO,        KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHRT,  SPC_NAV, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  TG(0),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_0,                               _______, _______, _______, _______, _______, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_MINS, KC_4,    KC_5,    KC_6,    KC_RBRC,                            _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,  KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_EQL,  L_SYMB_TO,        KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHRT,  L_QWRTY, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, RGB_RMOD,RGB_MOD, RGB_SPD, RGB_SPI, RGB_M_K,                            RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, S(KC_LBRC),S(KC_7),S(KC_8), S(KC_9), S(KC_0),                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, S(KC_RBRC),                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, S(KC_GRV),S(KC_1),S(KC_2), S(KC_3), S(KC_EQL),L_QWRTY,         KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, L_QWRTY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHRT,  SPC_NAV, KC_TRNS,                   L_QWRTY,   KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_HOMEMOD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS, _______, _______, KC_TAB,  _______,  _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                            _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, _______, _______, _______, _______, QK_BOOT, KC_TRNS,          KC_TRNS, _______, _______, _______, _______, _______, L_QWRTY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHRT,  SPC_NAV, KC_TRNS,                   L_SYMB_TO,KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_SHORTCUT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),                            C(KC_6), C(KC_7), C(KC_8), C(KC_9), C(KC_0), C(KC_MINS),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    C(KC_GRV),C(KC_Q), C(KC_W), C(KC_E), C(KC_R), C(KC_T),                            C(KC_Y), C(KC_U), C(KC_I), C(KC_O), C(KC_P), C(KC_BSLS),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, C(KC_A), C(KC_S), C(KC_D), C(KC_F), C(KC_G),                            C(KC_H), C(KC_J), C(KC_K), C(KC_L),C(KC_SCLN),C(KC_QUOT),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B), L_SYMB_TO,        C(KC_RGUI),C(KC_N),C(KC_M),C(KC_COMM),C(KC_DOT),C(KC_SLSH),L_QWRTY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHRT,  SPC_NAV, L_HOME,                    L_SYMB_TT,KC_BSPC, KC_ENT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

//========================================
// Keymap Main Handler
//========================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case NAVIGATE:
      if (record->event.pressed) {
        layer_on(_NAVIGATE);
        update_tri_layer(_NAVIGATE, _SYMBOL, _HOMEMOD);
      } else {
        layer_off(_NAVIGATE);
        update_tri_layer(_NAVIGATE, _SYMBOL, _HOMEMOD);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
      } else {
        layer_off(_NUMPAD);
      }
      return false;
      break;      
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        update_tri_layer(_NAVIGATE, _SYMBOL, _HOMEMOD);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_NAVIGATE, _SYMBOL, _HOMEMOD);
      }
      return false;
      break;
    case HOMEMOD:
      if (record->event.pressed) {
        layer_on(_HOMEMOD);
      } else {
        layer_off(_HOMEMOD);
      }
      return false;
      break;
    case SHORTCUT:
      if (record->event.pressed) {
        layer_on(_SHORTCUT);
      } else {
        layer_off(_SHORTCUT);
      }
      return false;
      break;
  }
  return true;
}
