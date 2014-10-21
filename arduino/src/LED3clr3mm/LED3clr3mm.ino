#include "SensorLib.h"
#include <Adafruit_GFX.h>
#include <Wire.h>

LED3clr3mm led3clr3mm(2,3);
void setup(){
    Serial.begin(115200);
}

void loop(){
     led3clr3mm.RLED(100);
     delay(500);
     led3clr3mm.RLED(0);
     led3clr3mm.BLED(100);
     delay(500);
     led3clr3mm.BLED(0);    
}
