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

    FastLed_inner = new FastLed_zone;
    int inner_positions[] = { 9,10,11,12,13,14,
                             17,            22,
                             25,            30,
                             33,            38,
                             41,            46,
                             49,50,51,52,53,54};
    FastLed_inner->init(inner_positions,20);

    FastLed_outer = new FastLed_zone;
    int outer_positions[] = { 0, 1, 2, 3, 4, 5, 6, 7,
                              8,                   15,
                              16,                  23,
                              24,                  31,
                              32,                  39,
                              40,                  47,
                              48,                  55,
                              56,57,58,59,60,61,62,63};
    FastLed_outer->init(outer_positions, 28);

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
    bool retVal = FastLed_inner->setColor(rc, gc, bc, leds, 64);
    return retVal;
}

bool FastLed_general_driver::setInnerIntensity(uint8_t intensity)
{
    FastLed_inner->setIntensity(intensity, leds, 64);
    return false;
}

bool FastLed_general_driver::setOuterColor(uint8_t rc, uint8_t gc, uint8_t bc)
{
    bool retVal = FastLed_outer->setColor(rc, gc, bc, leds, 64);
    return retVal;
}

bool FastLed_general_driver::setOuterIntensity(uint8_t intensity)
{
    FastLed_outer->setIntensity(intensity, leds, 64);
    return false;
}
