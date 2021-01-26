#include QMK_KEYBOARD_H

enum idobo_layers {
  _QWERTY,
  _WORKMAN,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum idobo_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN
};


// Tap Dance keycodes
enum td_keycodes {
  RAISE_OSMLSFT // `layer_on(_RAISE)` when held, `LSFT` when tapped.
};

// Define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
uint8_t current_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void raise_osmlsft_finished(qk_tap_dance_state_t *state, void *user_data);
void raise_osmlsft_reset(qk_tap_dance_state_t *state, void *user_data);

// Shorthanded keycodes
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ROSMS TD(RAISE_OSMLSFT)
#define C_ESC MT(MOD_LCTL,KC_ESC)
#define L_ENT LT(_LOWER,KC_ENT)
#define S_SPC MT(MOD_LSFT,KC_SPC)
#define S_LB  MT(MOD_LSFT,KC_LBRC)
#define S_RB  MT(MOD_LSFT,KC_RBRC)
#define G_SPC G(KC_SPC)

// Main keymap sections
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,--------------------------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   -  |G_SPC |   =  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |      |      |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+----------------------------------+------+------+------+------+------|
 * |C_ESC |   A  |   S  |   D  |   F  |   G  |      |      |      |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------|------|------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |      |      |      |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |ROSMS |S_SPC |Space |      |      | Bksp |L_ENT | Left | Down |  Up  |Right |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x15( \
  KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,  KC_MINS, G_SPC,   KC_EQL,  KC_6,      KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,  XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,      KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS, \
  C_ESC,   KC_A,    KC_S,    KC_D,     KC_F,    KC_G,  XXXXXXX, XXXXXXX, XXXXXXX, KC_H,      KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,  XXXXXXX, XXXXXXX, XXXXXXX, KC_N,      KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI,  ROSMS,   S_SPC, KC_SPC,  XXXXXXX, XXXXXXX, KC_BSPC,   L_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Workman
 * ,--------------------------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   -  |G_SPC |   =  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |      |      |      |   J  |   F  |   U  |   P  |   ;  |  \   |
 * |------+------+------+------+------+----------------------------------+------+------+------+------+------|
 * |C_ESC |   A  |   S  |   H  |   T  |   G  |      |      |      |   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------|------|------|------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   M  |   C  |   V  |      |      |      |   K  |   L  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |ROSMS |S_SPC |Space |      |      | Bksp |L_ENT | Left | Down |  Up  |Right |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT_ortho_5x15( \
  KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,  KC_MINS, G_SPC,   KC_EQL,  KC_6,      KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_D,    KC_R,     KC_W,    KC_B,  XXXXXXX, XXXXXXX, XXXXXXX, KC_J,      KC_F,  KC_U,    KC_P,    KC_SCLN, KC_BSLS, \
  C_ESC,   KC_A,    KC_S,    KC_H,     KC_T,    KC_G,  XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,      KC_N,  KC_E,    KC_O,    KC_I,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_M,     KC_C,    KC_V,  XXXXXXX, XXXXXXX, XXXXXXX, KC_K,      KC_L,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI,  ROSMS,   S_SPC, KC_SPC,  XXXXXXX, XXXXXXX, KC_BSPC,   L_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      |      |      |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   Y  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|------|------|------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 */
[_LOWER] = LAYOUT_ortho_5x15(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x15(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |AGnorm|AGswap|Qwerty|Wrkman|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x15(
  _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
  _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, QWERTY,  WORKMAN, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
  }
  return true;
}

// Determine the tapdance state to return
uint8_t current_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else return 2; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:
void raise_osmlsft_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = current_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      set_oneshot_mods(MOD_BIT(KC_LSFT));
      break;
    case SINGLE_HOLD:
      layer_on(_RAISE);
      break;
    default:
      break;
  }
}

void raise_osmlsft_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      break;
    case SINGLE_HOLD:
      layer_off(_RAISE);
      break;
    default:
      break;
  }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
  [RAISE_OSMLSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, raise_osmlsft_finished, raise_osmlsft_reset)
};
