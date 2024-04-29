#pragma once

#include "interface/OuterLedZoneInterface.h"

class FastLed_outer : public OuterLedZoneInterface
{
public:
    bool init();
    bool setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor);
    bool setIntensity(unsigned char intensity);
};
