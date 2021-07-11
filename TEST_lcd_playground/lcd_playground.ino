#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include "math.h"

#define TFT_RST A4
#define TFT_RS  A3
#define TFT_CS  A5  // SS
#define TFT_SDI A2  // MOSI
#define TFT_CLK A1  // SCK
#define TFT_LED 0   // 0 if wired to +5V directly

#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)

#define ROTATE_ANGLE 20 // Angle in degrees to rotate the triangle

struct _point
{
    int16_t x;
    int16_t y;
};

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED);

_point c1, c2, c3;

void setup() {
  
  c1.x = 30; c1.y = 30;
  tft.begin();
  tft.setFont(Terminal6x8);
  tft.clear();
  

}

void loop() {
  
  // put your main code here, to run repeatedly:
   // A font must be set before drawText will work
  
  tft.drawText(10, 10, "succ");
  tft.drawTriangle(30, 30, 120, 80, 80, 130, COLOR_MAGENTA);

  
  
  delay(1000);
  tft.clear();
}
