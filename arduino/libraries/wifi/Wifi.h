#include <aJSON.h>
#include <dht.h>
#define DHT22_PIN  7

long previousMillis = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;
int  interval1=4;
int  interval2=500;
int  interval3=10000;
unsigned long currentMillis;

float temperature,humidity;

char sample_data1[512]="POST /data/write HTTP/1.1\r\nHost: 202.120.58.116:8080\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: ";
char value[4];
dht DHT;

void setup()
{
  Serial.begin(115200);
 
}

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
   
    //temperature and humidity 
    int chk = DHT.read22(DHT22_PIN);
    if (chk==DHTLIB_OK)
    {
      temperature = DHT.temperature;
      humidity = DHT.humidity;
    }
    else
    {
      temperature = 0;
      humidity = 0;
    }
    volts=MGRead(MG_PIN);
    percentage = MGGetPercentage(volts,CO2Curve);
    //Serial.print(volts);Serial.print("\n");
  }

  //pseudo thread three to post request
  if(currentMillis - previousMillis3 > interval3) 
  {
    previousMillis3 = currentMillis; 
    // create a blank aJson object
    aJsonObject *msg = createMessage();
    //set parameter to the object
    
    add_temperature(msg, temperature);
    add_humidity(msg, humidity);
    

    char* temp=build_request(msg,"MOGE");
    post_request(temp);
    //clean the memory to avoid overflow
    aJson.deleteItem(msg);
  }
}

