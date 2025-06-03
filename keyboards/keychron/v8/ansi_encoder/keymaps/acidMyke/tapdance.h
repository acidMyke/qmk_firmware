typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_DOUBLE_SINGLE_TAP, // Send two single taps
  TD_TRIPLE_TAP,
  TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state, bool interrupt_as_hold) {
  if (state->count == 1) {
      if ((state->interrupted && !interrupt_as_hold) || !state->pressed) return TD_SINGLE_TAP;
      // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
      else return TD_SINGLE_HOLD;
  } else if (state->count == 2) {
      // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
      // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
      // keystrokes of the key, and not the 'double tap' action/macro.
      if (state->interrupted && !interrupt_as_hold) return TD_DOUBLE_SINGLE_TAP;
      else if (state->pressed) return TD_DOUBLE_HOLD;
      else return TD_DOUBLE_TAP;
  }

  // Assumes no one is trying to type the same letter three times (at least not quickly).
  // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
      if ((state->interrupted && !interrupt_as_hold) || !state->pressed) return TD_TRIPLE_TAP;
      else return TD_TRIPLE_HOLD;
  } else return TD_UNKNOWN;
}

