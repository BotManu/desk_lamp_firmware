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

    FastLed_center = new FastLed_zone;
    int center_positions[] = {18, 19, 20, 21,
                              26, 27, 28, 29,
                              34, 35, 36, 37,
                              42, 43, 44, 45};
    FastLed_center->init(center_positions, 16);

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

bool FastLed_general_driver::setCenterColor(uint8_t rc, uint8_t gc, uint8_t bc)
{
    bool retVal = FastLed_center->setColor(rc, gc, bc, leds, 64);
    return retVal;
}

bool FastLed_general_driver::setCenterIntensity(uint8_t intensity)
{
    FastLed_center->setIntensity(intensity, leds, 64);
    return false;
}

bool FastLed_general_driver::setInnnerColor(uint8_t rc, uint8_t gc, uint8_t bc)
{
    return false;
}

bool FastLed_general_driver::setOuterColor(uint8_t rc, uint8_t gc, uint8_t bc)
{
    return false;
}

bool FastLed_general_driver::setLedColor(int n_led, unsigned char red_color, unsigned char green_color, unsigned char blue_color)
{
    return false;
}
