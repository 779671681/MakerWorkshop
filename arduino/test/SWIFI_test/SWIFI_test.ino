#include <aJSON.h>
#include "SensorLib.h"
#include "DHT22.h"
#include  <Wire.h>
#include  <Adafruit_GFX.h>


//定义传感器对象
DHT22                 DHT(7); 
CO2MG                co2(0);
Dust                 dust(1,2);



//定义wifi模块所需常量
long previousMillis = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;

int  interval1=10;  //4
int  interval2=700;  //500
int  interval3=10000;  //10000

unsigned long currentMillis;

char sample_data1[512]="POST /data/write HTTP/1.1\r\nHost: 10.50.6.70:8080\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: ";
char value[4];

double dustDensity =0 ;
double temperature=0;
double humidity=0;
double co2density=0;


//定义ajson数据转换函数
aJsonObject *createMessage()
{
  aJsonObject *msg = aJson.createObject();
  return msg;
}

aJsonObject *add_temperature(aJsonObject* msg,float value)
{
  aJson.addNumberToObject(msg,"temperature",value);
  return msg;
}

aJsonObject *add_humidity(aJsonObject* msg,float value)
{
  aJson.addNumberToObject(msg,"humidity",value);
  return msg;
}

aJsonObject *add_pm25(aJsonObject* msg,float value)
{
  aJson.addNumberToObject(msg,"pm2_5",value);
  return msg;
}	
	
aJsonObject *add_CO2(aJsonObject* msg,float value)
{
  aJson.addNumberToObject(msg,"co2",value);
  return msg;
}

 aJsonObject *add_text(aJsonObject* msg,char* key,char* value)
{
  aJson.addStringToObject(msg,key,value);
  return msg;
}
 

char* build_request(aJsonObject* msg, char* key)
{
  char temp[512];
  char data[256];
  char* json=aJson.print(msg);
  strcpy(temp,sample_data1);
  strcpy(data,json);
  free(json);
  int length=strlen(data);
  strcat(temp,itoa(length+13+strlen(key),value,10));
  strcat(temp,"\r\n\r\nkey=");
  strcat(temp,key);
  strcat(temp,"&content=");
  strcat(temp,data);
  strcat(temp,"\r\n");
  return temp;
}

void post_request(char* request)
{
  Serial.write(request);
}



void setup()
{
  Serial.begin(115200);
 
}


void loop()
{
  
  currentMillis = millis();
  //pseudo thread one to handle serial comminication
  if(currentMillis - previousMillis > interval1) 
  {
    previousMillis = currentMillis; 
  // display the message received from the web server, use 5 ms to avoid buffer overflow
    while(Serial.available())
    Serial.write(Serial.read());  
  }
   
   
   
  //pseudo thread two to update sensor value
  if(currentMillis - previousMillis2 > interval2) 
  {
    previousMillis2 = currentMillis; 
   
    dustDensity = dust.getDust();
    temperature = DHT.getTem();
 
    humidity  =DHT.getHum();
  
    co2density  =co2.getCO2();

 }



  //pseudo thread three to post request
  if(currentMillis - previousMillis3 > interval3) 
  {
    previousMillis3 = currentMillis; 
    // create a blank aJson object
    aJsonObject *msg = createMessage();
    //set parameter to the object
   
 
    add_pm25(msg,dustDensity);
    add_temperature(msg, temperature);
    add_humidity(msg, humidity);
    
    //there is limitation of our CO2 sensor, which is 400ppm
    if (co2density ==-1)
      add_text(msg,"CO2","< 400ppm");
    else
      add_CO2(msg,co2density);
   
   
   //post the data
    char* temp=build_request(msg,"KEEWIFI");
    post_request(temp);
    Serial.println("*************************");
    Serial.println(Serial.read());
    Serial.println("*************************");
    //clean the memory to avoid overflow
    aJson.deleteItem(msg);
  }
  delay(1000);
}


