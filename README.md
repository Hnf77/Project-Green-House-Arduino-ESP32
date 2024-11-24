# Green House Automation and Monitoring

## Overview
This project aims to create a smart greenhouse system using **Arduino Uno** and **ESP32**, designed for automated plant care and real-time monitoring. It utilizes a combination of sensors and automated systems to ensure optimal growing conditions.

## Translation
- <a href="">Indonesian</a>

## Features
- **Temperature Monitoring**: Real-time temperature tracking inside the greenhouse.
- **Humidity Control**: Monitors the air humidity to maintain suitable conditions.
- **Soil Moisture Detection**: Automated watering system activated when soil moisture falls below a certain level.
- **Light Intensity Measurement**: Detects sunlight levels for optimal plant growth.
- **Automatic Watering**: Watering system triggers automatically based on soil moisture sensor readings.
- **Mobile Monitoring**: Sensor data is sent to the **Blynk app**, enabling users to monitor and control the greenhouse remotely.

## Hardware Requirements
- Arduino Uno
- ESP32
- DHT11 or DHT22 (Temperature & Humidity Sensor) but this the project is use DHT11
- Soil Moisture Sensor
- Light Intensity Sensor (LDR or similar)
- Relay Module (for controlling the water pump)
- Water Pump
- Jumper wires
- Breadboard

## Software Requirements
- Arduino IDE
- Blynk App (for mobile monitoring)
- Libraries: Blynk, DHT, WiFi, etc.

## Installation
1. Clone this repository to your local machine.
2. Set up the hardware connections as per the project wiring diagram.
3. Open the Arduino IDE and install the necessary libraries.
4. Upload the code to the Arduino and ESP32.
5. Set up the Blynk app to monitor the data remotely.

## How It Works
1. **Sensors** continuously monitor temperature, humidity, soil moisture, and light intensity.
2. When the soil moisture drops below a defined threshold, the **automatic watering system** is activated.
3. All sensor readings are transmitted to the **Blynk app**, allowing users to monitor and control the system remotely.

## Acknowledgments
This project was inspired by the need to automate and optimize plant care in a greenhouse setting, making it easier for users to monitor and control their plants remotely using modern IoT technologies.

## Support Me

 <a href="https://paypal.me/hanif1230?country.x=ID&locale.x=id_ID" target="_blank" >
    <img src="https://user-images.githubusercontent.com/42001064/196043185-ebd61195-44ee-480f-9b76-f5eb7cfcaf55.png" alt="Paypal" width="180"/>
 </a>
 &nbsp;
 &nbsp;
 &nbsp;
 &nbsp;
 &nbsp;
 <a href="https://www.buymeacoffee.com/hnf77" target="_blank">
    <img src="https://cdn.buymeacoffee.com/buttons/v2/arial-yellow.png" alt="Paypal" width="180"/>
 </a>
