#include QMK_KEYBOARD_H


/* ---------------------------- Declare Custom Keycodes ---------------------------- */

enum layers {
    L_QWERTY,
    L_STURDY,
    L_LOWER,
    L_RAISE,
    L_NUMPAD,
};

enum combos {
    PINKY_CAPS,
    COMBO_LENGTH,  /* Leave COMBO_LENGTH as last in enum */
};

uint16_t COMBO_LEN = COMBO_LENGTH;

#define TAB_CTL LCTL_T(KC_TAB)        /* Tap for tab, hold for control               */
#define QUT_CTL RCTL_T(KC_QUOT)       /* Tap for quote, hold for control             */
#define LWR_ENT LT(L_LOWER, KC_ENT)   /* Tap for enter, hold for L_LOWER             */
#define RAIS_BS LT(L_RAISE, KC_BSPC)  /* Tap for bksp, hold for L_RAISE              */
#define ESC_NUM LT(L_NUMPAD, KC_ESC)  /* Tap for esc, hold for L_NUMPAD              */
#define GNME_LF G(KC_PGUP)            /* (gnome) Move to prev workspace              */
#define GNME_RT G(KC_PGDN)            /* (gnome) Move to next workspace              */
#define GNME_ML G(S(KC_PGUP))         /* (gnome) Move window to prev workspace       */
#define GNME_MR G(S(KC_PGDN))         /* (gnome) Move window to next workspace       */
#define TERM_CP C(S(KC_C))            /* Terminal copy (ctrl + shift + c)            */
#define TERM_PT C(S(KC_V))            /* Terminal paste (ctrl + shift + v)           */
#define AWM_PRV G(KC_ESC)             /* (awesome) Return to previous tags           */
#define AWMT(N) G(C(KC_##N))          /* (awesome) Toggle tag #N                     */

/* ------------------------------------- Layers ------------------------------------ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_LALT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RALT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RGUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TAB_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, QUT_CTL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_VOLD,          KC_VOLU, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    TERM_CP, ESC_NUM, LWR_ENT,                   KC_SPC,  RAIS_BS, TERM_PT
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [L_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                            KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                            KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,          _______, _______, KC_PIPE, KC_LABK, KC_RABK, KC_BSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_DEL,  _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [L_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                            G(KC_6), G(KC_7), G(KC_8), G(KC_9), _______, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______,                            GNME_ML, GNME_LF, GNME_RT, GNME_MR, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_GRV,  KC_TILD, _______, KC_PSCR,          _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, AWM_PRV, _______,                   _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [L_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, AWMT(1), AWMT(2), AWMT(3), AWMT(4), AWMT(5),                            AWMT(6), AWMT(7), AWMT(8), AWMT(9), _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,                            _______, KC_4,    KC_5,    KC_6,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_0,    _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};


/* ------------------------------------ Get Hold ----------------------------------- */

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    /**
     * Return false for a keycode as to *not* select the hold action on other
     * keypress.
     *
     * Return true for a keycode as to immediately select the hold action on other
     * keypress.
     */
    switch (keycode) {
        case TAB_CTL:
        case LWR_ENT:
        case RAIS_BS:
            return true;
        default:
            return false;
    }
}


/* ------------------------------------- Combos ------------------------------------ */

const uint16_t PROGMEM pinky_caps_combo[] = { KC_LSFT, KC_RSFT, COMBO_END };

combo_t key_combos[] = {

    /* Tap both shift keys to toggle caps lock */
    [PINKY_CAPS] = COMBO(pinky_caps_combo, KC_CAPS),

};


/* --------------------------------- Key Overrides --------------------------------- */

const key_override_t comma_paren_override = ko_make_with_layers(
    MOD_MASK_SHIFT,  /* When shift is active   */
    KC_COMM,         /* and KC_COMM is pressed */
    KC_LPRN,         /* send KC_LPRN           */
    1 << L_QWERTY    /* only on these layers   */
);

const key_override_t dot_paren_override = ko_make_with_layers(
    MOD_MASK_SHIFT,  /* When shift is active  */
    KC_DOT,          /* and KC_DOT is pressed */
    KC_RPRN,         /* send KC_RPRN          */
    1 << L_QWERTY    /* only on these layers  */
);

const key_override_t colon_semicolon_override = ko_make_basic(
    MOD_MASK_SHIFT,  /* When shift is active   */
    KC_COLN,         /* and KC_COLN is pressed */
    KC_SCLN          /* send KC_SCLN           */
);

const key_override_t *key_overrides[] = {
    &comma_paren_override,      /* Use ,/( instead of ,/<  */
    &dot_paren_override,        /* Use ./) instead of ./>  */
    &colon_semicolon_override,  /* Use :/; instead of ;/:  */
};
