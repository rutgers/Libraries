
#include "PID.h"

PID::PID(int p, int i, int d)
{
	Kp = p;
	Ki = i;
	Kd = d;
}
PID::PID()
{
	
}

// Need to feed error 
float PID::getAdjustment(int error) // Returns correction for next interation
{
	sum += error;
	P = error * Kp;
	I = sum * Ki;
	D = (error - prevError) * Kd;
	prevError = error;
	total = P + I + D;
	return total;		// Returns adjustment
}
void PID::resetError()
{
	P = 0;
	I = 0;
	D = 0;
	prevError = 0;
}