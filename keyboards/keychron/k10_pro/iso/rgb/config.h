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

#pragma once

#ifdef RGB_MATRIX_ENABLE
/* RGB Matrix Driver Configuration */
#    define DRIVER_COUNT 2
#    define DRIVER_ADDR_1 0b1110111
#    define DRIVER_ADDR_2 0b1110100

/* RGB Matrix Configuration */
#    define DRIVER_1_LED_TOTAL 60
#    define DRIVER_2_LED_TOTAL 49
#    define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

/* Set to infinit, which is use in USB mode by default */
#    define RGB_MATRIX_TIMEOUT RGB_MATRIX_TIMEOUT_INFINITE

/* Allow to shutdown driver to save power */
#    define RGB_MATRIX_DRIVER_SHUTDOWN_ENABLE

/* Turn off backllit if brightness value is low */
#    define RGB_MATRIX_TURN_OFF_VAL 48

#    define NUM_LOCK_INDEX 37 // NumLock

#    define LOW_BAT_IND_INDEX 99 // Space

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects



#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS

/* Set LED driver current */
#    define SNLED27351_CURRENT_TUNE \
        { 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D }

#define EECONFIG_VIA_CUSTOM_BASE VIA_EEPROM_CUSTOM_CONFIG_ADDR

#define EECONFIG_VIA_CUSTOM_0 (EECONFIG_VIA_CUSTOM_BASE + 0)
#define EECONFIG_VIA_CUSTOM_1 (EECONFIG_VIA_CUSTOM_BASE + 1)
#define EECONFIG_VIA_CUSTOM_2 (EECONFIG_VIA_CUSTOM_BASE + 2)
#define EECONFIG_VIA_CUSTOM_3 (EECONFIG_VIA_CUSTOM_BASE + 3)
#define EECONFIG_VIA_CUSTOM_4 (EECONFIG_VIA_CUSTOM_BASE + 4)
#define EECONFIG_VIA_CUSTOM_5 (EECONFIG_VIA_CUSTOM_BASE + 5)
#define EECONFIG_VIA_CUSTOM_6 (EECONFIG_VIA_CUSTOM_BASE + 6)
#define EECONFIG_VIA_CUSTOM_7 (EECONFIG_VIA_CUSTOM_BASE + 7)
#define EECONFIG_VIA_CUSTOM_8 (EECONFIG_VIA_CUSTOM_BASE + 8)
#define EECONFIG_VIA_CUSTOM_9 (EECONFIG_VIA_CUSTOM_BASE + 9)
#define EECONFIG_VIA_CUSTOM_10 (EECONFIG_VIA_CUSTOM_BASE + 10)
#define EECONFIG_VIA_CUSTOM_11 (EECONFIG_VIA_CUSTOM_BASE + 11)
#define EECONFIG_VIA_CUSTOM_12 (EECONFIG_VIA_CUSTOM_BASE + 12)
#define EECONFIG_VIA_CUSTOM_13 (EECONFIG_VIA_CUSTOM_BASE + 13)
#define EECONFIG_VIA_CUSTOM_14 (EECONFIG_VIA_CUSTOM_BASE + 14)
#define EECONFIG_VIA_CUSTOM_15 (EECONFIG_VIA_CUSTOM_BASE + 15)
#define EECONFIG_VIA_CUSTOM_16 (EECONFIG_VIA_CUSTOM_BASE + 16)
#define EECONFIG_VIA_CUSTOM_17 (EECONFIG_VIA_CUSTOM_BASE + 17)
#define EECONFIG_VIA_CUSTOM_18 (EECONFIG_VIA_CUSTOM_BASE + 18)
#define EECONFIG_VIA_CUSTOM_19 (EECONFIG_VIA_CUSTOM_BASE + 19)
#define EECONFIG_VIA_CUSTOM_20 (EECONFIG_VIA_CUSTOM_BASE + 20)


#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 21  // Nombre d'octets réservés dans l'EEPROM pour vos paramètres

#    define DEFAULT_BASE_COLOR_HSV { .h = 190, .s = 255, .v = 255 }
#    define DEFAULT_BASE_FCT_COLOR_HSV { .h = 165, .s = 255, .v = 255 }
#    define DEFAULT_ACCENT_COLOR_HSV { .h = 85, .s = 255, .v = 255 }

#    define DEFAULT_PLAYSTATION_TRIANGLE_HSV { .h = 112, .s = 214, .v = 255 }
#    define DEFAULT_PLAYSTATION_SQUARE_HSV { .h = 213, .s = 158, .v = 255 }
#    define DEFAULT_PLAYSTATION_CIRCLE_HSV { .h = 252, .s = 173, .v = 255 }
#    define DEFAULT_PLAYSTATION_CROSS_HSV { .h = 143, .s = 148, .v = 255 }


#endif

