char layer_state_str[70];

#define INDICATOR_BRIGHTNESS 20

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s, Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv, Override)

#define SET_INDICATORS(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}

const rgblight_segment_t PROGMEM qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_INDICATORS(HSV_PINK));
const rgblight_segment_t PROGMEM lower_lights[]  = RGBLIGHT_LAYER_SEGMENTS(SET_INDICATORS(HSV_BLUE));
const rgblight_segment_t PROGMEM raise_lights[]  = RGBLIGHT_LAYER_SEGMENTS(SET_INDICATORS(HSV_RED));
const rgblight_segment_t PROGMEM adjust_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_INDICATORS(HSV_PURPLE));
const rgblight_segment_t PROGMEM emod_lights[]   = RGBLIGHT_LAYER_SEGMENTS(SET_INDICATORS(HSV_TEAL));
const rgblight_segment_t PROGMEM fn_lights[]     = RGBLIGHT_LAYER_SEGMENTS(SET_INDICATORS(HSV_GREEN));
const rgblight_segment_t PROGMEM numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_INDICATORS(HSV_YELLOW));

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	[_QWERTY] = qwerty_lights,
	[_LOWER]  = lower_lights,
	[_RAISE]  = raise_lights,
	[_ADJUST] = adjust_lights,
	[_EMOD]   = emod_lights,
	[_FN]     = fn_lights,
	[_NUMPAD] = numpad_lights
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
	rgblight_mode(10);
}