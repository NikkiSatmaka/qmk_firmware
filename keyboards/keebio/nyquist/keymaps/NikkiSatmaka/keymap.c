/* Copyright 2022 NikkiSatmaka
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "flow.h"


enum nyquist_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAKDH,
    _QWERTY,
    _NAV,
    _FUNC,
    _SYM,
    _MOUSE,
    _ADJUST
};

enum custom_keycodes {
    KC_COLEMAKDH = SAFE_RANGE,
    KC_QWERTY,
    KC_NAV,
    KC_SYM,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    OS_FUNC
};

// Shortcut to make keymap more readable

#define L_NAV         MO(_NAV)
#define L_SYM         MO(_SYM)
#define L_FUNC        MO(_FUNC)
#define L_MOUSE       MO(_MOUSE)
#define T_QWERTY      TG(_QWERTY)
#define D_MOUSE       DF(_MOUSE)
#define D_COLEMAKDH   DF(_COLEMAKDH)

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {L_NAV, KC_LALT},
    {L_NAV, KC_LGUI},
    {L_NAV, KC_LSFT},
    {L_NAV, KC_LCTL},
    {L_NAV, KC_RALT},
    {L_FUNC, KC_LALT},
    {L_FUNC, KC_LGUI},
    {L_FUNC, KC_LSFT},
    {L_FUNC, KC_LCTL}
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_FUNC, _FUNC}
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak-DH
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   '  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  ;   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| LGUI | LAlt | LCtrl|  Nav |LShift|Space |  Sym | RCtrl| RAlt | RGUI |RShift|
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAKDH] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,     KC_6,    KC_7,    KC_8,     KC_9,    KC_0,      KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_F,     KC_P,    KC_B,     KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOT,   KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,     KC_T,    KC_G,     KC_M,    KC_N,    KC_E,     KC_I,    KC_O,      KC_SCLN,
  KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_D,    KC_V,     KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,   KC_ENT ,
  KC_LSFT, KC_LGUI, KC_LALT, KC_LCTRL, L_NAV,   KC_LSFT,  KC_SPC,  L_SYM,   KC_RCTRL, KC_RALT, KC_RGUI,   KC_RSFT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| LGUI | LAlt | LCtrl|  Nav |LShift|Space |  Sym | RCtrl| RAlt | RGUI |RShift|
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,     KC_6,    KC_7,    KC_8,     KC_9,    KC_0,      KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,      KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,     KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,   KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,   KC_ENT ,
  KC_LSFT, KC_LGUI, KC_LALT, KC_LCTRL, L_NAV,   KC_LSFT,  KC_SPC,  L_SYM,   KC_RCTRL, KC_RALT, KC_RGUI,   KC_RSFT
),

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Esc  |BackWd| Find |ForWd | Ins  |Pg Up | Home |  Up  | End  | Caps |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |O_LAlt|O_LGUI|O_LSft|O_Lctl|O_RAlt|Pg Dn | Left | Down | Right|  Del |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy | LGUI |Paste | Pscr | Bspc |  Tab | Menu | Enter|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| LGUI | LAlt | LCtrl|  Nav |LShift|Enter |Funct | RCtrl| RAlt | RGUI |RShift|
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT(
  _______, KC_F1,    KC_F2,       KC_F3,      KC_F4,       KC_F5,      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  _______, KC_ESC,   A(KC_LEFT),  C(KC_F),    A(KC_RGHT),  KC_INS,     KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_CAPS,  KC_F12,
  _______, KC_LALT,  KC_LGUI,     KC_LSFT,    KC_LCTL,     KC_RALT,    KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,   _______,
  _______, C(KC_Z),  C(KC_X),     C(KC_INS),  KC_LGUI,     S(KC_INS),  KC_PSCR,  KC_BSPC,  KC_TAB,   KC_APP,   KC_ENT,   _______,
  _______, _______,  _______,     _______,    _______,     _______,    KC_ENT,   L_FUNC,   _______,  _______,  _______,  _______
),

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | MUTE | VOLDO| PLAY | VOLUP| BRIUP|  F12 |  F7  |  F8  |  F9  |ZoomIn|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |O_LAlt|O_LGUI|O_LSft|O_Lctl| BRIDN|  F11 |  F4 |   F5  |  F6  |ZoomOut|     |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | EJECT| PREV | STOP | NEXT |      |  F10 |  F1  |  F2  |  F3  |ZoomRst|     |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| LGUI | LAlt | LCtrl|  Nav |LShift|Space |  Sym | RCtrl| RAlt | RGUI |RShift|
 * `-----------------------------------------------------------------------------------'
 */

[_FUNC] = LAYOUT(
  _______, _______, _______, _______, _______, _______,      _______, _______, _______,  _______,  _______, _______,
  _______, KC_MUTE,  KC_VOLD,  KC_MPLY,  KC_VOLU,  KC_BRIU,  KC_F12,  KC_F7,  KC_F8,  KC_F9,  C(KC_PPLS),  _______,
  _______, KC_LALT,  KC_LGUI,  KC_LSFT,  KC_LCTL,  KC_BRID,  KC_F11,  KC_F4,  KC_F5,  KC_F6,  C(KC_PMNS),  _______,
  _______, KC_EJCT,  KC_MPRV,  KC_MSTP,  KC_MNXT,  XXXXXXX,  KC_F10,  KC_F1,  KC_F2,  KC_F3,  C(KC_P0),    _______,
  _______, _______, _______, _______, _______, _______,      _______, _______, _______,  _______,  _______,  _______
),

/* SYM
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   :  |   ;  |   =  |   7  |   8  |   9  |   +  |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   \  |   |  |   {  |   (  |   [  |   *  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   \  |   |  |   }  |   )  |   ]  |   0  |   1  |   2  |   3  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| LGUI | LAlt | LCtrl| Mouse|LShift|Space |  Sym | RCtrl| RAlt | RGUI |RShift|
 * `-----------------------------------------------------------------------------------'
 */

[_SYM] = LAYOUT(
  _______, KC_F1,    KC_F2,       KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,  KC_F8,  KC_F9,  KC_F10,   KC_F11,
  _______, KC_EXLM,  KC_AT,       KC_HASH,   KC_COLN,  KC_SCLN,   KC_EQL,   KC_7,   KC_8,   KC_9,   KC_PLUS,  KC_F12,
  _______, KC_BSLS,  KC_PIPE,     KC_LCBR,   KC_LPRN,  KC_LBRC,   KC_ASTR,  KC_4,   KC_5,   KC_6,   KC_MINS,  _______,
  _______, KC_NUBS,  S(KC_NUBS),  KC_RCBR,   KC_RPRN,  KC_RBRC,   KC_0,     KC_1,   KC_2,   KC_3,   KC_SLSH,  KC_ENT,
  _______, _______,  _______,     _______,   L_MOUSE,  _______,   _______, _______, _______, _______, _______, _______
),

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |TG_QWE|      |MOUS1 | M UP |MOUS2 |M Wl U|M Acc2|   &  |   `  |   ~  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |DF_SYM|      |M LFT |M DWN |M RGHT|M Wl D|M Acc1|   $  |   %  |   ^  |   _  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |DF_CLM|M Wl L|MOUS3 |MOUS4 |MOUS5 |M Wl R|M Acc0|   !  |   @  |   #  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| LGUI | LAlt | LCtrl|  Nav |LShift|Space |  Sym | RCtrl| RAlt | RGUI |RShift|
 * `-----------------------------------------------------------------------------------'
 */

[_MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,           _______, _______, _______,  _______,  _______, _______,
  T_QWERTY,     _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  KC_ACL2,  KC_AMPR,  KC_GRV,   KC_TILD,  _______, _______,
  D_MOUSE,      _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  KC_ACL1,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_UNDS, _______,
  D_COLEMAKDH,  KC_WH_L,  KC_BTN3,  KC_BTN4,  KC_BTN5,  KC_WH_R,  KC_ACL0,  KC_EXLM,  KC_AT,    KC_HASH,  _______, _______,
  _______, _______, _______, _______, _______, _______,           _______, _______, _______,  _______,  _______,  _______
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;

    switch (keycode) {
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
                update_tri_layer(_NAV, _SYM, _ADJUST);
            } else {
                layer_off(_NAV);
                update_tri_layer(_NAV, _SYM, _ADJUST);
            }
            return false;
        case KC_SYM:
            if (record->event.pressed) {
                layer_on(_SYM);
                update_tri_layer(_NAV, _SYM, _ADJUST);
            } else {
                layer_off(_SYM);
                update_tri_layer(_NAV, _SYM, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}
