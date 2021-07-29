// Library
#include <DHT.h>

// Definitions
#define dataPin 10
#define DHT_Type DHT22
DHT dht(dataPin, DHT_Type);

// Variables
float hum;
float temp;

void setup() {

  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // Get data
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  // Print data
  Serial.println(hum);
  Serial.println(temp);
  Serial.println("");
  delay(2000);
}
