/****************************************************************
 * ReadSHT2x
 *  An example sketch that reads the sensor and prints the
 *  relative humidity to the PC's serial port
 *
 *  Tested with:
 *    - SHT21-Breakout Humidity sensor from Modern Device
 *    - SHT2x-Breakout Humidity sensor from MisensO Electronics
 ***************************************************************/

#include <Wire.h>
#include <SHT2x.h>

// define Sense8 connector power enable pin
#define PIN_SENSE8_ALL_POWER_UP A1
#define PIN_SENSE8_ENABLE_DIGITAL_POWER_UP 18
#define PIN_SENSE8_ENABLE_ANALOG_POWER_UP 4
#define PIN_SENSE8_ENABLE_I2C_POWER_UP 5

void setup()
{
  // enable Sense8 power up
  pinMode(PIN_SENSE8_ALL_POWER_UP, OUTPUT);
  digitalWrite(PIN_SENSE8_ALL_POWER_UP, HIGH);
  // enable Sense8 digital connector power up
  //pinMode(PIN_SENSE8_ENABLE_DIGITAL_POWER_UP, OUTPUT);
  //digitalWrite(PIN_SENSE8_ENABLE_DIGITAL_POWER_UP, HIGH);
  // enable Sense8 analog connector power up
  //pinMode(PIN_SENSE8_ENABLE_ANALOG_POWER_UP, OUTPUT);
  //digitalWrite(PIN_SENSE8_ENABLE_ANALOG_POWER_UP, HIGH);
  // enable Sense8 I2C connector power up
  pinMode(PIN_SENSE8_ENABLE_I2C_POWER_UP, OUTPUT);
  digitalWrite(PIN_SENSE8_ENABLE_I2C_POWER_UP, HIGH);

  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Humidity(%RH): ");
  Serial.print(SHT2x.GetHumidity());
  Serial.print("     Temperature(C): ");
  Serial.println(SHT2x.GetTemperature());
  
  delay(1000);
}

