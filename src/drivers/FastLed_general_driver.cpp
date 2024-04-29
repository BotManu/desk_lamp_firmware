#include "FastLed_general_driver.h"
#include <string.h>

bool FastLed_general_driver::init()
{
    /*init all pixels to white*/
    CRGB init_led_color = CRGB(255, 255, 255);
    for (uint8_t i = 0; i < 64; i++)
        leds[i] = init_led_color;

    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS_DEFAULT);

    /*return true on success*/
    return true;
}

bool FastLed_general_driver::displayUpdate()
{
    FastLED.show();

    /*return true on success*/
    return true;
}

bool FastLed_general_driver::setDisplayIntensity(unsigned char intensity)
{
    return false;
}

bool FastLed_general_driver::setLedColor(int n_led, unsigned char red_color, unsigned char green_color, unsigned char blue_color)
{
    return false;
}
