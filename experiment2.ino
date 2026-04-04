#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>// Library V 1.0.1
#include <MAX6675.h>// Library Robb Tillaat v 0.1.1
#include <ModbusMaster.h>//Author:: Doc Walker <4-20ma@wvfans.net>  V 2.0.1
#include <SoftwareSerial.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

char server[] = "159.65.131.215";
uint16_t port = 8080;

// MAX6675
const uint8_t thermoSO  = D6;
const uint8_t thermoSCK = D7;
const uint8_t thermoCS1 = D2;   // hot side
const uint8_t thermoCS2 = D1;   // cold side

MAX6675 thermocoupleHot;
MAX6675 thermocoupleCold;

// MAX485 / PZEM
const uint8_t MAX485_RO = D5;
const uint8_t MAX485_DI = D3;
const uint8_t MAX485_RE = D0;
const uint8_t MAX485_DE = D4;

SoftwareSerial pzemSerial(MAX485_RO, MAX485_DI);
ModbusMaster node;

BlynkTimer timer;

float T_hot  = 0.0;
float T_cold = 0.0;
float deltaT = 0.0;

float voltage = 0.0;
float current = 0.0;
float power   = 0.0;
float energy  = 0.0;

void preTransmission()
{
  digitalWrite(MAX485_RE, HIGH);
  digitalWrite(MAX485_DE, HIGH);
}

void postTransmission()
{
  digitalWrite(MAX485_RE, LOW);
  digitalWrite(MAX485_DE, LOW);
}

void readTemperatureData()
{
  T_hot  = thermocoupleHot.read();
  T_cold = thermocoupleCold.read();
  deltaT = T_hot - T_cold;
}

void readElectricalData()
{
  uint8_t result = node.readInputRegisters(0x0000, 6);

  if (result == node.ku8MBSuccess)
  {
    voltage = node.getResponseBuffer(0) / 100.0;
    current = node.getResponseBuffer(1) / 100.0;
    power   = node.getResponseBuffer(3) / 10.0;
    energy  = node.getResponseBuffer(5) / 1000.0;
  }
  else
  {
    Serial.print("PZEM read error, code = ");
    Serial.println(result);
  }
}

void sendData()
{
  readTemperatureData();
  readElectricalData();

  Serial.println("====================================");
  Serial.print("T_hot  = ");
  Serial.print(T_hot, 2);
  Serial.println(" °C");

  Serial.print("T_cold = ");
  Serial.print(T_cold, 2);
  Serial.println(" °C");

  Serial.print("DeltaT = ");
  Serial.print(deltaT, 2);
  Serial.println(" °C");

  Serial.print("Voltage = ");
  Serial.print(voltage, 2);
  Serial.println(" V");

  Serial.print("Current = ");
  Serial.print(current, 3);
  Serial.println(" A");

  Serial.print("Power   = ");
  Serial.print(power, 3);
  Serial.println(" W");

  Serial.print("Energy  = ");
  Serial.print(energy, 6);
  Serial.println(" Wh");

  Blynk.virtualWrite(V0, T_hot);
  Blynk.virtualWrite(V1, T_cold);
  Blynk.virtualWrite(V2, deltaT);
  Blynk.virtualWrite(V3, voltage);
  Blynk.virtualWrite(V4, current);
  Blynk.virtualWrite(V5, power);
  Blynk.virtualWrite(V6, energy);
}

void setup()
{
  Serial.begin(115200);
  delay(200);

  pinMode(MAX485_RE, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);

  digitalWrite(MAX485_RE, LOW);
  digitalWrite(MAX485_DE, LOW);

  // MAX6675 begin(clock, cs, data)
  thermocoupleHot.begin(thermoSCK, thermoCS1, thermoSO);
  thermocoupleCold.begin(thermoSCK, thermoCS2, thermoSO);

  pzemSerial.begin(9600);

  node.begin(1, pzemSerial);
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);

  Blynk.begin(auth, ssid, pass, server, port);

  timer.setInterval(2000L, sendData);
}

void loop()
{
  Blynk.run();
  timer.run();
}