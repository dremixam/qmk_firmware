RGB_MATRIX_EFFECT(TYPING_REACTIVE)

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_TYPING_REACTIVE

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#    define RED (uint8_t)((0 * 255) / 360)
#    define GREEN (uint8_t)((120 * 255) / 360)
#    define BLUE (uint8_t)((240 * 255) / 360)

// Fonction de conversion RGB -> HSV
HSV rgb_to_hsv(RGB rgb) {
    HSV hsv;
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
    RGB rgbEnd = rgb_matrix_hsv_to_rgb(end);
    
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
    HSV start = {.h = GREEN, .s = 255, .v = 255};
    return interpolateHSV(start, hsv, offset);
}

bool TYPING_REACTIVE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return effect_runner_reactive(params, &TYPING_REACTIVE_math) && rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS