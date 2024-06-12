RGB_MATRIX_EFFECT(TYPING_REACTIVE)

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_TYPING_REACTIVE

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

enum physical_keys {
    PK_ESC      = 0x00,
    PK_F1       = 0x01,
    PK_F2       = 0x02,
    PK_F3       = 0x03,
    PK_F4       = 0x04,
    PK_F5       = 0x05,
    PK_F6       = 0x06,
    PK_F7       = 0x07,
    PK_F8       = 0x08,
    PK_F9       = 0x09,
    PK_F10      = 0x0A,
    PK_F11      = 0x0B,
    PK_F12      = 0x0C,
    PK_PSCR     = 0x0D,
    PK_MIC      = 0x0E,
    PK_RGB      = 0x0F,
    PK_CIRCLE   = 0x10,
    PK_TRIANGLE = 0x11,
    PK_SQUARE   = 0x12,
    PK_CROSS    = 0x13,
    PK_GRV      = 0x14,
    PK_1        = 0x15,
    PK_2        = 0x16,
    PK_3        = 0x17,
    PK_4        = 0x18,
    PK_5        = 0x19,
    PK_6        = 0x1A,
    PK_7        = 0x1B,
    PK_8        = 0x1C,
    PK_9        = 0x1D,
    PK_0        = 0x1E,
    PK_MINS     = 0x1F,
    PK_EQL      = 0x20,
    PK_BSPC     = 0x21,
    PK_INS      = 0x22,
    PK_HOME     = 0x23,
    PK_PGUP     = 0x24,
    PK_NUM      = 0x25,
    PK_PSLS     = 0x26,
    PK_PAST     = 0x27,
    PK_PMNS     = 0x28,
    PK_TAB      = 0x29,
    PK_Q        = 0x2A,
    PK_W        = 0x2B,
    PK_E        = 0x2C,
    PK_R        = 0x2D,
    PK_T        = 0x2E,
    PK_Y        = 0x2F,
    PK_U        = 0x30,
    PK_I        = 0x31,
    PK_O        = 0x32,
    PK_P        = 0x33,
    PK_LBRC     = 0x34,
    PK_RBRC     = 0x35,
    PK_DEL      = 0x36,
    PK_END      = 0x37,
    PK_PGDN     = 0x38,
    PK_P7       = 0x39,
    PK_P8       = 0x3A,
    PK_P9       = 0x3B,
    PK_PPLS     = 0x3C,
    PK_CAPS     = 0x3D,
    PK_A        = 0x3E,
    PK_S        = 0x3F,
    PK_D        = 0x40,
    PK_F        = 0x41,
    PK_G        = 0x42,
    PK_H        = 0x43,
    PK_J        = 0x44,
    PK_K        = 0x45,
    PK_L        = 0x46,
    PK_SCLN     = 0x47,
    PK_QUOT     = 0x48,
    PK_NUHS     = 0x49,
    PK_ENT      = 0x4A,
    PK_P4       = 0x4B,
    PK_P5       = 0x4C,
    PK_P6       = 0x4D,
    PK_LSFT     = 0x4E,
    PK_NUBS     = 0x4F,
    PK_Z        = 0x50,
    PK_X        = 0x51,
    PK_C        = 0x52,
    PK_V        = 0x53,
    PK_B        = 0x54,
    PK_N        = 0x55,
    PK_M        = 0x56,
    PK_COMM     = 0x57,
    PK_DOT      = 0x58,
    PK_SLSH     = 0x59,
    PK_RSFT     = 0x5A,
    PK_UP       = 0x5B,
    PK_P1       = 0x5C,
    PK_P2       = 0x5D,
    PK_P3       = 0x5E,
    PK_PENT     = 0x5F,
    PK_LCTL     = 0x60,
    PK_LSYS     = 0x61,
    PK_LALT     = 0x62,
    PK_SPC      = 0x63,
    PK_RALT     = 0x64,
    PK_RSYS     = 0x65,
    PK_FN       = 0x66,
    PK_RCTL     = 0x67,
    PK_LEFT     = 0x68,
    PK_DOWN     = 0x69,
    PK_RGHT     = 0x6A,
    PK_P0       = 0x6B,
    PK_PDOT     = 0x6C
};

#    include QMK_KEYBOARD_H

extern HSV BASE_COLOR_HSV;
extern HSV BASE_FCT_COLOR_HSV;
extern HSV ACCENT_COLOR_HSV;
extern HSV PLAYSTATION_TRIANGLE_HSV;
extern HSV PLAYSTATION_SQUARE_HSV;
extern HSV PLAYSTATION_CIRCLE_HSV;
extern HSV PLAYSTATION_CROSS_HSV;

// Fonction de conversion RGB -> HSV
HSV rgb_to_hsv(RGB rgb) {
    HSV     hsv;
    uint8_t rgb_min, rgb_max;

    rgb_min = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
    rgb_max = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);

    hsv.v = rgb_max;
    if (hsv.v == 0) {
        hsv.h = 0;
        hsv.s = 0;
        return hsv;
    }

    hsv.s = 255 * (rgb_max - rgb_min) / hsv.v;
    if (hsv.s == 0) {
        hsv.h = 0;
        return hsv;
    }

    if (rgb_max == rgb.r) {
        hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgb_max - rgb_min);
    } else if (rgb_max == rgb.g) {
        hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgb_max - rgb_min);
    } else {
        hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgb_max - rgb_min);
    }

    return hsv;
}

// Fonction pour interpoler entre deux valeurs entières
int interpolate(int start, int end, int offset) {
    return start + (end - start) * offset / 255;
}

// Fonction principale pour interpoler entre deux couleurs HSV
HSV interpolateHSV(HSV start, HSV end, int offset) {
    // Conversion HSV -> RGB
    RGB rgbStart = rgb_matrix_hsv_to_rgb(start);
    RGB rgbEnd   = rgb_matrix_hsv_to_rgb(end);

    // Interpolation directe en RGB
    RGB rgbResult;
    rgbResult.r = interpolate(rgbStart.r, rgbEnd.r, offset);
    rgbResult.g = interpolate(rgbStart.g, rgbEnd.g, offset);
    rgbResult.b = interpolate(rgbStart.b, rgbEnd.b, offset);

    // Conversion RGB -> HSV
    HSV hsvResult = rgb_to_hsv(rgbResult);

    return hsvResult;
}

static HSV TYPING_REACTIVE_math(HSV hsv, uint16_t offset) {
    return interpolateHSV(ACCENT_COLOR_HSV, hsv, offset);
}

bool effect_runner_reactive_custom(effect_params_t* params, reactive_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed / 8, 1);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        HSV color = BASE_FCT_COLOR_HSV;

        switch (i) {
            case PK_Q:
            case PK_W:
            case PK_E:
            case PK_R:
            case PK_T:
            case PK_Y:
            case PK_U:
            case PK_I:
            case PK_O:
            case PK_P:
            case PK_LBRC:
            case PK_RBRC:
            case PK_A:
            case PK_S:
            case PK_D:
            case PK_F:
            case PK_G:
            case PK_H:
            case PK_J:
            case PK_K:
            case PK_L:
            case PK_SCLN:
            case PK_QUOT:
            case PK_Z:
            case PK_X:
            case PK_C:
            case PK_V:
            case PK_B:
            case PK_N:
            case PK_M:
            case PK_COMM:
            case PK_DOT:
            case PK_SLSH:
            case PK_SPC:
            case PK_P0:
            case PK_P1:
            case PK_P2:
            case PK_P3:
            case PK_P4:
            case PK_P5:
            case PK_P6:
            case PK_P7:
            case PK_P8:
            case PK_P9:
            case PK_PDOT:
            case PK_1:
            case PK_2:
            case PK_3:
            case PK_4:
            case PK_5:
            case PK_6:
            case PK_7:
            case PK_8:
            case PK_9:
            case PK_0:
            case PK_MINS:
            case PK_EQL:
            case PK_LEFT:
            case PK_DOWN:
            case PK_RGHT:
            case PK_UP:
                color = BASE_COLOR_HSV;
                break;
            case PK_CIRCLE:
                color = PLAYSTATION_CIRCLE_HSV;
                break;
            case PK_CROSS:
                color = PLAYSTATION_CROSS_HSV;
                break;
            case PK_SQUARE:
                color = PLAYSTATION_SQUARE_HSV;
                break;
            case PK_TRIANGLE:
                color = PLAYSTATION_TRIANGLE_HSV;
                break;
        }

        uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed / 8, 1));

        HSV hsv = effect_func(color, offset);
        hsv.v   = rgb_matrix_get_val();
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool TYPING_REACTIVE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return effect_runner_reactive_custom(params, &TYPING_REACTIVE_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS