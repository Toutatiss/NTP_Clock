//Libraries
#include <DHT.h>
#include "SPI.h"
#include "TFT_22_ILI9225.h"


// Definitions
#define dataPin 10
#define DHT_Type DHT22

#define TFT_RST A4
#define TFT_RS  A3
#define TFT_CS  A5  // SS
#define TFT_SDI A2  // MOSI
#define TFT_CLK A1  // SCK
#define TFT_LED 0   // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)


DHT dht(dataPin, DHT_Type);

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED);

// Variables
float hum;
float temp;

void setup() {

  Serial.begin(9600);
  dht.begin();

  tft.begin();
  tft.setFont(Trebuchet_MS16x21);
  tft.setOrientation(3);
  tft.clear();

}

void loop() {
  // Get data
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  // Print data
  Serial.println(hum);
  Serial.println(temp);
  Serial.println("");

  tft.drawText(10, 10, String(hum));
  tft.drawText(10, 60, String(temp));
  
  delay(2000);
}
