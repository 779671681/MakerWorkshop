#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

Twoclr5mm two(2,3);

void setup(){
    Serial.begin(115200);
}

void loop(){
    two.RLED(255);
    delay(1000);
    two.RLED(0);
    two.BLED(255);
    two.BLED(0);
    delay(1000);  
}
