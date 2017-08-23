#pragma once
#include "Arduino.h"

/*
*
*	Written by Kevin Quizhpi 
*	For General Use at Rutgers IEEE
*	7/2/17
*
*	Simple general use PID(well PSD really) class.
*
*/

class PID
{
	private:
		float Kp;
		float Ki;
		float Kd;
		float sum;
		float P,I,D;
		float prevError;
		float total;

	public:

		PID(int p, int i, int d);
		PID();
		float getAdjustment(int error);
		void resetError();

};