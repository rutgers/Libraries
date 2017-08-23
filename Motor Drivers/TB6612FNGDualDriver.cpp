#include "TB6612FNGDualDriver.h"



/*
	Arguments for Constructor should correspond to the pinds that they are connected to.

	Motor Driver should be declared outside of the SetUp and Loop blocks.
	STBY is set to HIGH.
*/
TB6612FNGDualDriver::TB6612FNGDualDriver(int Ain1, int Ain2, int Apwm, int Bin1, int Bin2, int Bpwm, int standby) 
{
	AIN1 = Ain1;
	AIN2 = Ain2;
  	APWM = Apwm;
  	BIN1 = Bin1;
	BIN2 = Bin2;
  	BPWM = Bpwm;
  	STBY = standby;

}

// This method must be done inside the SetUp block 
void TB6612FNGDualDriver::SetPinMode()
{
	pinMode(AIN1, OUTPUT);
  	pinMode(AIN2, OUTPUT);
  	pinMode(APWM, OUTPUT);
	pinMode(BIN1, OUTPUT);
  	pinMode(BIN2, OUTPUT);
  	pinMode(BPWM, OUTPUT);
  	pinMode(STBY, OUTPUT);
  	digitalWrite(STBY, HIGH);
}

/*
	The following methods are written to be used with
	two DC motors. 

	*********** Rotation States**************
	IN1 = LOW & IN2 = HIGH  => Counter Clockwise
	IN1 = HIGH & IN2 = LOW  => Clockwise
*/


void TB6612FNGDualDriver::setAClockwise()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
}
void TB6612FNGDualDriver::setBClockwise()
{
	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
}

void TB6612FNGDualDriver::setACounterClockwise()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
}
void TB6612FNGDualDriver::setBCounterClockwise()
{
	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
}

/* 	Stop method sets enables to LOW so that motors don't run,
	when re-enabled motors will run at speed set before unless 
 	changed
 */
void TB6612FNGDualDriver::stopA()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, LOW);
}
void TB6612FNGDualDriver::stopB()
{
	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, LOW);
}


void TB6612FNGDualDriver::setSpeedA(int Speed)
{
  	Speed = constrain(Speed,0,255);
	analogWrite(APWM, Speed);
}
void TB6612FNGDualDriver::setSpeedB(int Speed)
{
  	Speed = constrain(Speed,0,255);
	analogWrite(BPWM, Speed);
}

/* 
	Boolean argument set sets STBY to HIGH or LOW
*/
void TB6612FNGDualDriver::setStandby(bool set)
{
	if(set == true)	
		digitalWrite(STBY, HIGH);
	
	if(set == false)
		digitalWrite(STBY,LOW);
}

// Default Constructor
TB6612FNGDualDriver::TB6612FNGDualDriver()
{
	
}


/* Methods for controlling both motors at the same time. 
* Not meant for stepper
*
* Assuming Channel A is the right motor and B is the left
*/

// Sets speed of both motors to the same speed
void TB6612FNGDualDriver::setSpeedBoth(int Speed)
{
	setSpeedB(Speed);
	setSpeedA(Speed);
}

void TB6612FNGDualDriver::setForwards()
{
	setAClockwise();
	setBCounterClockwise();
}

void TB6612FNGDualDriver::setBackwards()
{
	setACounterClockwise();
	setBClockwise();
}

void TB6612FNGDualDriver::setRotateRight()
{
	setACounterClockwise();
	setBCounterClockwise();
}

void TB6612FNGDualDriver::setRotateLeft()
{
	setAClockwise();
	setBClockwise();
}