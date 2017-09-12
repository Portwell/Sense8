/*
  SDL_Weather_80422.cpp - Library for SwitchDoc Labs WeatherRack.
  SparkFun Weather Station Meters
  Argent Data Systems
  Created by SwitchDoc Labs July 27, 2014.
  Released into the public domain.
  Version 1.1 - updated constants to suppport 3.3V
  
  Supports WeatherPiArduino Board www.switchdoc.com
*/
#include <Wire.h>
#include <Time.h>

#include "SDL_Weather_80422.h"



#define pinLED     13   // LED connected to digital pin 13
#define pinAnem    3  // Anenometer connected to pin 18 - Int 5 - Mega   / Uno pin 2, 32u4 pin 3
#define pinRain    2  // Anenometer connected to pin 2 - Int 0 - Mega   / Uno Pin 3 , 32u4 pin 2
#define intAnem    0  // int 0 (check for Uno), pin3 for 32u4
#define intRain    1  // int 1, pin2 for 32u4

// for mega, have to use Port B - only Port B works.
/*
 Arduino Pins         PORT
 ------------         ----
 Digital 0-7          D
 Digital 8-13         B
 Analog  0-5          C
*/


#define PIN_SENSE8_WEATHER_WIND_VANE A8
// initialize SDL_Weather_80422 library
SDL_Weather_80422 weatherStation(pinAnem, pinRain, intAnem, intRain, PIN_SENSE8_WEATHER_WIND_VANE, SDL_MODE_INTERNAL_AD);


uint8_t i;




float currentWindSpeed;
float currentWindGust;
float totalRain;

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
  pinMode(PIN_SENSE8_ENABLE_ANALOG_POWER_UP, OUTPUT);
  digitalWrite(PIN_SENSE8_ENABLE_ANALOG_POWER_UP, HIGH);
  // enable Sense8 I2C connector power up
  //pinMode(PIN_SENSE8_ENABLE_I2C_POWER_UP, OUTPUT);
  //digitalWrite(PIN_SENSE8_ENABLE_I2C_POWER_UP, HIGH);

  Serial.begin(9600);  
  

  Serial.println("---start setup--------");
  Serial.println("WeatherArduino SDL_Weather_80422 Class Test");
  Serial.println("Version 1.1");
      
      
      weatherStation.setWindMode(SDL_MODE_SAMPLE, 5.0);
      //weatherStation.setWindMode(SDL_MODE_DELAY, 5.0);
  Serial.println("---end setup--------");
      totalRain = 0.0;
}


void loop()
{
  Serial.println("----------------");

  currentWindSpeed = weatherStation.current_wind_speed()/1.6;
  currentWindGust = weatherStation.get_wind_gust()/1.6;
  totalRain = totalRain + weatherStation.get_current_rain_total()/25.4;
  Serial.print("rain_total=");
  Serial.print(totalRain);
  Serial.print(", wind_speed=");
  Serial.print(currentWindSpeed);
  Serial.print(", MPH wind_gust=");
  Serial.print(currentWindGust);
  Serial.print(", MPH wind_direction=");
  Serial.println(weatherStation.current_wind_direction());
  

  
  delay(1000);
  
  
}

