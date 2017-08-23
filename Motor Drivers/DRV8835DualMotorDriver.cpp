#include "DRV8835DualMotorDriver.h"



/*
	Arguments for Constructor should correspond to the pins that they are connected to.

	Motor Driver should be declared outside of the SetUp and Loop blocks.
	MODE is set to HIGH.
*/
DRV8835DualMotorDriver::DRV8835DualMotorDriver(int phaseA, int enableA, int phaseB, int enableB, int mode) 
{
	A_PHASE = phaseA;
	A_ENABLE = enableA;
  	B_PHASE = phaseB;
	B_ENABLE = enableB;
  	MODE = mode;

}

// This method must be done inside the SetUp block 
void DRV8835DualMotorDriver::SetPinMode()
{
	pinMode(A_PHASE, OUTPUT);
  	pinMode(A_ENABLE, OUTPUT);
	pinMode(B_PHASE, OUTPUT);
  	pinMode(B_ENABLE, OUTPUT);
  	pinMode(MODE, OUTPUT);
  	digitalWrite(MODE, HIGH);
}

/*
	The following methods are written to be used with
	two DC motors. 

	*********** Rotation States**************
	Phase = 0, Enable = PWM => OUT1 = PWM, OUT2 = LOW -> Clockwise
	Phase = 1, Enable = PWM => OUT1 = LOW, OUT2 = PWM -> CounterClockwise
*/


void DRV8835DualMotorDriver::setAClockwise()
{
	digitalWrite(A_PHASE, LOW);
}
void DRV8835DualMotorDriver::setBClockwise()
{
	digitalWrite(B_PHASE, LOW);
}

void DRV8835DualMotorDriver::setACounterClockwise()
{
	digitalWrite(A_PHASE, HIGH);
}
void DRV8835DualMotorDriver::setBCounterClockwise()
{
	digitalWrite(B_PHASE, HIGH);
}

/* 	Stop method sets enables to LOW so that motors don't run,
	when re-enabled motors will run at speed set before unless 
 	changed
 */
void DRV8835DualMotorDriver::stopA()
{
	digitalWrite(A_PHASE, LOW);
}
void DRV8835DualMotorDriver::stopB()
{
	digitalWrite(B_PHASE, LOW);
}


void DRV8835DualMotorDriver::setSpeedA(int Speed)
{
  	Speed = constrain(Speed,0,255);
	analogWrite(A_ENABLE, Speed);
}
void DRV8835DualMotorDriver::setSpeedB(int Speed)
{
  	Speed = constrain(Speed,0,255);
	analogWrite(B_ENABLE, Speed);
}

/* 
	Boolean argument set sets MODE to HIGH or LOW
*/
void DRV8835DualMotorDriver::setMode(bool set)
{
	if(set == true)	
		digitalWrite(MODE, HIGH);
	
	if(set == false)
		digitalWrite(MODE,LOW);
}

// Default Constructor
DRV8835DualMotorDriver::DRV8835DualMotorDriver()
{
	
}


/* Methods for controlling both motors at the same time. 
* Not meant for stepper
*
* Assuming Channel A is the right motor and B is the left
*/

// Sets speed of both motors to the same speed
void DRV8835DualMotorDriver::setSpeedBoth(int Speed)
{
	setSpeedB(Speed);
	setSpeedA(Speed);
}

void DRV8835DualMotorDriver::setForwards()
{
	setAClockwise();
	setBCounterClockwise();
}

void DRV8835DualMotorDriver::setBackwards()
{
	setACounterClockwise();
	setBClockwise();
}

void DRV8835DualMotorDriver::setRotateRight()
{
	setACounterClockwise();
	setBCounterClockwise();
}

void DRV8835DualMotorDriver::setRotateLeft()
{
	setAClockwise();
	setBClockwise();
}
void DRV8835DualMotorDriver::stopBoth()
{
	stopB();
	stopA();
}