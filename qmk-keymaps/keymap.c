/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
qthe Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "dynamic_macro.h"

enum my_layers {
  L_BASE,
  L_FN
};

enum my_keycodes {
  ANY = SAFE_RANGE,
  MY_MACROS
};

// key shorthand
#define FN MO(L_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Special keys:
   * PRO = Programming
   * NXL = Next Layer
   * ANY = Any Key
   * NO = Not Defined yet
   */

  /* Base Layer
   *
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ ` │ \ │PRO│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │Bspc │ANY│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │MT_CE │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │PXL│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │MACROS│ ↑ │NXL│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
   * │LEAD│LAlt│LGui│         Space          │ NO │ FN │ │ ← │ ↓ │ → │
   * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
   */
    [L_BASE] = LAYOUT_truefox(
        KC_ESC,		KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_MINS,	KC_EQL,	KC_GRV,	KC_BSLS,	KC_NO,
        KC_TAB,		KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_LBRC,	KC_RBRC,	KC_BSPC,	ANY,
        CTL_T(KC_ESC),	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,KC_QUOT,	KC_ENT,	KC_NO,
        KC_LSFT,		KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,KC_DOT, KC_SLSH,MY_MACROS,			KC_UP,		KC_NO,
        KC_LEAD,		KC_LALT,KC_LGUI,		KC_SPC, KC_NO,	FN,	KC_LEFT,KC_DOWN,KC_RGHT),

  /* Function layer
   *
   *  Other than explicitly defined keys, other keys will be explicitly set to NO. This is because Fn layer is usually short lived, temporarly layer,
   * and we don't want any other keys to be functional from previous layer(TRNS)
   *
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │NO │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│NO │NO │FLS│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
   * │ NO  │NO │NO │NO │NO │NO │NO │NO │NO │NO │NO │NO │NO │ NO  │NO │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │  NO  │NO │NO │DBG│NO │NO │NO │NO │NO │BLT│NO │NO │  NO    │NO │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │   NO   │NO │NO │NO │NO │NO │NO │NO │NO │NO │NO │ PLAY │VLU|NO │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
   * │ NO | NO │ NO │        NO              │ NO │ NO │ |PRV│VLD|NXT|
   * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
   */
  [L_FN] = LAYOUT_truefox(
    KC_NO,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_NO,	KC_NO,	RESET,
    KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_NO,		KC_NO,		KC_NO,	KC_NO,
    KC_NO,	KC_NO,	KC_NO,	DEBUG,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	BL_TOGG,KC_NO,		KC_NO,		KC_NO,		KC_NO,
    KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_MPLY,	KC_VOLU,	KC_NO,
    KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_MPRV,	KC_VOLD,	KC_MNXT),
};

uint16_t todo_timer = 0;
bool is_dyn_rec_started = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (record->event.pressed) {
      dprintf("kc: %u", keycode);
  }

  switch (keycode) {
    case MY_MACROS:

      if (record->event.pressed) {
        todo_timer = timer_read();

      } else {
        keyrecord_t kr;
        kr.event.pressed = false;

        if (timer_elapsed(todo_timer) > MY_DYN_REC_START_TIMEOUT) {
          is_dyn_rec_started = true;
          // Can make minor improvement by always stopping previous one, however need to probably set kr.event.pressed = false for stop to work which
          // I really don't understand why.
          /* process_record_dynamic_macro( DYN_REC_STOP, &kr); */
          process_record_dynamic_macro( DYN_REC_START1, &kr);
        } else {
          if (is_dyn_rec_started) {
            kr.event.pressed = true;
            process_record_dynamic_macro( DYN_REC_STOP, &kr);
            is_dyn_rec_started = false;
          } else {
            process_record_dynamic_macro( DYN_MACRO_PLAY1, &kr);
          }
        }
      }

      return false;

    default:

      if ( !process_record_dynamic_macro( keycode, record ) ) {
        return false;
      }

      return true; // Process all other keycodes normally
  }
}

// leader key
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_P) {
      SEND_STRING(LEADER_P);
    }
  }
}
