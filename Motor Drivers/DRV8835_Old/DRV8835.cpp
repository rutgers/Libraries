#include "DRV8835.h"



/*
	Arguments for Constructor should correspond to the pins that they are connected to.

	Motor Driver should be declared outside of the SetUp and Loop blocks.
	MODE is set to HIGH.
*/
DRV8835::DRV8835(int phaseA, int enableA, int phaseB, int enableB, int mode) 
{
	A_PHASE = phaseA;
	A_ENABLE = enableA;
  	B_PHASE = phaseB;
	B_ENABLE = enableB;
  	MODE = mode;

}

// This method must be done inside the SetUp block 
void DRV8835::SetPinMode()
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


void DRV8835::setAClockwise()
{
	digitalWrite(A_PHASE, LOW);
}
void DRV8835::setBClockwise()
{
	digitalWrite(B_PHASE, LOW);
}

void DRV8835::setACounterClockwise()
{
	digitalWrite(A_PHASE, HIGH);
}
void DRV8835::setBCounterClockwise()
{
	digitalWrite(B_PHASE, HIGH);
}

/* 	Stop method sets enables to LOW so that motors don't run,
	when re-enabled motors will run at speed set before unless 
 	changed
 */
void DRV8835::stopA()
{
	digitalWrite(A_PHASE, LOW);
}
void DRV8835::stopB()
{
	digitalWrite(B_PHASE, LOW);
}


void DRV8835::setSpeedA(int Speed)
{
  	Speed = constrain(Speed,0,255);
	analogWrite(A_ENABLE, Speed);
}
void DRV8835::setSpeedB(int Speed)
{
  	Speed = constrain(Speed,0,255);
	analogWrite(B_ENABLE, Speed);
}

/* 
	Boolean argument set sets MODE to HIGH or LOW
*/
void DRV8835::setMode(bool set)
{
	if(set == true)	
		digitalWrite(MODE, HIGH);
	
	if(set == false)
		digitalWrite(MODE,LOW);
}

// Default Constructor
DRV8835::DRV8835()
{
	
}


/* Methods for controlling both motors at the same time. 
* Not meant for stepper
*
* Assuming Channel A is the right motor and B is the left
*/

// Sets speed of both motors to the same speed
void DRV8835::setSpeedBoth(int Speed)
{
	setSpeedB(Speed);
	setSpeedA(Speed);
}

void DRV8835::setForwards()
{
	setAClockwise();
	setBCounterClockwise();
}

void DRV8835::setBackwards()
{
	setACounterClockwise();
	setBClockwise();
}

void DRV8835::setRotateRight()
{
	setACounterClockwise();
	setBCounterClockwise();
}

void DRV8835::setRotateLeft()
{
	setAClockwise();
	setBClockwise();
}
void DRV8835::stopBoth()
{
	stopB();
	stopA();
}