# DRV8835 Dual Motor Driver Carrier

link: https://www.pololu.com/product/2135

Usage:

To use this module, there are two different constructors:

```c
#include <DRV8835.h>

DRV8835 motors(8, 6, 7, 5, 4);
DRV8835 motors(8, 6, 7, 5, true);
```
The first is used when you connect the mode pin into the Arduino - it needs to know which pin you connected it into.
The second is used when you connect the mode pin directly to 5V or ground, in which case, tell the library (by using true for 5V or false for ground)

In setup, you need to run init() to setup the motor pins.
Then, you use setSpeed(motor number, motor speed) to actually move the motors. Note that speed should be a value in between -255 and 255, and if you give it a higher value, it will just clamp it.
Finally, if you want to invert the direction a motor spins (for convenience reasons), use setInverted():

```c
void setup() {
	motors.init();
	motors.setInverted(1, true);
}

void loop() {
	motors.setSpeed(0, 255);
}
```


## Motor Driver Specifications

Motor Voltage: 0V to 11V
Logic Voltage: 2V to 7V
Max Output Current: 1.2A per Channel 
Max PWM freq: 250kHz
Reverse power protection against reverse-voltage
under-voltage, over-current, and over-temperature.

Can be used to drive two bidirectional motors or
a single bipolar stepper motor.

## Enable Modes

There are two modes of operation.

Phase/Enable & IN1/IN2

MODE = HIGH
-  Phase/Enable mode
MODE = LOW
- IN1/IN2 mode

data sheet link: https:http://www.ti.com/lit/ds/symlink/drv8835.pdf

## VMM Pin

This pin gives access to the motor power supply after the reverse-voltage protection MOSFET . 
It can be used to supply reverse-protected power to other components in the system. It is generally intended as an output, 
but it can also be used to supply board power (such as in cases where the motor supply voltage is too low for the reverse-protection circuit).

*Written by Kevin Quizhpi on August 2, 2017*
*Updated by Rupesh Chinta on October 3, 2017 - Updated usage of library*