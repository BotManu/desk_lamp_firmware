#include <Arduino.h>
#include "drivers/FastLed_general_driver.h"

FastLed_general_driver LedDisplay;

void setup() {
  LedDisplay.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  LedDisplay.displayUpdate();
  delay(1000);
}
