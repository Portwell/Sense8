/*
 * Demo name   : HP20x_dev demo 
 * Usage       : I2C PRECISION BAROMETER AND ALTIMETER [HP206C hopeRF] 
 * Author      : Oliver Wang from Seeed Studio
 * Version     : V0.1
 * Change log  : Add kalman filter 2014/04/04
*/

#include <HP20x_dev.h>
#include "Arduino.h"
#include "Wire.h" 
#include <KalmanFilter.h>
unsigned char ret = 0;

/* Instance */
KalmanFilter t_filter;    //temperature filter
KalmanFilter p_filter;    //pressure filter
KalmanFilter a_filter;    //altitude filter

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

  //while(!Serial){;}
  Serial.begin(9600);        // start serial for output
  
  Serial.println("****HP20x_dev demo by seeed studio****\n");
  Serial.println("Calculation formula: H = [8.5(101325-P)]/100 \n");
  /* Power up,delay 150ms,until voltage is stable */
  delay(150);
  /* Reset HP20x_dev */
  HP20x.begin();
  delay(100);
  
  /* Determine HP20x_dev is available or not */
  ret = HP20x.isAvailable();
  if(OK_HP20X_DEV == ret)
  {
    Serial.println("HP20x_dev is available.\n");    
  }
  else
  {
    Serial.println("HP20x_dev isn't available.\n");
  }
}
 

void loop()
{
    char display[40];
    if(OK_HP20X_DEV == ret)
    { 
	  Serial.println("------------------");
	  long Temper = HP20x.ReadTemperature();
	  Serial.print("Temper: ");
	  float t = Temper/100.0;
	  Serial.print(t);	  
	  Serial.print(" C.");
	  Serial.print(" / Filter: ");
	  Serial.print(t_filter.Filter(t));
	  Serial.println(" C.");
 
      long Pressure = HP20x.ReadPressure();
	  Serial.print("Pressure: ");
	  t = Pressure/100.0;
	  Serial.print(t);
	  Serial.print(" hPa.");
	  Serial.print(" / Filter: ");
	  Serial.print(p_filter.Filter(t));
	  Serial.println(" hPa");
	  
	  long Altitude = HP20x.ReadAltitude();
	  Serial.print("Altitude: ");
	  t = Altitude/100.0;
	  Serial.print(t);
	  Serial.print(" m.");
	  Serial.print(" / Filter: ");
	  Serial.print(a_filter.Filter(t));
	  Serial.println(" m.");
      delay(3000);
    }
}
 
