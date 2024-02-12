#include <WiFiNINA.h>                   // WiFi
#include <Adafruit_Sensor.h>            // For usage of sensors
#include "DHT.h"                        // For usage of this specific sensor
#define DHT11_PIN 2                     // Sensor connected to pin 2

DHT dht11(DHT11_PIN, DHT11);
const char ssid[] = "UserSSID";             // Used SSID
const char pass[] = "UserPassword";         // Used password
WiFiClient net;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(ssid,pass);
  dht11.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
                                                                            // The WiFi connection doesn't currently do anything but could be used to send the data wirelessly
  int WiFiStatus;                                                           // Currently the data transfer happens on Arduino.js using serialport
  WiFiStatus = WiFi.status();
  if (WiFiStatus == WL_DISCONNECTED || WiFiStatus == WL_CONNECTION_LOST){   // If WiFi.status() indicates no connection
    while (WiFiStatus != WL_CONNECTED) {                                    // Try to reconnect to given SSID using given password 
      pinMode(LED_BUILTIN, LOW);                                            // turn off the builtin LED + print "Connecting..." to indicate lost connection
      WiFiStatus = WiFi.begin(ssid, pass);                                  
      Serial.println("Connecting...");
      delay(5000);
    }
  }
  pinMode(LED_BUILTIN, HIGH);                                               // Connection successfull = LED turned on
  delay(2000);
 
  float humi = dht11.readHumidity();                                        // Read sensor values
  float tempC = dht11.readTemperature();

  if (isnan(humi) || isnan(tempC)) {
    Serial.println("Sensor read error: isnan");                             // If error with sensor reading give error message
  } else {                                                                  // Else print out sensor values
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("% ");

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println("°C");
  }
}
