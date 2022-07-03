#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |Enter |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RShift|
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  =   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  -   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Slash| LAlt | Fn   | /Space  /       \Space \  | Fn   |Ctrl  | Ins  |
 *                   | Pipe |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
  OSM(MOD_LSFT),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, OSM(MOD_RSFT),
  KC_EQUAL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_MINS,
                        KC_NONUS_BACKSLASH, OSM(MOD_LALT), TG(_LOWER), KC_SPC, KC_SPC, MO(_LOWER), OSM(MOD_LCTL), KC_INSERT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |BkTick|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |MsWhlL|MsUp  |MsWhlR|MsWhlU|PrtSrc|                    |PgUp  |      |ArrowU| F11  | F12  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |MsL   |MsDn  |MsR   |MsWhlD|eacute|-------.    ,-------|PgDn  |ArrowL|ArrowD|ArrowR| Quot |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |MsBtnL|MsBtnM|MsBtnR|      |Del   |-------|    |-------|      |MsBtnL|MsBtnM|MsBtnR| Hash |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  | Win  |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
  _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_PSCR,                   KC_PGUP, _______, KC_UP, KC_F11,  KC_F12,  _______,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, UC(0x00e9),                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOTE, _______,
  _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, KC_DEL,  _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, KC_NONUS_HASH, _______,
                             _______, _______, _______, _______, _______, OSM(MOD_LGUI), _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_270;
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

static void render_logo(void) {
    // Psyduck image is 32 pixels wide, and 40 pixels high, column-major.
    // So 5 horizontal stripes, starting at the top, each containing 32 bytes.
    // Each byte represents a vertical stripe of 8 pixels.
    // static const char PROGMEM raw_logo[] = {
    //     0,  0,  0,  0,  0,  0,128, 64, 32, 16,200,168,144,136,  8,  4,  4,  4,  4,  4,  4,  4,  8, 16, 16, 62,112,168, 36, 16,  0,  0,
    //     0,  0,  0,  0,120,134,  1,  0,128,254, 73, 48, 18, 80, 25, 14,  8, 72, 16, 32, 44, 82, 97,165, 33, 18,204, 33,226, 28,112,128,
    //     0,  0,  0,  0,  0,  0,143, 81, 32, 32, 64, 64,128,128,128,128,128, 64, 64, 32, 24,  6,  5,  4, 30,  1,  0,128,128, 64, 60,  3,
    //     224, 16, 60,  4,  8, 14, 17, 96,128,  0,  0,  0,  0,  0,  0,  0,128, 64, 64,128, 64, 32,192,  1,  1,129,127, 16, 16,144, 96,  0,
    //     0,  1,  2,  4,  8,  8, 16, 16, 17, 14,  8,  8,  8, 16, 16, 16, 31, 48, 64, 64, 64, 64, 33, 21, 11,  8,  4,  4,  2,  1,  0,  0,
    // };
    // oled_write_raw_P(raw_logo, sizeof(raw_logo));
}


bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(read_layer_state(), false);
  } else {
    render_logo();
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if (record->event.pressed) {
// #ifdef OLED_ENABLE
//     set_keylog(keycode, record);
// #endif
  //   set_timelog();
  // }
  return true;
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        if (is_keyboard_master()) {
          oled_write_ln("CAPS", false);
        }
    } else {
        // Do something when Caps Word deactivates.
        if (is_keyboard_master()) {
          oled_write_ln("    ", false);
        }
    }
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (!is_keyboard_master()) {
    // oled_write_ln("HELD ", false);
    if (mods & MOD_MASK_CTRL) {
      oled_write("C", false);
    } else {
      oled_write(" ", false);
    }
    if (mods & MOD_MASK_SHIFT) {
      oled_write("S", false);
    } else {
      oled_write(" ", false);
    }
    if (mods & MOD_MASK_ALT) {
      oled_write("A", false);
    } else {
      oled_write(" ", false);
    }
    if (mods & MOD_MASK_GUI) {
      oled_write("W", false);
    } else {
      oled_write(" ", false);
    }
    if (!mods) {
      oled_write_ln("     ", false);
    }
  }
}
