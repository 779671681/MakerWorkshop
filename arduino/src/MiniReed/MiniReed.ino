#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

MiniReed mr(2);

void setup(){
    Serial.begin(115200);
}
void loop(){
    Serial.print("MiniReed------test");
    Serial.println(mr.getPin());    
}
