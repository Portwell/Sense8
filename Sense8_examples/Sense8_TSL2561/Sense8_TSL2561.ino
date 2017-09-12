/*
 * Digital_Light_Sensor.ino
 * A library for TSL2561
 *
 * Copyright (c) 2012 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : zhangkun
 * Create Time:
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <Wire.h>
#include <Digital_Light_TSL2561.h>

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
  TSL2561.init();
}

void loop()
{
  Serial.print("The Light value is: ");
  Serial.println(TSL2561.readVisibleLux());
  delay(1000);
}

