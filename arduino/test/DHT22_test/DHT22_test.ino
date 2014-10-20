#include "DHT22.h"

DHT22 DHT(7);

void setup()
{  Serial.begin(115200);
}

void loop()
{
  Serial.println( DHT.getHum());
  Serial.println( DHT.getTem());
  
  Serial.println(" ");
  delay(1000);
}

