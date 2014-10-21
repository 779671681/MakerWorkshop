#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

ReedSwitch reed(2);
void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.print("ReedSwitch------test");
  Serial.println(reed.getPin()); 
}
