#pragma once

//#define USE_MATRIX_I2C

#define MASTER_LEFT
//#define MASTER_RIGHT
//#define EE_HANDS

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ // what does this do? I can't find any uses of it in the source code

#define ENCODER_DIRECTION_FLIP
#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4                                                                                                                                                                                     

#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS

#define WS2812_DI_PIN D3

#ifdef RGB_MATRIX_ENABLE
	#define RGBLED_NUM 35    // Number of LEDs
	#define RGBLED_NUM 35    // Number of LEDs
	#define RGB_MATRIX_LED_COUNT RGBLED_NUM
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM

	#define RGBLIGHT_EFFECT_RAINBOW_MOOD

    #define RGBLED_NUM 70
	//#define RGBLED_SPLIT
	#define RGBLED_SPLIT { 35, 35 } // haven't figured out how to use this yet

	//#define RGBLED_NUM 30
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
	#define RGB_MATRIX_KEYPRESSES
	//#define RGB_MATRIX_KEYRELEASES

	#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended

	#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
	//#define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5
	//#define RGB_MATRIX_LED_FLUSH_LIMIT 16
	#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
	#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT

	#define RGB_MATRIX_HUE_STEP 8
	#define RGB_MATRIX_SAT_STEP 8
	#define RGB_MATRIX_VAL_STEP 8
	#define RGB_MATRIX_SPD_STEP 10
#endif
