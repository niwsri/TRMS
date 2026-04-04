#include <dummy.h>

#include <dummy.h>

//
//    FILE: MAX6675_test.ino (MODIFIED)
//

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>// Library V 1.0.1
#include "MAX6675.h"//Library Robb Tillaat v 0.1.1

////////////////////////////////////// CONFIG //////////////////////////////////////
char auth[] = "YOUR_BLYNK_TOKEN";
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";
////////////////////////////////////////////////////////////////////////////////////

BlynkTimer timer;

// ✅ Use the clock together
const int clockPin  = D5;

// Hot side
const int dataPin   = D6;  // SO
const int selectPin = D1;  // CS

// Cold side
const int dataPin2   = D7; // SO
const int selectPin2 = D2; // CS

MAX6675 thermoCouple_hotside;
MAX6675 thermoCouple_coldside;

int status, status2;
float hotside, coldside;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("MAX6675 Dual Sensor Start");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  Blynk.begin(auth, ssid, pass, "159.65.131.215", 8080);

  // start sensor
  thermoCouple_hotside.begin(clockPin, selectPin, dataPin);
  thermoCouple_coldside.begin(clockPin, selectPin2, dataPin2);

  thermoCouple_hotside.setSPIspeed(4000000);
  thermoCouple_coldside.setSPIspeed(4000000);

  timer.setInterval(2000L, TermoCC);
}

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void loop()
{
  Blynk.run();
  timer.run();
}

void TermoCC()
{
  status  = thermoCouple_hotside.read();
  status2 = thermoCouple_coldside.read();

  // ✅ Check errors
  if (status != STATUS_OK) {
    Serial.println("Hot sensor error!");
    return;
  }

  if (status2 != STATUS_OK) {
    Serial.println("Cold sensor error!");
    return;
  }

  hotside  = thermoCouple_hotside.getTemperature();
  coldside = thermoCouple_coldside.getTemperature();

  float delta = fabs(hotside - coldside);

  // ✅ Easy to read results
  Serial.print("T1: ");
  Serial.print(hotside);
  Serial.print(" °C | T2: ");
  Serial.print(coldside);
  Serial.print(" °C | Delta: ");
  Serial.print(delta);
  Serial.println(" °C");
   // Send Blynk values
  Blynk.virtualWrite(V1, hotside);
  Blynk.virtualWrite(V2, coldside);
  Blynk.virtualWrite(V3, delta);
}