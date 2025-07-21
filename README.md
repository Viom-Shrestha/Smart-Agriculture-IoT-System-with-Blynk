# Smart-Agriculture-IoT-System-with-Blynk
An IoT-powered Smart Agricultural Monitoring System that continuously tracks environmental parameters like soil moisture, temperature, humidity, and water tank level to optimize irrigation, conserve water, and improve crop yields.

🚀 Features
  🌱 Monitors soil moisture to trigger irrigation as needed
  🌡️ Tracks temperature and humidity using DHT11 sensor
  💧 Uses ultrasonic sensor to check water tank levels
  📱 Blynk app for real-time remote monitoring and control
  🔔 Buzzer alert when water levels are low
  🚰 Controls water pump automatically
  📟 LCD display for live data output
  📊 Efficient and data-driven irrigation decisions

🛠️ Hardware Components
 ESP32 Development Board
 DHT11 Temperature & Humidity Sensor
 Soil Moisture Sensor
 Ultrasonic Sensor (HC-SR04)
 Water Pump
 LCD Display (I2C)
 Buzzer
 Power Source (Battery or USB)
 Jumper Wires, Breadboard, etc.

💻 Software Requirements
Arduino IDE – for ESP32 firmware development
Blynk App – for remote monitoring and control
ESP32 Board Manager – installed in Arduino IDE


Required Libraries:
  DHT.h / DHT_U.h
  LiquidCrystal_I2C.h
  WiFi.h
  BlynkSimpleEsp32.h

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
