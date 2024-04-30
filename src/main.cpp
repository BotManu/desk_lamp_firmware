#include <Arduino.h>
#include "drivers/FastLed_general_driver.h"

FastLed_general_driver LedDisplay;

void setup()
{
  LedDisplay.init();
  LedDisplay.setCenterColor(200, 0, 0);
  LedDisplay.setInnnerColor(0, 0, 200);
  LedDisplay.setOuterColor(0, 200, 0);
}

static uint8_t i = 0;
bool rising_edge = true;
bool falling_edge = false;
void loop()
{
  if (i == 255)
  {
    rising_edge = false;
    falling_edge = true;
  }else if(i==0){
    rising_edge = true;
    falling_edge = false;
  }

  LedDisplay.setCenterColor(200, 0, 0);
  if (rising_edge)
    LedDisplay.setCenterIntensity(i++);

  if (falling_edge)
    LedDisplay.setCenterIntensity(i--);

  LedDisplay.displayUpdate();
  delay(5);
}
