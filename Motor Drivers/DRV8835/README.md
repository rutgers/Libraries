# DRV8835 Dual Motor Driver Carrier

link: https://www.pololu.com/product/2135

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