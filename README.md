# Smart-Agriculture-IoT-System-with-Blynk
An IoT-powered Smart Agricultural Monitoring System that continuously tracks environmental parameters like soil moisture, temperature, humidity, and water tank level to optimize irrigation, conserve water, and improve crop yields.

🚀 Features
1. Monitors soil moisture to trigger irrigation as needed
2. Tracks temperature and humidity using DHT11 sensor
3. Uses ultrasonic sensor to check water tank levels
4. Blynk app for real-time remote monitoring and control
5. Buzzer alert when water levels are low
6. Controls water pump automatically
7. LCD display for live data output
8. Efficient and data-driven irrigation decisions

🛠️ Hardware Components
 1. ESP32 Development Board
 2. DHT11 Temperature & Humidity Sensor
 3. Soil Moisture Sensor
 4. Ultrasonic Sensor (HC-SR04)
 5. Water Pump
 6. LCD Display (I2C)
 7. Buzzer
 8. Power Source (Battery or USB)
 9. Jumper Wires, Breadboard, etc.

💻 Software Requirements
Arduino IDE – for ESP32 firmware development
Blynk App – for remote monitoring and control
ESP32 Board Manager – installed in Arduino IDE


Required Libraries:
 1. DHT.h / DHT_U.h
 2. LiquidCrystal_I2C.h
 3. WiFi.h
 4. BlynkSimpleEsp32.h

🧠 How It Works
1. Sensors collect real-time environmental data.
2. ESP32 reads this data and displays it on the LCD.
3. Based on soil moisture and tank levels:
      Activates the water pump.
      Sends updates and allows control via Blynk.
4. Blynk app allows manual override and remote viewing of:
      Soil moisture level
      Temperature & humidity
      Water tank level
      Pump status
