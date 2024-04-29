#pragma once

#include "OuterLedZoneInterface.h"

class FastLed_outer : public OuterLedZoneInterface
{
private:
    /* data */
public:
    bool init();
    bool setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor);
    bool setIntensity(unsigned char intensity);

    FastLed_outer(/* args */);
    ~FastLed_outer();
};
