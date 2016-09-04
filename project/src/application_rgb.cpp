#include "application.h"

SYSTEM_MODE(MANUAL);

void setup() {
  RGB.control(true);
}

// This routine loops forever
void loop() {
  RGB.color(255, 0, 0);                 // set LED to RED
  delay(500);
  
  RGB.color(0, 255 ,0);                 // set LED to GREEN
  delay(500);
  
  RGB.color(0, 0,255);                 // set LED to BLUE
  delay(500);
}

 
