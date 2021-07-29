#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include <SoftwareSerial.h>
#include <elapsedMillis.h>
#include <DHT.h>

#define TFT_RST A4
#define TFT_RS  A3
#define TFT_CS  A5  // SS
#define TFT_SDI A2  // MOSI
#define TFT_CLK A1  // SCK
#define TFT_LED 0   // 0 if wired to +5V directly

#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)

#define dataPin 10
#define DHT_Type DHT22
DHT dht(dataPin, DHT_Type);

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED);


SoftwareSerial ESP_Serial(6, 7); //Tx,Rx
String payload;
String date;
String dayString;
int dayInt;
String timeWithoutSeconds;
String humidity;
String temperature;
String perc = "% RH";
String cel = " C";
elapsedMillis readTime;

//Week Days
String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Month names
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


float hum;
float temp;

void setup() {
  Serial.begin(9600);
  ESP_Serial.begin(74880);
  tft.begin();
  tft.setFont(Terminal12x16);
  tft.setOrientation(3);
  tft.clear();
  dht.begin();

}

void loop() {

  
  while (ESP_Serial.available() > 0)
  {
    payload = ESP_Serial.readString();
    Serial.println(payload);
    timeWithoutSeconds = payload.substring(0, 5);  // Takes characters: XX:XX
    //day = payload.substring(10,11);
    //date = payload.substring(13, 21);
    //dayString = weekDays[dayInt)];

    //if (readTime >= 30000) {
      //readTime = readTime - 30000;
      //Serial.println(timeWithoutSeconds);
      //Serial.println(day);
      //Serial.println(date);
      tft.drawText(10, 10, timeWithoutSeconds);
    //}

    hum = dht.readHumidity();
    temp = dht.readTemperature();

    humidity = (String)hum + perc;
    temperature = (String)temp + cel;

    Serial.println(humidity);
    Serial.println(temperature);
    Serial.println("");
    tft.drawText(10, 40, humidity);
    tft.drawText(10, 70, temperature);
    delay(2000);
  
  }

  
}


String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {
    0, -1  };
  int maxIndex = data.length()-1;
  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
      found++;
      strIndex[0] = strIndex[1]+1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
