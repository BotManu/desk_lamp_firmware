#pragma once

#include "interface/InnerLedZoneInterface.h"

class FastLed_inner: public InnerLedZoneInterface
{
public:
    bool init();
    bool setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor);
    bool setIntensity(unsigned char intensity);
};
