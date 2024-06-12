/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "via.h"
#include "eeprom.h"
#include "quantum.h"

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_TYPING_REACTIVE

// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

HSV BASE_COLOR_HSV = DEFAULT_BASE_COLOR_HSV;
HSV BASE_FCT_COLOR_HSV = DEFAULT_BASE_FCT_COLOR_HSV;
HSV ACCENT_COLOR_HSV = DEFAULT_ACCENT_COLOR_HSV;
HSV PLAYSTATION_TRIANGLE_HSV = DEFAULT_PLAYSTATION_TRIANGLE_HSV;
HSV PLAYSTATION_SQUARE_HSV = DEFAULT_PLAYSTATION_SQUARE_HSV;
HSV PLAYSTATION_CIRCLE_HSV = DEFAULT_PLAYSTATION_CIRCLE_HSV;
HSV PLAYSTATION_CROSS_HSV = DEFAULT_PLAYSTATION_CROSS_HSV;

extern HSV BASE_COLOR_HSV;
extern HSV BASE_FCT_COLOR_HSV;
extern HSV ACCENT_COLOR_HSV;
extern HSV PLAYSTATION_TRIANGLE_HSV;
extern HSV PLAYSTATION_SQUARE_HSV;
extern HSV PLAYSTATION_CIRCLE_HSV;
extern HSV PLAYSTATION_CROSS_HSV;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_iso_109(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_SNAP,  KC_SIRI,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT          ),

    [MAC_FN] = LAYOUT_iso_109(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                                _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,            _______          ),

    [WIN_BASE] = LAYOUT_iso_109(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_PSCR,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT         ),
        
    [WIN_FN] = LAYOUT_iso_109(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_MOD,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                                _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,            _______          )
};

void eeconfig_update_base_color(HSV color) {
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_0, color.h);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_1, color.s);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_2, color.v);
}

void eeconfig_update_base_fct_color(HSV color) {
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_3, color.h);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_4, color.s);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_5, color.v);
}

void eeconfig_update_accent_color(HSV color) {
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_6, color.h);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_7, color.s);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_8, color.v);
}

void eeconfig_update_playstation_triangle_color(HSV color) {
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_9, color.h);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_10, color.s);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_11, color.v);
}

void eeconfig_update_playstation_square_color(HSV color) {
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_12, color.h);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_13, color.s);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_14, color.v);
}

void eeconfig_update_playstation_circle_color(HSV color) {
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_15, color.h);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_16, color.s);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_17, color.v);
}

void eeconfig_update_playstation_cross_color(HSV color) {
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_18, color.h);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_19, color.s);
    eeprom_update_byte((uint8_t*)EECONFIG_VIA_CUSTOM_20, color.v);
}

void eeconfig_read_custom_colors(void) {
  
    BASE_COLOR_HSV.h = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_0);
    BASE_COLOR_HSV.s = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_1);
    BASE_COLOR_HSV.v = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_2);

    if (BASE_COLOR_HSV.h == 0x00 && BASE_COLOR_HSV.s == 0x00 && BASE_COLOR_HSV.v == 0x00) {
        BASE_COLOR_HSV = (HSV)DEFAULT_BASE_COLOR_HSV;
        eeconfig_update_base_color(BASE_COLOR_HSV);
    }
    
    BASE_FCT_COLOR_HSV.h = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_3);
    BASE_FCT_COLOR_HSV.s = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_4);
    BASE_FCT_COLOR_HSV.v = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_5);

    if (BASE_FCT_COLOR_HSV.h == 0x00 && BASE_FCT_COLOR_HSV.s == 0x00 && BASE_FCT_COLOR_HSV.v == 0x00) {
        BASE_FCT_COLOR_HSV = (HSV)DEFAULT_BASE_FCT_COLOR_HSV;
        eeconfig_update_base_fct_color(BASE_FCT_COLOR_HSV);
    }

    ACCENT_COLOR_HSV.h = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_6);
    ACCENT_COLOR_HSV.s = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_7);
    ACCENT_COLOR_HSV.v = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_8);

    if (ACCENT_COLOR_HSV.h == 0x00 && ACCENT_COLOR_HSV.s == 0x00 && ACCENT_COLOR_HSV.v == 0x00) {
        ACCENT_COLOR_HSV = (HSV)DEFAULT_ACCENT_COLOR_HSV;
        eeconfig_update_accent_color(ACCENT_COLOR_HSV);
    }

    PLAYSTATION_TRIANGLE_HSV.h = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_9);
    PLAYSTATION_TRIANGLE_HSV.s = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_10);
    PLAYSTATION_TRIANGLE_HSV.v = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_11);

    if (PLAYSTATION_TRIANGLE_HSV.h == 0x00 && PLAYSTATION_TRIANGLE_HSV.s == 0x00 && PLAYSTATION_TRIANGLE_HSV.v == 0x00) {
        PLAYSTATION_TRIANGLE_HSV = (HSV)DEFAULT_PLAYSTATION_TRIANGLE_HSV;
        eeconfig_update_playstation_triangle_color(PLAYSTATION_TRIANGLE_HSV);
    }

    PLAYSTATION_SQUARE_HSV.h = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_12);
    PLAYSTATION_SQUARE_HSV.s = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_13);
    PLAYSTATION_SQUARE_HSV.v = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_14);

    if (PLAYSTATION_SQUARE_HSV.h == 0x00 && PLAYSTATION_SQUARE_HSV.s == 0x00 && PLAYSTATION_SQUARE_HSV.v == 0x00) {
        PLAYSTATION_SQUARE_HSV = (HSV)DEFAULT_PLAYSTATION_SQUARE_HSV;
        eeconfig_update_playstation_square_color(PLAYSTATION_SQUARE_HSV);
    }

    PLAYSTATION_CIRCLE_HSV.h = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_15);
    PLAYSTATION_CIRCLE_HSV.s = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_16);
    PLAYSTATION_CIRCLE_HSV.v = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_17);

    if (PLAYSTATION_CIRCLE_HSV.h == 0x00 && PLAYSTATION_CIRCLE_HSV.s == 0x00 && PLAYSTATION_CIRCLE_HSV.v == 0x00) {
        PLAYSTATION_CIRCLE_HSV = (HSV)DEFAULT_PLAYSTATION_CIRCLE_HSV;
        eeconfig_update_playstation_circle_color(PLAYSTATION_CIRCLE_HSV);
    }

    PLAYSTATION_CROSS_HSV.h = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_18);
    PLAYSTATION_CROSS_HSV.s = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_19);
    PLAYSTATION_CROSS_HSV.v = eeprom_read_byte((uint8_t*)EECONFIG_VIA_CUSTOM_20);

    if (PLAYSTATION_CROSS_HSV.h == 0x00 && PLAYSTATION_CROSS_HSV.s == 0x00 && PLAYSTATION_CROSS_HSV.v == 0x00) {
        PLAYSTATION_CROSS_HSV = (HSV)DEFAULT_PLAYSTATION_CROSS_HSV;
        eeconfig_update_playstation_cross_color(PLAYSTATION_CROSS_HSV);
    }
}




void matrix_init_user(void) {
  rgb_matrix_mode(RGB_MATRIX_CUSTOM_TYPING_REACTIVE);
};

void keyboard_post_init_user(void) {
    eeconfig_read_custom_colors();
}

extern void via_set_custom_color(uint8_t index, HSV color);

void via_set_custom_color(uint8_t index, HSV color) {
    switch (index) {
        case 4:
            BASE_COLOR_HSV = color;
            eeconfig_update_base_color(color);
            break;
        case 5:
            BASE_FCT_COLOR_HSV = color;
            eeconfig_update_base_fct_color(color);
            break;
        case 6:
            ACCENT_COLOR_HSV = color;
            eeconfig_update_accent_color(color);
            break;
        case 7:
            PLAYSTATION_TRIANGLE_HSV = color;
            eeconfig_update_playstation_triangle_color(color);
            break;
        case 8:
            PLAYSTATION_SQUARE_HSV = color;
            eeconfig_update_playstation_square_color(color);
            break;
        case 9:
            PLAYSTATION_CIRCLE_HSV = color;
            eeconfig_update_playstation_circle_color(color);
            break;
        case 10:
            PLAYSTATION_CROSS_HSV = color;
            eeconfig_update_playstation_cross_color(color);
            break;
    }
}

void via_process_dynamic_config(uint8_t index, uint8_t* data) {
    // Vérifier si l'index est valide (doit être compris entre 0 et 2 pour les trois couleurs)
    if (index < 7) {
        // Récupérer les valeurs HSV des données reçues depuis VIA Configurator
        HSV color;
        color.h = data[0];
        color.s = data[1];
        color.v = data[2];

        via_set_custom_color(index, color);
    }
}