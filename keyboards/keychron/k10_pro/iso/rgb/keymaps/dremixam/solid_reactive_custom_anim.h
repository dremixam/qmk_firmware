RGB_MATRIX_EFFECT(TYPING_REACTIVE)

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_TYPING_REACTIVE

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#    define RED 0
#    define GREEN 120
#    define BLUE 240

// Fonction de conversion HSV -> RGB
RGB hsvToRgb(HSV hsv) {
    float r, g, b;
    float h = hsv.h / 60.0;
    float s = hsv.s / 255.0;
    float v = hsv.v / 255.0;

    int i = (int)h;
    float f = h - i;
    float p = v * (1 - s);
    float q = v * (1 - s * f);
    float t = v * (1 - s * (1 - f));

    switch (i) {
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        default: r = v; g = p; b = q; break;
    }

    RGB rgb = { (int)(r * 255), (int)(g * 255), (int)(b * 255) };
    return rgb;
}

// Fonction de conversion RGB -> HSV
HSV rgbToHsv(RGB rgb) {
    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;

    float max = fmaxf(fmaxf(r, g), b);
    float min = fminf(fminf(r, g), b);
    float delta = max - min;

    float h, s, v = max;

    if (delta == 0) {
        h = 0;
    } else if (max == r) {
        h = 60 * fmod(((g - b) / delta), 6);
    } else if (max == g) {
        h = 60 * (((b - r) / delta) + 2);
    } else {
        h = 60 * (((r - g) / delta) + 4);
    }

    if (max == 0) {
        s = 0;
    } else {
        s = delta / max;
    }

    HSV hsv = { (int)(h < 0 ? h + 360 : h), (int)(s * 255), (int)(v * 255) };
    return hsv;
}

// Fonction pour interpoler entre deux valeurs entières
int interpolate(int start, int end, int offset) {
    return start + (end - start) * offset / 255;
}

// Fonction principale pour interpoler entre deux couleurs HSV
HSV interpolateHSV(HSV start, HSV end, int offset) {
    // Conversion HSV -> RGB
    RGB rgbStart = hsvToRgb(start);
    RGB rgbEnd = hsvToRgb(end);
    
    // Interpolation directe en RGB
    RGB rgbResult;
    rgbResult.r = interpolate(rgbStart.r, rgbEnd.r, offset);
    rgbResult.g = interpolate(rgbStart.g, rgbEnd.g, offset);
    rgbResult.b = interpolate(rgbStart.b, rgbEnd.b, offset);
    
    // Conversion RGB -> HSV
    HSV hsvResult = rgbToHsv(rgbResult);
    
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