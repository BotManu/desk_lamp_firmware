#pragma once
#include "FastLED.h"

class FastLed_zone{
private:
    static const int N_LEDS = 64;

    //current color of the zone
    CRGB zoneColor;
    
    /*keep the positions to be controlled by this object*/
    static const int N_MAX_ACT_LEDS = 28;
    int activeLedPositions[N_MAX_ACT_LEDS];
    int n_activeLeds; 
    
public:
    bool init(int activePositions[], int n_activePositions);
    bool setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor, 
                   CRGB colorBuffer[], int nColors);
    bool setIntensity(unsigned char intensity,CRGB colorBuffer[], int nColors);
    bool setColor(CRGB color, CRGB colorBuffer[], int nColors);
};