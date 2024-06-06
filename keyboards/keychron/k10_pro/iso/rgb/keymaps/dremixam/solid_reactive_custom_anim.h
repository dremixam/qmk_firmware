
RGB_MATRIX_EFFECT(TYPING_REACTIVE)

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_TYPING_REACTIVE

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
/*
bool effect_runner_reactive(effect_params_t* params, reactive_f effect_func) {
    LED_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / led_matrix_eeconfig.speed;
    for (uint8_t i = led_min; i < led_max; i++) {
        LED_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, led_matrix_eeconfig.speed);
        led_matrix_set_value(i, effect_func(led_matrix_eeconfig.val, offset));
    }
    return led_matrix_check_finished_leds(led_max);
}
*/
/*
static HSV TYPING_REACTIVE_math(HSV hsv, uint16_t offset) {
    hsv.v = scale8(255 - offset, hsv.v);
    return hsv;
}
*/
bool TYPING_REACTIVE(effect_params_t* params) {
    //return effect_runner_reactive(params, &TYPING_REACTIVE_math);

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);

}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
