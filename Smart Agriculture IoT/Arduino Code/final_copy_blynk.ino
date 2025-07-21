#include "DHT.h"                 // Including the DHT library for DHT sensors
#include <LiquidCrystal_I2C.h>   // Including LCD library
#include <WiFi.h>                // Including the WiFi library
#include <WiFiClient.h>          // Including the WiFiClient library
#include <BlynkSimpleEsp32.h>    // Including the Blynk library for ESP32

// Blynk authentication and template information
#define BLYNK_TEMPLATE_ID "TMPL6aVrGgj9f"
#define BLYNK_TEMPLATE_NAME "Farm"
#define AUTH_TOKEN "L1aLQCpWmfBt2e1MwDXd4segilyGDdTE"

// Constants for calculations
#define SOUND_SPEED 0.034

// Pin definitions
#define DHTPIN 4
#define DHTTYPE DHT11
#define RELAY_PIN 23
#define MOISTURE_PIN 36

// WiFi credentials
char ssid[] = "Joe Mama";
char pass[] = "houa8855";

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Pin connections
int trigger_pin = 2;
int echo_pin = 5;
int buzzer_pin = 15;
int lcdColumns = 16;
int lcdRows = 2;
long duration;
float distance;
float water_level;
int moisture, sensor_analog;
const int sensor_pin = A0;  /* Soil moisture sensor O/P pin */

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Connect to Blynk server
  Blynk.begin(AUTH_TOKEN, ssid, pass);
  
  // Initialize pin modes
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  
  // Initialize DHT sensor
  Serial.println(F("DHTxx test!"));
  dht.begin();
  
  // Initialize LCD
  lcd.init();
  lcd.backlight(); // Turn on LCD backlight
}

void loop() {
  // Run Blynk
  Blynk.run();
  
  // Wait a few seconds between measurements
  delay(500);

  // Read temperature and humidity from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if DHT readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Print humidity and temperature readings
  Serial.print("Current Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Current Temperature: ");
  Serial.print(temperature);
  Serial.println("°C ");

  // Send humidity and temperature readings to Blynk
  Blynk.virtualWrite(V0, humidity);
  Blynk.virtualWrite(V2, temperature);

  // Ultrasonic sensor measurements
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
  distance = duration * SOUND_SPEED / 2;
  water_level = 16 - distance;

  // Check water level and send data to Blynk
  if (water_level <= 7) {
    Serial.print("Water level: ");
    Serial.print(water_level);
    Serial.println("cm");
    Blynk.virtualWrite(V1, water_level);
    digitalWrite(buzzer_pin, HIGH);
    delay(100);
    digitalWrite(buzzer_pin, LOW);
    delay(1000);
    Serial.println("Warning! Low Water Level!");
    delay(1000);
  } else if (water_level >= 27) {
    Serial.print("Water level: ");
    Serial.print(water_level);
    Serial.println("cm");
    Blynk.virtualWrite(V1, water_level);
    digitalWrite(buzzer_pin, HIGH);
    delay(100);
    digitalWrite(buzzer_pin, LOW);
    delay(1000);
    Serial.println("Warning! High Water Level!");
    delay(1000);
  } else {
    Serial.print("Water level: ");
    Serial.print(water_level);
    Serial.println("cm");
    Blynk.virtualWrite(V1, water_level);
    digitalWrite(buzzer_pin, LOW);
    delay(500);
  }

  // Soil moisture sensor measurements
  sensor_analog = analogRead(sensor_pin);
  moisture = (100 - ((sensor_analog / 4095.00) * 100));
  Serial.print("Moisture = ");
  Serial.print(moisture);
  Serial.println("%");
  Blynk.virtualWrite(V3, moisture);

  // Control the relay based on soil moisture level
  if (moisture < 20) {
    digitalWrite(RELAY_PIN, LOW);
    Blynk.virtualWrite(V4, HIGH);
    Serial.println("The soil moisture is Low => activate the pump");
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    Blynk.virtualWrite(V4, LOW);
    Serial.println("The soil moisture is High => deactivate pump");
  }

  // Display readings on LCD
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Temperature:");
  lcd.print(temperature);
  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Water Level:");
  lcd.print(water_level);
  lcd.print("cm");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Soil Moisture:");
  lcd.print(moisture);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
