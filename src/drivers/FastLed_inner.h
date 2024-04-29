#pragma once

#include "InnerLedZoneInterface.h"

class FastLed_inner: public InnerLedZoneInterface
{
private:
    /* data */
public:
    bool init();
    bool setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor);
    bool setIntensity(unsigned char intensity);
};
