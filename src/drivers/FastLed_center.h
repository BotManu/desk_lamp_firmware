#pragma once

#include "interface/CenterLedZoneInterface.h"

class FastLed_center:public CenterLedZoneInterface {
private:
    unsigned int ledIndexes[16];
    
public:
    bool init();
    bool setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor);
    bool setIntensity(unsigned char intensity);
};