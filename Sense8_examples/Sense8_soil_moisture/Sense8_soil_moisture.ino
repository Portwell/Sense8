#include <Arduino.h>

const int PIN_MOISTURE_SENSOR_REACH_THRESHOLD = 7;
const int PIN_MOISTURE_SENSOR = A8;

// define Sense8 connector power enable pin
#define PIN_SENSE8_ALL_POWER_UP A1
#define PIN_SENSE8_ENABLE_DIGITAL_POWER_UP 18
#define PIN_SENSE8_ENABLE_ANALOG_POWER_UP 4
#define PIN_SENSE8_ENABLE_I2C_POWER_UP 5

void setup() {
  // enable Sense8 power up
  pinMode(PIN_SENSE8_ALL_POWER_UP, OUTPUT);
  digitalWrite(PIN_SENSE8_ALL_POWER_UP, HIGH);
  // enable Sense8 digital connector power up
  //pinMode(PIN_SENSE8_ENABLE_DIGITAL_POWER_UP, OUTPUT);
  //digitalWrite(PIN_SENSE8_ENABLE_DIGITAL_POWER_UP, HIGH);
  // enable Sense8 analog connector power up
  pinMode(PIN_SENSE8_ENABLE_ANALOG_POWER_UP, OUTPUT);
  digitalWrite(PIN_SENSE8_ENABLE_ANALOG_POWER_UP, HIGH);
  // enable Sense8 I2C connector power up
  //pinMode(PIN_SENSE8_ENABLE_I2C_POWER_UP, OUTPUT);
  //digitalWrite(PIN_SENSE8_ENABLE_I2C_POWER_UP, HIGH);

  pinMode(PIN_MOISTURE_SENSOR_REACH_THRESHOLD, INPUT);
  Serial.begin(9600);
}

void loop() {
    int moistureSensorValue = analogRead(PIN_MOISTURE_SENSOR);
    Serial.print("Measured Value: ");
    Serial.print(moistureSensorValue);
    int threshold = digitalRead(PIN_MOISTURE_SENSOR_REACH_THRESHOLD);
    Serial.print("\t, Threshold reach: " + threshold);
    Serial.println("");
    if (moistureSensorValue < 500) {
        Serial.println("--- Over water");
    } else if (moistureSensorValue >= 500 && moistureSensorValue < 900) {
        Serial.println("--- Humid");
    } else {
        Serial.println("--- Dry");
    }

    delay(1000);
}
