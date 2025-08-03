#define BLYNK_TEMPLATE_ID "YourTemplateId"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"
#define BLYNK_DEVICE_NAME "Mini Satellite"
#define BLYNK_PRINT Serial

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

Adafruit_MPU6050 mpu;

int mq2Pin = 34;
int buzzerPin = 25;
int ledPin = 26;

// Blynk Virtual Pins
#define MQ2_VALUE_VPIN V6
#define GAS_ALERT_VPIN V4
#define ACCEL_X_VPIN V7
#define ACCEL_Y_VPIN V8
#define ACCEL_Z_VPIN V2
#define MOTION_ALERT_VPIN V5

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Buzzer and LED setup
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) delay(10);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
}

void loop() {
  Blynk.run();

  // --- MQ2 Sensor Reading ---

  int mq2Value = analogRead(mq2Pin);
  Serial.print("MQ2 Gas Value: ");
  Serial.println(mq2Value);
  Blynk.virtualWrite(MQ2_VALUE_VPIN, mq2Value);

  if (mq2Value > 600) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    Blynk.virtualWrite(GAS_ALERT_VPIN, "⚠️ Smoke or Gas Leak Detected!");
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    Blynk.virtualWrite(GAS_ALERT_VPIN, "Air Quality Normal ✅");
  }

  // --- MPU6050 Reading ---
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float ax = a.acceleration.x;
  float ay = a.acceleration.y;
  float az = a.acceleration.z;

  Blynk.virtualWrite(ACCEL_X_VPIN, ax);
  Blynk.virtualWrite(ACCEL_Y_VPIN, ay);
  Blynk.virtualWrite(ACCEL_Z_VPIN, az);

  // Motion Alert
  if (abs(ax) > 8 || abs(ay) > 8 || abs(az) < 2) {
    Blynk.virtualWrite(MOTION_ALERT_VPIN, "⚠️ Shock or Tilt Detected!");
  } else {
    Blynk.virtualWrite(MOTION_ALERT_VPIN, "Stable ✅");
  }

  delay(1000);
}
