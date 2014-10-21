#include  <Wire.h>
#include  <Adafruit_GFX.h>
#include  "SensorLib.h"

JoyStick	        JS(1,2,3);//anolog pin

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.print("x: ");
    Serial.print(JS.getX());   
    Serial.print("   y: ");
    Serial.print(JS.getY());
    Serial.print("   z: ");
    Serial.println(JS.getZ());
    delay(1000);
}
