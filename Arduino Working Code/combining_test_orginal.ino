//
#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include <SoftwareSerial.h>
#include <elapsedMillis.h>

#define TFT_RST A4
#define TFT_RS  A3
#define TFT_CS  A5  // SS
#define TFT_SDI A2  // MOSI
#define TFT_CLK A1  // SCK
#define TFT_LED 0   // 0 if wired to +5V directly

#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED);
//

// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionaly you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).

SoftwareSerial ESP_Serial(6, 7); //Tx,Rx
String payload;
String timeWithoutSeconds;
elapsedMillis readTime;


void setup() {
  Serial.begin(9600);
  ESP_Serial.begin(74880);
  tft.begin();
  tft.setFont(Trebuchet_MS16x21);
  tft.setOrientation(3);
  tft.clear();

}

void loop() {
  while (ESP_Serial.available() > 0)
  {
    payload = ESP_Serial.readString();
    timeWithoutSeconds = payload.substring(0, 5);  // Takes characters: XX:XX

    if (readTime >= 30000) {
    readTime = readTime - 30000;
    Serial.println(timeWithoutSeconds);
    tft.drawText(10, 10, timeWithoutSeconds);
    }
    delay(1000);
  }
}
