#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

MerSwitch merswitch(2);
void setup(){
  Serial.begin(115200);
}

void loop(){
        Serial.println("MerSwitch------test");
        Serial.println(merswitch.getPin());
        delay(500);
}
