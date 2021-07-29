#include <IRremote.h>

int REC_PIN = 11;

IRrecv irrecv(REC_PIN);
decode_results results;

void setup() {
  
  Serial.begin(9600);
  irrecv.enableIRIn();
  // put your setup code here, to run once:

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    delay(1000);
  }
  // put your main code here, to run repeatedly:

}
