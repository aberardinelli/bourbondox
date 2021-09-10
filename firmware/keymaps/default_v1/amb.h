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

enum unicode_names {
    lowera,
    uppera,
    lowere,
    uppere,
    loweri,
    upperi,
    lowero,
    uppero,
    loweru,
    upperu,
    lowern,
    uppern,
    EXCLAMATION,
    QUESTION
};

const uint32_t PROGMEM unicode_map[] = {
    [lowera] = 0x00E1,
    [uppera] = 0x00C1,
    [lowere] = 0x00E9,
    [uppere] = 0x00C9,
    [loweri] = 0x00ED,
    [upperi] = 0x00CD,
    [lowero] = 0x00F3,
    [uppero] = 0x00D3,
    [loweru] = 0x00FA,
    [upperu] = 0x00DA,
    [lowern] = 0x00F1,
    [uppern] = 0x00D1,
    [EXCLAMATION] = 0x00A1,
    [QUESTION] = 0x00BF
};

enum user_custom_keycodes {
    MVW_LEFT   = LCTL(KC_LEFT) 
    ,MVW_RIGHT  = LCTL(KC_RIGHT)
    ,SELW_LEFT  = LCTL(S(KC_LEFT))
    ,SELW_RIGHT = LCTL(S(KC_RIGHT))
    ,ACC_a = XP(lowera, uppera)
    ,ACC_e = XP(lowere, uppere)
    ,ACC_i = XP(loweri, upperi)
    ,ACC_o = XP(lowero, uppero)
    ,ACC_u = XP(loweru, upperu)
    ,ACC_n = XP(lowern, uppern)
    ,EXCL  = X(EXCLAMATION)
    ,QUES  = X(QUESTION)
};

