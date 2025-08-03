# NanoGuardian--IOT
A compact IoT mini satellite using ESP32, MPU6050, MQ2, and Blynk

NanoGuardian is a compact IoT-based mini satellite prototype built using **ESP32**, **MPU6050 (gyroscope + accelerometer)**, and **MQ2 gas sensor**, with real-time data monitoring via **Blynk IoT**. Designed to simulate environmental monitoring in space or atmospheric applications, it also includes an alert mechanism (LED/Buzzer) for hazardous gas detection.

---

## 🛠️ Components Used

| Component        | Purpose                                |
|------------------|----------------------------------------|
| ESP32            | Microcontroller + WiFi/Bluetooth       |
| MPU6050          | Detects orientation and movement       |
| MQ2              | Detects gases like LPG, smoke, methane |
| LED + Buzzer     | Alert on gas detection                 |
| Blynk IoT        | Cloud platform to visualize data       |
| Jumper Wires     | Connections                            |
| Breadboard       | Prototyping base                       |
| Power Supply     | 5V or USB from laptop                  |

---

## 📡 Sensors & Output Data

- **MPU6050** – Orientation data (acceleration & gyroscope)
- **MQ2** – Air quality monitoring (smoke, LPG, methane, propane, etc.)
- **LED/Buzzer** – Turns ON when gas exceeds a defined threshold
- **Blynk Dashboard** – Shows real-time sensor values via widgets

---
## 📸 Images

### 🔌 Wiring Diagram
![Wiring Diagram](wiring.png)

### 🚀 Real Project Setup
![Mini Satellite](satellite_photo.jpg)

- **MPU6050**
  - VCC → 3.3V
  - GND → GND
  - SDA → GPIO 21
  - SCL → GPIO 22

- **MQ2**
  - VCC → 5V
  - GND → GND
  - A0 → GPIO 34 (Analog Input)

- **LED** → GPIO 25 _(with 220Ω resistor)_
- **Buzzer** → GPIO 26 _(optional resistor)_

---

## 📱 Blynk Setup Instructions

1. Download **Blynk IoT** app from Play Store / App Store
2. Create a new Template in **[blynk.cloud](https://blynk.cloud)**
   - Note your **Template ID**, **Device Name**, and **Auth Token**
3. Add Widgets:
   - **Gauge** (MPU6050 Ax, Ay, Az)
   - **Display** (Gyro)
   - **LED** (linked to GPIO pin for gas alert)
4. Paste these details in the code before uploading.

---

## 💻 Code Overview

- Reads data from MPU6050 and MQ2
- Sends sensor values to Blynk
- Triggers LED/Buzzer alert when gas is detected
- Displays real-time feedback on mobile

> 🔗 Full code available in `nano_guardian.ino`

---

## 💡 Future Enhancements

- Add BMP280 or DHT22 for pressure/temp monitoring
- Store sensor logs to SD card
- Enable location tracking via GPS
- Solar-powered version for field deployment

---

## 📃 License

MIT License – free to use, modify, and distribute with credit.

---

## 🙌 Acknowledgments

- [Blynk IoT](https://blynk.io)
- Open Source Libraries for ESP32 & MPU6050
- Community support and feedback

---

## 🌐 Let's Connect!

Project by [Hemasri P]  
📍 ECE Student, Rajalakshmi Institute of Technology  
🔗 LinkedIn: [https://www.linkedin.com/in/hemasri-p-419a49305]  
📘 GitHub: [github.com/your-HemasriPalani](https://github.com/HemasriPalani)


