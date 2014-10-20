#include  "SensorLib.h"
#include  "DHT22.h"
#include  "DHT11.h"
#include  <Wire.h>
#include  <Adafruit_GFX.h>

/*

以下类 定义了 on 函数 和 off: 函数 （有些有getPin（） 函数）
LightCup         on：    off：
HallMagentic     on：    off：   getPin():
Relay			 on：    off：
LinearHall       on：    off：
LED7Flash        on：    off：
LaserEmit        on：    off：
以下类  只定义了 getPin() 函数  getPin()用来获得传感器的最直接的测量值，一般返回的是高地电平
MiniReed	
RotaryEncoders
AnalogHall         
Tap               
LightBlocking    
Avoid          
ReedSwitch   
Shock
Tracking
PhotoResistor 
Button
Flame
LED3clr	
Pulse         
LightCup       
HallMagentic    
Relay	    
LinearHall
LED3Fclr	
LED7Flash     
MerSwitch      
Temp
BigSound	    
Touch
Twoclr5mm	
LaserEmit     
SlopeSwitch	  

*/
//JoyStick	        JS(1,2,3);
//Flame			flame(1);
//LED3clr		led3clr(1,2,3);
//Pulse                 pulse(2);
//LightCup       	lightcup(1,2,3,4);
//HallMagentic          HM(2);
//Relay	    	        RY(1);
//LinearHall		LH(2);
//LED3Fclr	        led3fclr(2,3,4);
//LED7Flash             led7flash(2);
//MerSwitch             merswitch(2);
//Temp                  temp();
//BigSound	        bigsound(2,3);
//Touch                 touch(2);
//Twoclr5mm	        two(2,3);
//LaserEmit             laseremit(2);
//SlopeSwitch	        ss(2);
//AnalogTemp            at(2);
//SmallSound	        smallsound(2,3);
//DigitalTemp           dt(2);
//LED3clr3mm            led3clr3mm(2,3);   
//Button                button(2);
//PhotoResistor         photoresistor(2);
////IRemission	        iremission();
//Tracking	        tracking(2);
//ActiveBuzzer          active(2);
//ReedSwitch            reed(2);
//Shock		        shock(2);
//DHT11               dht11(2); 
////IRremote            irremote(2);
//Avoid                 avoid(2);
//PassiveBuzzer         pb(2);
//MiniReed	        mr(2);
////RotaryEncoders      re(2);
//AnalogHall            ah(2);    
//Tap                   tap(2);  
//LightBlocking         lb(2);

//OLED                  Oled(10,11,8,9);//(int8_t SDA, int8_t SCL, int8_t DC, int8_t RST) 
//DHT22                 DHT(7); 
//CO2MG                 co2(0);
Dust                   dust(1,2);
static unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


int val = 0;


void setup(){
	Serial.begin(115200);
}

void loop(){
     
/******************************************************************************/
//                      验证JoyStick      JS(2,3,4);
/******************************************************************************/
//	Serial.print("x: ");
//	Serial.print(JS.getX());   
//	Serial.print("   y: ");
//	Serial.print(JS.getY());
//	Serial.print("   z: ");
//	Serial.println(JS.getZ());
//      delay(1000);





/******************************************************************************/
//	               验证Flame	  flame(2);	
/******************************************************************************/	
//	Serial.print("flame: ");
//	Serial.println(flame.getPin());
	
	


	
/******************************************************************************/	
//	              验证LED3clr        led3clr(2,3,4);
/******************************************************************************/
//	for(val=255; val>0; val--){     //val从255到0每次减1
//            led3clr.RLED(val);      //调用led3clr类中的函数RLED();红色LED亮度值等于val
//            led3clr.GLED(255-val);   //调用led3clr类中的函数GLED();绿色LED亮度值等于255-val
//            led3clr.BLED(128-val);  //调用led3clr类中的函数BLED();蓝色LED亮度值等于128-val
//            delay(1);         //持续时间为1
//        }
//
//	for(val=255; val>0; val--){
//		led3clr.BLED(val);
//		led3clr.RLED(255-val);
//		led3clr.GLED(128-val);
//		delay(1);
//	}
//
//	for(val=255; val>0; val--){
//		led3clr.GLED(val);
//		led3clr.BLED(255-val);
//		led3clr.RLED(128-val);
//	        delay(1);
//	}
	
	
	
/******************************************************************************/
//                   验证Pulse                   pulse(2);
/******************************************************************************/
	
	
	
	
/******************************************************************************/	
//                   验证LightCup       	lightcup(2,3,4,5);
/******************************************************************************/
//	lightcup.on();
//	delay(2000);
//      lightcup.off();
	
	
/******************************************************************************/	
//                   验证HallMagentic            HM(2);
/******************************************************************************/
//	Serial.println("HallMagentic------Test");
//	Serial.println(HM.getPin());
//	delay(1000);
	
/******************************************************************************/
//                   验证Relay	                	RY(2);
/******************************************************************************/
//		RY.on();
//		delay(1000);
//		RY.off();
//              delay(1000);
/******************************************************************************/
//                   验证LinearHall		        LH(2);
/******************************************************************************/
//	Serial.println("LinearHall------Test");
//	Serial.println(LH.getPin());
//	delay(100);
	

/******************************************************************************/
//                    验证LED3Fclr	    led3fclr(2,3,4);
/******************************************************************************/
//	for(val=255; val>0; val--){     //val从255到0每次减1
//            led3fclr.RLED(val);      //调用led3clr类中的函数RLED();红色LED亮度值等于val
//            led3fclr.GLED(255-val);   //调用led3clr类中的函数GLED();绿色LED亮度值等于255-val
//            led3fclr.BLED(128-val);  //调用led3clr类中的函数BLED();蓝色LED亮度值等于128-val
//          delay(1);         //持续时间为1
//         }
//
//	for(val=255; val>0; val--){
//		led3fclr.BLED(val);
//		led3fclr.RLED(255-val);
//		led3fclr.GLED(128-val);
//		delay(1);
//	}
//
//	for(val=255; val>0; val--){
//		led3fclr.GLED(val);
//		led3fclr.BLED(255-val);
//		led3fclr.RLED(128-val);
//	    delay(1);
//	}
	
/******************************************************************************/
//                    验证LED7Flash       led7flash(2);led7flash
/******************************************************************************/
//	led7flash.on();
//	delay(2000);
//	led7flash.off();
//        delay(2000);



/******************************************************************************/
//                   验证MerSwitch       merswitch(2);
/******************************************************************************/
//        Serial.println("MerSwitch------test");
//        Serial.println(merswitch.getPin());
//        delay(500);


/******************************************************************************/
//                   验证Temp       temp(2);
/******************************************************************************/










/******************************************************************************/
//                    验证BigSound	    bigsound(2,3);
/******************************************************************************/
//      Serial.println("bigsound----test");
//      Serial.println(bigsound.getAO());
//      Serial.println(bigsound.getDO());
//      delay(500);

/******************************************************************************/
//                    验证Touch           touch(2);
/******************************************************************************/
//        Serial.println("Touch------test");
//        Serial.println(touch.getPin());
//        delay(500);

/******************************************************************************/
//                    验证Twoclr5mm	    two(2,3);
/******************************************************************************/
//        two.RLED(255);
//        delay(1000);
//        two.RLED(0);
//        two.BLED(255);
//        two.BLED(0);
//        delay(1000);
/******************************************************************************/
//                      验证LaserEmit       laseremit(2);
/******************************************************************************/
//        laseremit.on();
//        delay(500);
//        laseremit.off();
//        delay(500);
/******************************************************************************/
//                      验证SlopeSwitch	    ss(2);
/******************************************************************************/
//        Serial.println("SlopeSwitch------test");
//        Serial.println(ss.getPin());
//        delay(500);
/******************************************************************************/
//                      验证AnalogTemp      at(2);
/******************************************************************************/
//        Serial.println("Analogtemp------test");
//        Serial.println(at.getPin());
//        delay(500);


/******************************************************************************/
//                      验证SmallSound	    smallsound(2,3);
/******************************************************************************/
//        Serial.println("smallsound------test");
//        Serial.println(smallsound.getAO());
//        Serial.println(smallsound.getDO());
//        delay(500);


/******************************************************************************/
//                     验证DigitalTemp      dt(2);
/******************************************************************************/

//        Serial.println("digitaltemp------test");
//        Serial.println(dt.getPin());
//        delay(500);

/******************************************************************************/
//                     验证LED3clr3mm      led3clr3mm(2,3); 
/******************************************************************************/
//        led3clr3mm.RLED(100);
//       delay(500);
//        led3clr3mm.RLED(0);
//        led3clr3mm.BLED(100);
//        delay(500);
//        led3clr3mm.BLED(0);
/******************************************************************************/
//                    验证Button		    button(2);
/******************************************************************************/
//        Serial.println("Button------test");
//        Serial.println(button.getPin());
//        delay(500);

/******************************************************************************/
//                    验证PhotoResistor             photoresistor(2);
/******************************************************************************/
//        Serial.println("PhotoResistor------test");
//        Serial.println(photoresistor.getPin());
//        delay(500);

/******************************************************************************/
//                    验证Tracking	    tracking(2);
/******************************************************************************/
//        Serial.println("Tracking------test");
//        Serial.println(tracking.getPin());
//        delay(500);
        
/******************************************************************************/
//                    验证ActiveBuzzer    active(2);
/******************************************************************************/
//        active.on();
//        delay(1000);
//        active.off();
//        delay(1000);


/******************************************************************************/
//                    验证ReedSwitch      reed(2);
/******************************************************************************/
  
//        Serial.print("ReedSwitch------test");
//        Serial.println(reed.getPin());


/******************************************************************************/
//                    验证Shock		    shock(2);
/******************************************************************************/
        
//        Serial.print("Shock------test");
//          val=shock.getPin();
//    if(val==HIGH){
//        digitalWrite(13,LOW);
//     }
//    else{
//        digitalWrite(13,HIGH);
//    }
      
        
/******************************************************************************/
//                    验证DHT11           dht11(2); 
/******************************************************************************/

//  Serial.println( dht11.getHum());
//  Serial.println( dht11.getTem());
//  Serial.println(" ");
//  delay(1000);


/******************************************************************************/
//                    验证Avoid           avoid(2);
/******************************************************************************/
//       Serial.println("Avoid------test");
//       Serial.println(avoid.getPin());
//       delay(500);
       
       
/******************************************************************************/
//                   验证MiniReed	    mr(2);
/******************************************************************************/

//      Serial.print("MiniReed------test");
//      Serial.println(mr.getPin());
      
/******************************************************************************/
//                  验证AnalogHall      ah(2);
/******************************************************************************/
//      Serial.print("AnalogHall------test");
//      Serial.println(ah.getPin());


/******************************************************************************/    
//                 验证Tap             tap(2);  
/******************************************************************************/
//      Serial.print("tap------test");
//      Serial.println(tap.getPin());
//      delay(500);

/******************************************************************************/
//               验证           LightBlocking   lb(2);
/******************************************************************************/

//      Serial.print("LightBlocking------test");
//      Serial.println(lb.getPin());
//      delay(500);


/******************************************************************************/
//               验证          DHT22                 DHT(7);
/******************************************************************************/

//  Serial.println( DHT.getHum());
//  Serial.println( DHT.getTem());
//  Serial.println(" ");
//  delay(1000);
//



/*****************************************************************************/
//             验证            OLED                 Ole
/*****************************************************************************/
//  Oled.begin(SSD1306_SWITCHCAPVCC);
//  // init done  used to show the logo of the vender
//  Oled.display(); // show splashscreen
//  delay(2000);
//  Oled.clearDisplay();   // clears the screen and buffer
//  Oled.drawPixel(10, 10);
//  Oled.display();
//  delay(1000);
//  Oled.clearDisplay();   // clears the screen and buffer


/*****************************************************************************/
//             验证            CO2MG                 co2（0）
/*****************************************************************************/

//  co2.on();
//  Serial.println(co2.getPin());
//  Serial.println(co2.getCO2());


/*****************************************************************************/
//             验证            CO2MG                 co2（0）
/*****************************************************************************/

//Serial.println(dust.getPin());
Serial.println(dust.getDust());
//Serial.println(dust.getvol());
Serial.println(" ");

delay(1000);

}





 

