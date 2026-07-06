#include QMK_KEYBOARD_H

#ifdef SPLIT_KEYBOARD
#    include "transactions.h"
#endif


/* ---------------------------- Declare Custom Keycodes ---------------------------- */

enum layers {
    L_QWERTY,
    L_STURDY,
    L_LOWER,
    L_FUN,
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

#define TAB_NUM LT(L_NUMPAD, KC_TAB)  /* Tap for tab, hold for L_NUMPAD              */
#define QUT_FUN LT(L_FUN, KC_QUOT)    /* Tap for quote, hold for function layer      */
#define RAIS_BS LT(L_RAISE, KC_BSPC)  /* Tap for bksp, hold for L_RAISE              */
#define ALT_LWR MO(L_LOWER)           /* Hold for L_LOWER (tap does nothing)         */
#define ALT_RAS LT(L_RAISE, KC_RALT)  /* Tap for right alt, hold for L_RAISE         */
#define A_GUI LGUI_T(KC_A)            /* Home row mod: tap A, hold left GUI          */
#define S_ALT LALT_T(KC_S)            /* Home row mod: tap S, hold left ALT          */
#define D_CTL LCTL_T(KC_D)            /* Home row mod: tap D, hold left CTRL         */
#define F_SFT LSFT_T(KC_F)            /* Home row mod: tap F, hold left SHIFT        */
#define J_SFT RSFT_T(KC_J)            /* Home row mod: tap J, hold right SHIFT       */
#define K_CTL RCTL_T(KC_K)            /* Home row mod: tap K, hold right CTRL        */
#define L_ALT RALT_T(KC_L)            /* Home row mod: tap L, hold right ALT         */
#define CLN_GUI RGUI_T(KC_COLN)       /* Home row mod: tap :, hold right GUI         */
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
     TAB_NUM, A_GUI,   S_ALT,   D_CTL,   F_SFT,   KC_G,                               KC_H,    J_SFT,   K_CTL,   L_ALT,   CLN_GUI, QUT_FUN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_VOLD,          KC_VOLU, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    ALT_LWR, KC_SPC, KC_LGUI,                   KC_RGUI, KC_ENT,  ALT_RAS
  //                               └────────┴───────┴────────┘                 └────────┴──── ───┴────────┘
  ),

  [L_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_ASTR, KC_PLUS, KC_LBRC, KC_RBRC, KC_AMPR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_PIPE, KC_EQL,  KC_LCBR, KC_RCBR, KC_EXLM, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_UNDS, KC_MINS, KC_LABK, KC_RABK, KC_BSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_DEL,  _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [L_FUN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
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

// Treat thumb keys as exempt so home row mods can chord with them naturally.
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',    '*', '*', 'R', 'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',    '*', '*', '*'
);


/* ------------------------------------ Get Hold ----------------------------------- */

// Per-key tap-hold customization for home row mods.
// Strategy (drawn from precondition guide, Getreuer/pgetreuer recommendations,
// Chordal Hold + Flow Tap core features, and urob "timeless" HRM ports):
// - High base TAPPING_TERM (250ms) for safety on same-hand rolls (Chordal enforces tap).
// - Shorter term on Shift (F/J) for responsive capitalization/CamelCase without
//   feeling sluggish for deliberate holds.
// - Home-row mods use conservative tap-hold decisions so ordinary typing wins,
//   especially at word starts where Flow Tap has no preceding key to inspect.
// - Flow Tap still removes HRM delay during fast continuous typing.
// - QUICK_TAP_TERM global 0 for safety, but per-key exceptions for Vim hjkl
//   navigation so that tap-then-hold on j/k/l produces rapid letter repeat
//   (jjjj / kkkk cursor movement). h is plain (not a mod-tap) so it always worked.
// See also: docs.qmk.fm/tap_hold , getreuer.info/posts/keyboards/faqs ,
// precondition.github.io/home-row-mods , ZSA Chordal Hold blog.

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    /*
     * Keep all eight home-row mods off permissive hold. Nested word-start rolls
     * like "and" (A_GUI+n) and "find" (F_SFT+i) should resolve as letters, not
     * shortcuts or capitalization. Intentional HRM chords still work after the
     * tapping term; fast modifier chords can use the dedicated thumb/outer mods.
     */
    switch (keycode) {
        case A_GUI:
        case S_ALT:
        case D_CTL:
        case F_SFT:
        case J_SFT:
        case K_CTL:
        case L_ALT:
        case CLN_GUI:
            return false;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    switch (keycode) {
        /*
         * Do not let HRMs become holds merely because another key was pressed.
         * This avoids word-start roll failures like "and" -> GUI+n and
         * "find" -> Shift+i.
         */
        case A_GUI:
        case S_ALT:
        case D_CTL:
        case F_SFT:
        case J_SFT:
        case K_CTL:
        case L_ALT:
        case CLN_GUI:
            return false;

        /*
         * Layer-taps are not home-row letter mods; keep them responsive.
         */
        case TAB_NUM:
        case RAIS_BS:
            return true;

        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    switch (keycode) {
        // Shifts get a shorter term: snappier for intentional caps while still
        // protected by Chordal (same hand) + Flow Tap (fast flow). Adjust offset
        // or use absolute value during tuning. Use g_tapping_term for the base
        // if you prefer the runtime global.
        case F_SFT:
        case J_SFT:
            return TAPPING_TERM - 50;  // 200ms
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    switch (keycode) {
        // Vim navigation special case (right-hand home row):
        //   h = plain KC_H (always repeats normally)
        //   j = J_SFT (RSFT_T), k = K_CTL (RCTL_T), l = L_ALT (RALT_T)
        // User needs to be able to tap-then-hold (or rapidly double-press+hold)
        // these to get quick repeated cursor movement: jjjj, kkkk, etc.
        // Returning a positive value (here the normal TAPPING_TERM window)
        // allows the tap action to repeat on a subsequent quick hold of the *same*
        // dual-role key.
        //
        // For the other HRMs (A/S/D/F GUI/ALT/CTL and the : GUI), we return the
        // global 0. This keeps the safety property: after you tap the letter,
        // a quick hold of the key will activate the modifier rather than spamming
        // the letter or interfering with intended mod usage.
        //
        // This is a very common pattern for Vim + HRM users.
        case J_SFT:
        case K_CTL:
        case L_ALT:
            return TAPPING_TERM;
        default:
            return QUICK_TAP_TERM;  // 0 for everything else
    }
}

// Optional explicit is_flow_tap_key if you want to customize the set of keys
// that participate in flow-tap protection (letters, space, common punct by
// default in QMK). Defining it alongside get_flow_tap_term is supported; the
// get_ version takes precedence for the term decision.
bool is_flow_tap_key(uint16_t keycode) {
    // Strip mod-tap / layer-tap to get the tap keycode for classification.
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
            break;
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
            break;
    }
    switch (keycode) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
        case KC_COLN:  // our right GUI tap key
            return true;
    }
    return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    (void)record;

    // Note: Previously shifts returned 0 here (exempt from flow protection).
    // Removed that special case so that F_SFT/J_SFT also benefit from flow-tap
    // forcing tap during rapid typing. This directly targets cross-hand rolls
    // like "fo" that were producing unwanted shifts. Snappiness for deliberate
    // shift comes from the shorter get_tapping_term + permissive/hold-on-other
    // paths + Chordal for opposite-hand.
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
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
