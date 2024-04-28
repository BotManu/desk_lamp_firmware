#pragma once

class OuterLedZoneInterface {
    public:
    virtual bool init() = 0;
    virtual bool setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor);
    virtual bool setIntensity(unsigned char intensity);

};