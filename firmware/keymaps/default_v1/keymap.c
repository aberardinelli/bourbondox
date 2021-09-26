/* Copyright 2021 bourbon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "amb.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_BOURB(
  //┌────────┬────────┬────────┬────────┬──────────────┬────────┬────────┐             ┌──────────┬────────┬──────────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4          ,KC_5    ,KC_SLCK ,              TT(NUM)   ,KC_6    ,KC_7          ,KC_8    ,KC_9    ,KC_0    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼──────────────┼────────┼────────┤             ├──────────┼────────┼──────────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R          ,KC_T    ,KC_PSCR ,              TT(GAME)  ,KC_Y    ,KC_U          ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼──────────────┼────────┼────────┤             ├──────────┼────────┼──────────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,LT(FSYM,KC_F) ,KC_G    ,TT(FXN) ,              LGUI(KC_L),KC_H    ,LT(JSYM,KC_J) ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼──────────────┼────────┼────────┘             └──────────┼────────┼──────────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V          ,KC_B    ,                                  KC_N    ,KC_M          ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_ENT  ,
  //└────────┼────────┼────────┼────────┴──────────────┴────────┼────────┐             ┌──────────┼────────┴──────────────┼────────┼────────┴────────┴────────┘
     KC_LCTL ,KC_LGUI ,KC_LALT ,MO(ADJ) ,                        KC_SPC  ,              KC_CALC   ,                        KC_UP   ,
  //└────────┴────────┴────────┴────────┘                       └────────┘             ┌──────────┼────────┐     ┌────────┼────────┼────────┬────────┬────────┐
                                                                                        KC_DEL    ,KC_BSPC ,      KC_LEFT ,KC_DOWN ,KC_RGHT ,         KC_RSFT
  //                                                                                   └──────────┴────────┘     └────────┴────────┴────────┴────────┴────────┘
  ),

  [FXN] = LAYOUT_BOURB(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐             ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,_______ ,_______ ,KC_VOLD ,KC_MUTE ,KC_VOLU ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,_______ ,_______ ,              _______ ,_______ ,_______ ,KC_MPRV ,KC_MPLY ,KC_MNXT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,_______ ,                                _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┼────────┼────────┼────────┴────────┴────────┼────────┐             ┌────────┼────────┴────────┴─────┬──┴─────┬──┴────────┴────────┘
     _______ ,_______ ,_______ ,_______ ,                  _______ ,              _______ ,                        _______ ,
  //└────────┴────────┴────────┴────────┘                 └────────┘             ┌────────┼────────┐     ┌────────┼────────┼────────┬────────┬────────┐
                                                                                  _______ ,_______ ,      _______ ,_______ ,_______ ,         _______
  //                                                                             └────────┴────────┘     └────────┴────────┴────────┴────────┴────────┘
  ),

  [NUM] = LAYOUT_BOURB(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐             ┌────────┬────────┬────────┬────────┬────────┬────────┬───────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,KC_NLCK ,KC_PSLS ,KC_PAST ,KC_PMNS ,_______ ,LGUI(KC_L) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼───────────┤
     _______ ,_______ ,_______ ,_______ ,KC_UP   ,_______ ,_______ ,              _______ ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PPLS ,_______ ,_______    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼───────────┤
     _______ ,_______ ,_______ ,KC_LEFT ,KC_DOWN ,KC_RGHT ,_______ ,              _______ ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,_______ ,_______    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             └────────┼────────┼────────┼────────┼────────┼────────┼───────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,KC_PENT ,KC_PENT    ,
  //└────────┼────────┼────────┼────────┴────────┴────────┴────────┘             ┌────────┼────────┴────────┴─────┬──┴─────┬──┴────────┴───────────┘
     _______ ,_______ ,_______ ,_______ ,                  _______ ,              KC_BSPC ,                        KC_PENT ,
  //└────────┴────────┴────────┴────────┘                 └────────┘             ┌────────┼────────┐     ┌────────┼────────┼────────┬────────┬────────┐
                                                                                  KC_P0   ,KC_P0   ,      KC_PDOT ,KC_PDOT ,_______ ,         _______
  //                                                                             └────────┴────────┘     └────────┴────────┴────────┴────────┴────────┘
  ),

  [GAME] = LAYOUT_BOURB(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐             ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,              KC_F    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┼────────┼────────┼────────┴────────┴────────┼────────┐             ┌────────┼────────┴────────┴─────┬──┴─────┬──┴────────┴────────┘
     _______ ,_______ ,_______ ,_______ ,                  _______ ,              KC_BSPC ,                        KC_P0   ,
  //└────────┴────────┴────────┴────────┘                 └────────┘             ┌────────┼────────┐     ┌────────┼────────┼────────┬────────┬────────┐
                                                                                  KC_LCTL ,KC_LALT ,      KC_P4   ,KC_P2   ,KC_P6   ,         _______
  //                                                                             └────────┴────────┘     └────────┴────────┴────────┴────────┴────────┘
  ),

  [JSYM] = LAYOUT_BOURB(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐             ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_LBRC ,KC_RBRC ,KC_UNDS ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_LCBR ,KC_RCBR ,KC_MINS ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┼────────┼────────┼────────┴────────┴────────┼────────┐             ┌────────┼────────┴────────┴─────┬──┴─────┬──┴────────┴────────┘
     _______ ,_______ ,_______ ,_______ ,                  _______ ,              _______ ,                        _______ ,
  //└────────┴────────┴────────┴────────┘                 └────────┘             ┌────────┼────────┐     ┌────────┼────────┼────────┬────────┬────────┐
                                                                                  _______ ,_______ ,      _______ ,_______ ,_______ ,         _______
  //                                                                             └────────┴────────┘     └────────┴────────┴────────┴────────┴────────┘
  ),

  [FSYM] = LAYOUT_BOURB(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐             ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,KC_HASH ,_______ ,_______ ,_______ ,              _______ ,_______ ,MVW_LEFT,MVW_RIGHT,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,_______ ,KC_HOME, KC_END  ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                _______ ,SELW_LEFT,SELW_RIGHT,_______ ,_______ ,_______ ,
  //└────────┼────────┼────────┼────────┴────────┴────────┼────────┐             ┌────────┼────────┴────────┴─────┬──┴─────┬──┴────────┴────────┘
     _______ ,_______ ,_______ ,_______ ,                  _______ ,              _______ ,                        _______ ,
  //└────────┴────────┴────────┴────────┘                 └────────┘             ┌────────┼────────┐     ┌────────┼────────┼────────┬────────┬────────┐
                                                                                  _______ ,_______ ,      _______ ,_______ ,_______ ,         _______
  //                                                                             └────────┴────────┘     └────────┴────────┴────────┴────────┴────────┘
  ),

  [ADJ] = LAYOUT_BOURB(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐             ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     RESET   ,EXCL    ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,ACC_e   ,_______ ,_______ ,_______ ,              _______ ,_______ ,ACC_u   ,ACC_i   ,ACC_o   ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,ACC_a   ,_______ ,_______ ,_______ ,_______ ,_______ ,              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                ACC_n   ,_______ ,_______ ,_______ ,QUES    ,_______ ,
  //└────────┼────────┼────────┼────────┴────────┴────────┼────────┐             ┌────────┼────────┴────────┴─────┬──┴─────┬──┴────────┴────────┘
     TO(BASE),_______ ,_______ ,_______ ,                  KC_CAPS ,              _______ ,                        _______ ,
  //└────────┴────────┴────────┴────────┘                 └────────┘             ┌────────┼────────┐     ┌────────┼────────┼────────┬────────┬────────┐
                                                                                  _______ ,_______ ,      _______ ,_______ ,_______ ,         _______
  //                                                                             └────────┴────────┘     └────────┴────────┴────────┴────────┴────────┘
  )
};



//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);


void oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case FXN:
            oled_write_P(PSTR("Alternate\n"), false);
            break;
        case NUM:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case ADJ:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Symbol"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);


    // If you want to change the display of OLED, you need to change here
    //oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
    //led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    //oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
