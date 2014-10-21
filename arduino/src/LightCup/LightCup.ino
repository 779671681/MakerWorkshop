#include  "SensorLib.h"
#include  <Adafruit_GFX.h>

LightCup lightcup(1, 2, 3, 4);//digtal pin

void setup(void){
    Serial.begin(115200);
}

void loop(){
    lightcup.on();
    delay(2000);
    lightcup.off();
}
