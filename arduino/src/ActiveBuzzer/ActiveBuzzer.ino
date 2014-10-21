#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

ActiveBuzzer active(2);
void setup(){;
}

void loop(){
    active.on();
    delay(80);
    active.off();
    delay(80);  
}
