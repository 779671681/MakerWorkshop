#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>
#include "DHT22.h"

DHT22 DHT(7);
void setup(){
  Serial.begin(115200);
}
void loop(){
  //get humidity value
  Serial.println( DHT.getHum());
  //get temperature value
  Serial.println( DHT.getTem());
  Serial.println(" ");
  delay(1000);
}
