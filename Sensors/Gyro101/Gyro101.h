#pragma once
#include "Arduino.h"

/**
 *	For use by Rutgers IEEE
 *
*/

class 101Gyro {

	private:
		Madgwick filter;
		unsigned long microsPerReading, microsPrevious;
		float accelScale, gyroScale;
		float Roll, Pitch, Yaw;

		float convertRawAcceleration(int aRaw);
		float convertRawGyro(int gRaw);
	public:
		Gyro101();
		void updateAngle();
		float getRoll();
		float getPitch();
		float getYaw();
}