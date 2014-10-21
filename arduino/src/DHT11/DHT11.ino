#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>
#include "DHT11.h"

DHT11 dht11(2);
void setup(){
  Serial.begin(115200);
}
void loop(){
  Serial.println( dht11.getHum());
  Serial.println( dht11.getTem());
  Serial.println(" ");
  delay(1000);  
}
