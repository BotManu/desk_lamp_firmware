#pragma once

#include "CenterLedZoneInterface.h"

class FastLed_center:public CenterLedZoneInterface {
private:
    unsigned int ledIndexes[16];
    
public:
    FastLed_center(/* args */);
    bool init();
    bool setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor);
    bool setIntensity(unsigned char intensity);
    ~FastLed_center();
};