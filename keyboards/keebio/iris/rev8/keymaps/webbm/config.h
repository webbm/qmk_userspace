#pragma once


// Timeout for mod taps, layer taps, etc
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

// Disable auto-repeat of tap action on tap-then-hold of the same dual-role key.
// Essential for HRMs (avoids "llllllllcase" when intending camelCase or repeated letters).
// We set the global to 0 for safety on most mod-taps, but use QUICK_TAP_TERM_PER_KEY
// (see get_quick_tap_term in keymap.c) to re-enable the "tap then hold to repeat letter"
// behavior specifically for Vim navigation keys (j/k/l on the right home row).
#define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY

#define PERMISSIVE_HOLD_PER_KEY

// Force fast consecutive tap-hold presses to resolve as taps (helps with home row mods while typing).
// Complements Chordal Hold: during rapid typing flow, lean toward tap for HRMs to avoid
// accidental mods like "fo" -> "O" (user's reported "food" problem).
#define FLOW_TAP_TERM 150

// Specify get-hold config on a key-by-key basis.
// Chordal Hold (same-hand rolls -> tap; opposite-hand can use permissive for snappy mods)
// is the modern recommended foundation per Getreuer/pgetreuer, ZSA Chordal Hold post, and
// community consensus (2025-2026). See precondition guide and urob "timeless" ports for background.
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Keep custom toggle state in sync across the split halves (for per-half RGB Matrix)
#define SPLIT_TRANSACTION_IDS_USER JJ_STATE_SYNC

// Default RGB Matrix state: enabled but "off" (solid black). This prevents the default animations
// from running unless you explicitly turn them on.
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 0
