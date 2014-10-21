#include  "SensorLib.h"
#include  "DHT22.h"
#include  "DHT11.h"
#include  <Wire.h>
#include  <Adafruit_GFX.h>

LED3clr		led3clr(1,2,3);//DigtalPin:R, G, B

void setup(){
}

void loop(){
        int val;
	for(val=255; val>0; val--){     
            led3clr.RLED(val);      
            led3clr.GLED(255-val);   
            led3clr.BLED(128-val);  
            delay(1);         
        }

	for(val=255; val>0; val--){
		led3clr.BLED(val);
		led3clr.RLED(255-val);
		led3clr.GLED(128-val);
		delay(1);
	}

	for(val=255; val>0; val--){
		led3clr.GLED(val);
		led3clr.BLED(255-val);
		led3clr.RLED(128-val);
	        delay(1);
	} 
}
