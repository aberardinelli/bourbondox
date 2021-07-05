#include QMK_KEYBOARD_H

enum user_layers {
    BASE = 0
   ,FXN
   ,NUM
   ,FSYM 
   ,JSYM
   ,GAME
   ,ADJ
};

enum user_custom_keycodes {
    MVW_LEFT   = LCTL(KC_LEFT) 
    ,MVW_RIGHT  = LCTL(KC_RIGHT)
    ,SELW_LEFT  = LCTL(S(KC_LEFT))
    ,SELW_RIGHT = LCTL(S(KC_RIGHT))
};

