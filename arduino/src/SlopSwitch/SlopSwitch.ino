#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

SlopeSwitch  ss(2);
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("SlopeSwitch------test");
    Serial.println(ss.getPin());
    delay(500);
}


