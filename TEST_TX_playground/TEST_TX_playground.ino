#include <IRremote.h>

unsigned int power1[] = {2380,570,880,570,880,570,930,1220,880,1220,880,570,880,570,880,570,880,570,930,570,880,570,880,570,880,570,930,520,930,1170,930,1170,880};  // Protocol=UNKNOWN Hash=0x0 17 bits received
unsigned int power2[] = {2330,620,880,570,880,620,830,1270,880,1220,880,570,880,570,880,570,830,670,830,620,880,570,880,570,880,570,880,570,880,570,880,570,880};  // Protocol=UNKNOWN Hash=0x0 17 bits received
unsigned int power3[] = {2380,570,880,570,930,520,930,1220,880,1220,880,570,880,570,880,570,880,620,880,570,880,570,880,570,930,520,930,520,930,520,880,1220,880};  // Protocol=UNKNOWN Hash=0x0 17 bits received
unsigned int power4[] = {2380,570,880,620,880,570,880,1220,880,1220,930,520,930,520,880,570,880,620,880,570,880,570,930,570,880,570,880,570,880,1220,880,520,930};  // Protocol=UNKNOWN Hash=0x0 17 bits received

const uint16_t irSignal[] = {2380,570,880,570,880,570,930,1220,880,1220,880,570,880,570,880,570,880,570,930,570,880,570,880,570,880,570,930,520,930,1170,930,1170,880};  // Protocol=UNKNOWN Hash=0x0 17 bits received

IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode (LED_BUILTIN, OUTPUT);
}

void loop() {

    Serial.println("sent");
    IrSender.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), 38); // Note the approach used to automatically calculate the size of the array.
    delay(1000);

//  Serial.println("code1");
//  irsend.sendRaw(power1, 33, 38);
//  delay(2000);
//  Serial.println("code2");
//  irsend.sendRaw(power2, 33, 38);
//  delay(2000);
//  Serial.println("code3");
//  irsend.sendRaw(power3, 33, 38);
//  delay(2000);
//  Serial.println("code4");
//  irsend.sendRaw(power4, 33, 38);
//  delay(10000);
}
