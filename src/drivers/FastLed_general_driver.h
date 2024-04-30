#pragma once
#include <Arduino.h>
#include <FastLED.h>

/*Project Specific includes*/
#include "interface/DisplayLedInterface.h"
#include "FastLed_zone.h"

/*Public library defines*/
#define LED_PIN 5
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define MAX_BRIGHTNESS 120
#define BRIGHTNESS_DEFAULT  (unsigned int)(MAX_BRIGHTNESS/2)

class FastLed_general_driver:DisplayLedInterface{
    public:
    bool init();
    bool displayUpdate();

    bool setDisplayIntensity(unsigned char intensity);
    bool setCenterColor(uint8_t rc, uint8_t gc, uint8_t bc);
    bool setCenterIntensity(uint8_t intensity);

    bool setInnnerColor(uint8_t rc, uint8_t gc, uint8_t bc);
    bool setOuterColor(uint8_t rc, uint8_t gc, uint8_t bc);

    private:
    static const unsigned char NUM_LEDS = 64;
    CRGB leds[NUM_LEDS];

        /*The three zones*/
    FastLed_zone *FastLed_center;
    FastLed_zone *FastLed_inner;
    FastLed_zone *FastLed_outer;

    bool setLedColor(int n_led, unsigned char red_color, 
                            unsigned char green_color,
                            unsigned char blue_color);
    

};