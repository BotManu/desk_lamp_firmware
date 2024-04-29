#pragma once
#include <Arduino.h>
#include <FastLED.h>

/*Project Specific includes*/
#include "DisplayLedInterface.h"
#include "FastLed_center.h"
#include "FastLed_inner.h"
#include "FastLed_outer.h"

/*Public library defines*/
#define LED_PIN 5
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B

class FastLed_general_driver:DisplayLedInterface{
    public:
    bool init();
    bool displayUpdate();

    bool setDisplayIntensity(unsigned char intensity);

    /*The three zones*/
    FastLed_center ZoneCenter;
    FastLed_inner ZoneInner;
    FastLed_outer ZoneOuter;

    private:
    static const unsigned char NUM_LEDS = 64;
    CRGB leds[NUM_LEDS];

    bool setLedColor(int n_led, unsigned char red_color, 
                            unsigned char green_color,
                            unsigned char blue_color);



};