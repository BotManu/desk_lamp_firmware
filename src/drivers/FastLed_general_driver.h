#pragma once
#include <Arduino.h>
#include <FastLED.h>

/*Project Specific includes*/
#include "interface/DisplayLedInterface.h"

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

    /*The three zones*/

    private:
    static const unsigned char NUM_LEDS = 64;
    CRGB leds[NUM_LEDS];

    bool setLedColor(int n_led, unsigned char red_color, 
                            unsigned char green_color,
                            unsigned char blue_color);
    
    private:

};