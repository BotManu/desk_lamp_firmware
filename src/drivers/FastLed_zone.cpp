#include "FastLed_zone.h"
#include "Arduino.h"

bool FastLed_zone::init(int activePositions[], int n_activePositions)
{
    /*initialize active positions to -1, the invalid position*/
    for (int i = 0; i < N_MAX_ACT_LEDS; i++)
    {
        activeLedPositions[i] = -1;
    }

    if (n_activePositions > N_MAX_ACT_LEDS)
        return false;

    n_activeLeds = n_activePositions;

    /*Put leds active in this zone into vector*/
    for (int i = 0; i < n_activePositions; i++)
    {
        if (activePositions[i] >= N_LEDS)
        {
            return false;
        }
        activeLedPositions[i] = activePositions[i];
    }

    return true;
}

bool FastLed_zone::setColor(unsigned char redColor, unsigned char greenColor, unsigned char blueColor, 
                   CRGB colorBuffer[], int nColors)
{
    // compose the color
    zoneColor.setRGB(redColor, greenColor, blueColor);

    // iterate through positions vtor and update colors
    for(int i=0; i<n_activeLeds;i++){
        if(activeLedPositions[i]>=nColors)
        return false;
        colorBuffer[activeLedPositions[i]] = zoneColor;
    }

    return true;
};

bool FastLed_zone::setColor(CRGB color, CRGB colorBuffer[], int nColors)
{
    // compose the color
    zoneColor = color;

    // iterate through positions vtor and update colors
    for(int i=0; i<n_activeLeds;i++){
        if(activeLedPositions[i]>=nColors)
        return false;
        colorBuffer[activeLedPositions[i]] = zoneColor;
    }

    return true;
};

bool FastLed_zone::setIntensity(unsigned char intensity,CRGB colorBuffer[], int nColors)
{
    
    uint8_t red = (uint8_t)((uint16_t)(zoneColor.r) * (uint16_t)intensity / (uint16_t)255);
    uint8_t blue = (uint8_t)((uint16_t)(zoneColor.g) * (uint16_t)intensity / (uint16_t)255);
    uint8_t green = (uint8_t)((uint16_t)(zoneColor.b) * (uint16_t)intensity / (uint16_t)255);

    

    zoneColor.setRGB(red, blue, green);

    bool retVal = setColor(zoneColor, colorBuffer, nColors);

    return retVal;
};
