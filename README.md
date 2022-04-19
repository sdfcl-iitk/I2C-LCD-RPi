# LCD-I2C-RPi
Ported the Arduino LCD I2C Library to Raspberry Pi https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

This library has been tested on a Raspberry Pi 4B with 8 GB RAM, running Ubuntu Server 20.04.

## Wiring
Connect the MPU9250 to the Pi's I2C bus. GPIO2 corresponds to SDA and GPIO3 corresponds to SCL.

| RPi | MPU |
| --- | --- |
| 5V  | 5V  |
| GND | GND |
| GPIO2 | SDA |
| GPIO3 | SCL |
