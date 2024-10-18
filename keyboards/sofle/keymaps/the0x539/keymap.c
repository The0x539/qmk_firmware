#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EMOD,
    _FN,
    _NUMPAD,
};

enum custom_keycodes {
    KC_EMOD = SAFE_RANGE,
    KC_LF,
    KC_LEQ,
    KC_GEQ,
    KC_NEQ,
    KC_ARRW,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FN)
#define MONP MO(_NUMPAD)
#define C_S_ESC C(S(KC_ESC))
#define C_A_DEL C(A(KC_DEL))

#define ___ KC_TRNS
#define ____ KC_TRNS
#define _____ KC_TRNS
#define ______ KC_TRNS
#define ___________ KC_TRNS

#define _X_ KC_NO
#define __X__ KC_NO
#define ___X___ KC_NO
#define _____X_____ KC_NO
 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_GRV,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,           /**/          KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    KC_BSPC,
  KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,    KC_T,           /**/          KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_BSLS,
  KC_EMOD, KC_A, KC_S,    KC_D,    KC_F,    KC_G,           /**/          KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE, /**/ KC_MUTE, KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_LALT, KC_LCTL, LOWER, KC_SPC,  /**/ KC_SPC,  RAISE, FUNCT, KC_RALT, KC_ENT
),

[_LOWER] = LAYOUT(
  ___, _______, _______, _______, _______, _______,      /**/      _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_DEL,
  ___, _______, _______, _______, _______, _______,      /**/      _______, KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, ______,
  ___, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      /**/      KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_SCLN, KC_LF,
  ___, _______, _______, _______, _______, _______, ___, /**/ ___, _______, _______, _______, KC_ARRW, _______, ______,
                _______, _______, _______, _______, ___, /**/ ___, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
  ___, ____, ____, ____, ____, ____,      /**/      ____, ____, ______, KC_MINS, KC_EQL, KC_INS,
  ___, ____, ____, ____, ____, ____,      /**/      ____, ____, ______, _______, ______, ______,
  ___, KC_1, KC_2, KC_3, KC_4, KC_5,      /**/      KC_6, KC_7, KC_8,   KC_9,    KC_0,   ______,
  ___, ____, ____, ____, ____, ____, ___, /**/ ___, ____, ____, KC_LEQ, KC_GEQ,  KC_NEQ, ______,
             ____, ____, ____, ____, ___, /**/ ___, ____, ____, ______, C(A(G(KC_P)))
),

[_ADJUST] = LAYOUT(
  C_S_ESC, ___X___, _X_, _X_, ___X___, _X_,          /**/          ___X___, ___X___, ___X___, ___X___, ___X___, C_A_DEL,
  ___X___, QK_BOOT, _X_, _X_, QK_RBT,  _X_,          /**/          ___X___, ___X___, ___X___, ___X___, QK_BOOT, ___X___,
  RGB_TOG, ___X___, _X_, _X_, ___X___, _X_,          /**/          KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, ___X___, ___X___,
  ___X___, ___X___, _X_, _X_, ___X___, _X_, QK_BOOT, /**/ QK_BOOT, NK_ON,   NK_OFF,  ___X___, ___X___, ___X___, ___X___,
                    _X_, _X_, ___X___, _X_, ___X___, /**/ ___X___, ___X___, ___X___, ___X___, ___X___
),

[_EMOD] = LAYOUT(
  KC_PSCR, ___, ___, ___, ____, ___,          /**/          G(KC_LEFT), G(KC_DOWN), G(KC_UP),  G(KC_RGHT), ___, ______,
  _______, ___, ___, ___, ____, ___,          /**/          A(KC_LEFT), A(KC_DOWN), A(KC_UP),  A(KC_RGHT), ___, ______,
  _______, ___, ___, ___, MONP, ___,          /**/            KC_LEFT,    KC_DOWN,    KC_UP,     KC_RGHT,  ___, KC_ENT,
  _______, ___, ___, ___, ____, ___, _______, /**/ _______, C(KC_LEFT), C(KC_DOWN), C(KC_UP),  C(KC_RGHT), ___, ______,
            ___, ___, ____, ___, KC_UNDS, /**/ KC_UNDS,   KC_HOME,    KC_PGDN,    KC_PGUP,   KC_END
),

[_FN] = LAYOUT(
  _____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,       /**/       KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, ______,
  _____, _____, _____, _____, _____, _____,       /**/       _____, _____, _____, ______, ______, ______,
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,       /**/       KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
  _____, _____, _____, _____, _____, _____, ____, /**/ ____, _____, _____, _____, ______, ______, ______,
                _____, _____, _____, _____, ____, /**/ ____, _____, _____, _____, ______
),

[_NUMPAD] = LAYOUT(
  _X_, _X_, _X_, _X_, _X_, _X_,      /**/      KC_PPLS, KC_P7,   KC_P8, KC_P9,   KC_PEQL, ___________,
  _X_, _X_, _X_, _X_, _X_, _X_,      /**/      KC_PMNS, KC_P4,   KC_P5, KC_P6,   KC_NUM,  _____X_____,
  _X_, _X_, _X_, _X_, _X_, _X_,      /**/      KC_PAST, KC_P1,   KC_P2, KC_P3,   KC_PENT, _____X_____,
  _X_, _X_, _X_, _X_, _X_, _X_, ___, /**/ ___, KC_PSLS, KC_PCMM, KC_P0, KC_PDOT, KC_PENT, KC_NUM_LOCK,
            ___, ___, ___, ___, ___, /**/ ___, _______, _______, _____, _______
)

};

#if defined(ENCODER_MAP_ENABLE)
#define ENC_TRNS { {KC_TRNS, KC_TRNS}, {KC_TRNS, KC_TRNS} }
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [_LOWER]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_UP,   KC_DOWN) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(_______, _______) },
    [_ADJUST] = ENC_TRNS,
    [_EMOD]   = ENC_TRNS,
    [_FN]     = ENC_TRNS,
    [_NUMPAD] = ENC_TRNS,
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool shifts[2] = {false, false};
    static bool emod_used = false;

    bool pressed = record->event.pressed;

    if (pressed && layer_state_is(_EMOD)) {
        emod_used = true;
    }

    switch (keycode) {
        case KC_LSFT:
        case KC_RSFT:
            shifts[keycode == KC_RSFT] = pressed;
            if (shifts[0] && shifts[1]) {
                tap_code(KC_CAPS);
            }
            break;

        case KC_EMOD:
            if (pressed) {
                emod_used = false;
                layer_on(_EMOD);
            } else {
                layer_off(_EMOD);
                if (!emod_used) {
                    tap_code(KC_ESC);
                }
            }
            break;

        #define SIMPLE_MACRO(key, text) \
            case key:                   \
                if (pressed) {          \
                    SEND_STRING(text);  \
                }                       \
                break;

        SIMPLE_MACRO(KC_LF, "\\n");
        SIMPLE_MACRO(KC_LEQ, "<=");
        SIMPLE_MACRO(KC_GEQ, ">=");
        SIMPLE_MACRO(KC_NEQ, "!=");

        case KC_ARRW:
            if (pressed) {
                uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                if (mods & MOD_MASK_SHIFT) {
                    SEND_STRING("=>");
                } else {
                    SEND_STRING("->");
                }
                set_mods(mods);
            }
            break;

        default:
            break;
    }

    return true;
}

#ifdef OLED_ENABLE
#include "oled.c"
#endif

#ifdef RGBLIGHT_ENABLE
#include "rgblight.c"
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    #ifdef RGBLIGHT_ENABLE
        rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
        rgblight_set_layer_state(_LOWER,  layer_state_cmp(state, _LOWER));
        rgblight_set_layer_state(_RAISE,  layer_state_cmp(state, _RAISE));
        rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));
        rgblight_set_layer_state(_EMOD,   layer_state_cmp(state, _EMOD));
        rgblight_set_layer_state(_FN,     layer_state_cmp(state, _FN));
        rgblight_set_layer_state(_NUMPAD, layer_state_cmp(state, _NUMPAD));
    #endif
    return state;
}
