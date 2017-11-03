# Arduino 101 - IMU

A simple library to get the IMU working on the Arduino 101

## Using the Library

After initalizing the class, it is simple to get the angle of the board. Simply call the function of the angle you want.

```c
#include <Gyro101>

Gyro101 gyro();

void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.print("This is the Yaw: ");
	Serial.println(gyro.getYaw());
}
```

*Written by Nicholas Clegg- November 3rd*