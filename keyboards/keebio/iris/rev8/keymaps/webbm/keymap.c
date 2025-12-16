#include QMK_KEYBOARD_H

#ifdef SPLIT_KEYBOARD
#    include "transactions.h"
#endif


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

enum custom_keycodes {
    JJ_TOGG = SAFE_RANGE,  /* Toggle jj-to-escape feature */
};

uint16_t COMBO_LEN = COMBO_LENGTH;

#define TAB_CTL LCTL_T(KC_TAB)        /* Tap for tab, hold for control               */
#define QUT_CTL RCTL_T(KC_QUOT)       /* Tap for quote, hold for control             */
#define RAIS_BS LT(L_RAISE, KC_BSPC)  /* Tap for bksp, hold for L_RAISE              */
#define ENT_NUM LT(L_NUMPAD, KC_ENT)  /* Tap for enter, hold for L_NUMPAD              */
#define ALT_LWR LT(L_LOWER, KC_LALT)  /* Tap for left alt, hold for L_LOWER          */
#define ALT_RAS LT(L_RAISE, KC_RALT)  /* Tap for right alt, hold for L_RAISE         */
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
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RALT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TAB_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, QUT_CTL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_VOLD,          KC_VOLU, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    ALT_LWR, KC_SPC, KC_LGUI,                   KC_RGUI, ENT_NUM, ALT_RAS
  //                               └────────┴───────┴────────┘                 └────────┴──── ───┴────────┘
  ),

  [L_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                            KC_ASTR, KC_PLUS, KC_LBRC, KC_RBRC, KC_AMPR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                            KC_PIPE, KC_EQL,  KC_LCBR, KC_RCBR, KC_EXLM, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,          _______, KC_UNDS, KC_MINS, KC_LABK, KC_RABK, KC_BSLS, _______,
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
     _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,                            JJ_TOGG, KC_4,    KC_5,    KC_6,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_1,    KC_2,    KC_3,    KC_0,    _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
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


/* ---------------------------------- JJ to Escape ---------------------------------- */

static uint16_t j_timer = 0;
static bool awaiting_second_j = false;
static bool jj_escape_enabled = false;  /* Off by default, toggle with JJ_TOGG */

#ifdef SPLIT_KEYBOARD
static void jj_state_sync_slave(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size,
                                void *target2initiator_buffer) {
    (void)target2initiator_buffer_size;
    (void)target2initiator_buffer;

    if (initiator2target_buffer_size != sizeof(uint8_t)) {
        return;
    }

    jj_escape_enabled = *((const uint8_t *)initiator2target_buffer);
}
#endif

void keyboard_post_init_user(void) {
#ifdef SPLIT_KEYBOARD
    transaction_register_rpc(JJ_STATE_SYNC, jj_state_sync_slave);
#endif

#ifdef RGB_MATRIX_ENABLE
    // Keep RGB off by default; the JJ indicator will override the J key when enabled.
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_BLACK);
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JJ_TOGG:
            if (record->event.pressed) {
                jj_escape_enabled = !jj_escape_enabled;
#ifdef SPLIT_KEYBOARD
                if (is_keyboard_master()) {
                    const uint8_t state = jj_escape_enabled;
                    transaction_rpc_send(JJ_STATE_SYNC, sizeof(state), &state);
                }
#endif
            }
            return false;

        case KC_J:
            if (!jj_escape_enabled || !record->event.pressed) {
                return true;
            }
            if (awaiting_second_j && timer_elapsed(j_timer) < TAPPING_TERM) {
                tap_code(KC_BSPC);
                tap_code(KC_ESC);
                awaiting_second_j = false;
                return false;
            }
            j_timer = timer_read();
            awaiting_second_j = true;
            return true;

        default:
            if (record->event.pressed) {
                awaiting_second_j = false;
            }
            return true;
    }
}

#ifdef RGB_MATRIX_ENABLE

#    define JJ_LED_ROW 7
#    define JJ_LED_COL 4
#    define JJ_PULSE_PERIOD_MS 1000

static uint8_t jj_pulse_brightness(void) {
    const uint16_t period = JJ_PULSE_PERIOD_MS;
    const uint16_t half   = period / 2;
    const uint16_t phase  = timer_read() % period;

    if (phase < half) {
        return (uint8_t)(((uint32_t)phase * 255) / half);
    }
    return (uint8_t)(((uint32_t)(period - phase) * 255) / half);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!jj_escape_enabled) {
        return true;
    }

    const uint8_t j_led = g_led_config.matrix_co[JJ_LED_ROW][JJ_LED_COL];
    if (j_led < led_min || j_led >= led_max) {
        return true;
    }

    hsv_t hsv = {HSV_RED};
    hsv.v     = (uint8_t)(((uint16_t)jj_pulse_brightness() * RGB_MATRIX_MAXIMUM_BRIGHTNESS) / 255);

    const rgb_t rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(j_led, rgb.r, rgb.g, rgb.b);

    return true;
}

#endif
