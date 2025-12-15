#pragma once


// Timeout for mod taps, layer taps, etc
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Specify get-hold config on a key-by-key basis
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Keep custom toggle state in sync across the split halves (for per-half RGB Matrix)
#define SPLIT_TRANSACTION_IDS_USER JJ_STATE_SYNC

// Default RGB Matrix state: enabled but "off" (solid black). This prevents the default animations
// from running unless you explicitly turn them on.
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 0
