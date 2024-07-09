#include QMK_KEYBOARD_H

//========================================
// Constant Defines
//========================================

// Layer Defines
#define _QWERTY         (0U)
#define _NAVIGATE       (1U)
#define _NUMPAD         (2U)
#define _SYMBOL_LEFT    (3U)
#define _SYMBOL_RIGHT   (4U)
#define _FUNCTION        (5U)
#define _SHORTCUT       (6U)

// Layer Shortcuts
#define L_QWRTY      TO(_QWERTY)                   // Activates base layer and deactivates all others
#define SPC_SYML     LT(_NAVIGATE, KC_SPC)         // Tap for Space, hold for the Nav Left layer
#define BSPC_SYMR    LT(_NAVIGATE, KC_BSPC)        // Tap for Backspace, hold for Nav Right layer
#define ENT_NUM      LT(_NUMPAD, KC_ENT)           // Tap for Enter, hold for the Numpad layer
#define L_NAV        LT(_SYMBOL_LEFT, _FUNCTION)   // Tap for the Symbol Left layer, hold for the Function layer
#define R_NAV        LT(_SYMBOL_RIGHT, _FUNCTION)  // Tap for the Symbol Right layer, hold for the Function layer
#define L_HOME       TT(_FUNCTION)                 // Tap Toggle for the Function layer
#define L_SHCL       LT(_SHORTCUT, KC_CAPS)        // Tap for Capsword, hold for the Shortcut layer


// One shot mods
#define OS_LSFT      OSM(MOD_LSFT)
#define OS_RSFT      OSM(MOD_RSFT)

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
  SYMBOL_LEFT,
  SYMBOL_RIGHT,
  Function,
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
     OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    L_QWRTY,          KC_RGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHCL,  SPC_SYML,L_NAV,                     R_NAV,   BSPC_SYMR,ENT_NUM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAVIGATE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  _______, CS_TAB,  G_TAB,   C_TAB,   _______,                            _______, _______, _______, _______, _______,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, S_TAB,   KC_LALT, KC_TAB,  _______,                             _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                            _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, L_QWRTY,          KC_TRNS, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHCL,  SPC_SYML, L_NAV,                    R_NAV,   BSPC_SYMR,ENT_NUM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, KC_NUM,  KC_PSCR, KC_PAST, KC_PPLS,                            _______, _______, _______, _______, _______, TG(0),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PMNS,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_BSPC,                            _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PDOT, KC_4,    KC_5,    KC_6,    KC_EQL,  L_QWRTY,          _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHCL,  SPC_SYML, L_NAV,                    R_NAV,   BSPC_SYMR,ENT_NUM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOL_LEFT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_COLN, KC_LABK, KC_RABK, KC_SCLN,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,                              _______, _______, KC_EQL,  KC_PPLS, KC_PERC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_EXLM, KC_LBRC, KC_RBRC, _______, L_QWRTY,          _______, _______, _______, _______, _______, _______,  L_QWRTY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHCL,  SPC_SYML,L_NAV,                    L_QWRTY, BSPC_SYMR,ENT_NUM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOL_RIGHT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_UNDS, KC_PIPE, KC_QUOT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_CIRC, KC_ASTR, KC_AMPR, KC_QUES, _______,                            KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, L_QWRTY,          _______, _______, KC_MINS, KC_BSLS, KC_GRV,  _______,  L_QWRTY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHCL,  SPC_SYML,L_NAV,                    L_QWRTY, BSPC_SYMR,ENT_NUM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_FUNCTION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,                             _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_LGUI, KC_F1,   KC_F2,   KC_F3,   KC_F4,                              _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   L_QWRTY,          KC_TRNS, _______, _______, _______, _______, _______, L_QWRTY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHCL,  SPC_SYML,L_NAV,                     L_NAV,   BSPC_SYMR,ENT_NUM
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
     _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B), L_QWRTY,          C(KC_RGUI),C(KC_N),C(KC_M),C(KC_COMM),C(KC_DOT),C(KC_SLSH),L_QWRTY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    L_SHCL,  SPC_SYML,L_NAV,                     R_NAV,   BSPC_SYMR,ENT_NUM
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
      } else {
        layer_off(_NAVIGATE);
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
    case SYMBOL_LEFT:
      if (record->event.pressed) {
        layer_on(_SYMBOL_LEFT);
      } else {
        layer_off(_SYMBOL_LEFT);
      }
      return false;
      break;
    case SYMBOL_RIGHT:
      if (record->event.pressed) {
        layer_on(_SYMBOL_RIGHT);
      } else {
        layer_off(_SYMBOL_RIGHT);
      }
      return false;
      break;
    case Function:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
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
