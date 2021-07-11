#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>

const char *ssid     = "Your SSID";
const char *password = "Your Password";

WiFiUDP ntpUDP;


// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionaly you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, "au.pool.ntp.org", 36000); // our timezone is +11, so 60seconds*60minutes*11hours = 39600 - 30seconds for sychronisation
// 39595? 


//Week Days
//String weekDays[7]={"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};

//Month names
//String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


void setup(){
  Serial.begin(74880);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());
  //Serial.print((String)timeClient.getHours() + ":");
  //Serial.print((String)timeClient.getMinutes());
  //Serial.println(weekDays[timeClient.getDay()]);

  // Creating the formatted date
  //unsigned long epochTime = timeClient.getEpochTime();
  //struct tm *ptm = gmtime ((time_t *)&epochTime); 
//  int monthDay = ptm->tm_mday;
//  int currentMonth = ptm->tm_mon+1;
//  String currentMonthName = months[currentMonth-1];
//  int currentYear = ptm->tm_year+1900;
//  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);

  //Serial.print(String(currentMonth) + ",");
  //Serial.print((String)monthDay + ",");
  
  //Serial.print(String(currentYear));

  
  //Serial.println(currentDate);
  //Serial.println(currentMonthName);
  
  //Serial.print((String)timeClient.getDay() + ",");
  //Serial.println("");

  delay(1000);
}
