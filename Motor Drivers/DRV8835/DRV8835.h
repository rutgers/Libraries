#pragma once
#include "Arduino.h"

/*
	Written by Kevin Quizhpi 
	For General Use at Rutgers IEEE
	Only covers Phase/Enable mode as of 07/2/2017
*/



/*
	DRV8835 Dual Motor Driver Carrier
	link: https://www.pololu.com/product/2135

	*********Motor Driver Specifications*************
	
	Motor Voltage: 0V to 11V
	Logic Voltage: 2V to 7V
	Max Output Current: 1.2A per Channel 
	Max PWM freq: 250kHz
	Reverse power protection against reverse-voltage
	under-voltage, over-current, and over-temperature.


	Can be used to drive two bidirectional motors or
	a single bipolar stepper motor.

	************ To intpret enable modes***********

	There are two modes of operation.

	Phase/Enable & IN1/IN2

	MODE = HIGH
	-  Phase/Enable mode
	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
	MODE = LOW
	- IN1/IN2 mode
	
	data sheet link: https:http://www.ti.com/lit/ds/symlink/drv8835.pdf

	_ __ _ __ _ __ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __ _ __

	VMM pin is for This pin gives access to the motor power supply after the reverse-voltage protection MOSFET . 
	It can be used to supply reverse-protected power to other components in the system. It is generally intended as an output, 
	but it can also be used to supply board power (such as in cases where the motor supply voltage is too low for the reverse-protection circuit).
		


*/
class DRV8835
{
	/*
		Variables correspond to the A and B channel.
	
	*/
	private: 


		int A_PHASE;
		int A_ENABLE;

		int B_PHASE;
		int B_ENABLE;

		int MODE;



	public:
		DRV8835(int phaseA, int enableA, int phaseB, int enableB, int mode);	
		DRV8835();	
		void SetPinMode();

		/*
			Each channel has a rotation set method, stop and set Speed method.
		*/
		void setAClockwise();
		void setACounterClockwise();
		void stopA();
		void setSpeedA(int Speed);

		void setBClockwise();
		void setBCounterClockwise();
		void stopB();
		void setSpeedB(int Speed);

		void setMode(bool mode);

/*		Methods for controlling both Channels at once for two motors
		Methods assume Channel A is the right motor and B is the left
		Robot configuration assumed below:

				Robot Front
					v
					_ _
				   /	\
				  / 	 \
	Channel B -> O 		  O   <- Channel A
				 \		  /
				  \	_  _ /

				  	  ^
				  Robot Rear
*/
		void setSpeedBoth(int Speed);
		void setForwards();
		void setBackwards();
		void setRotateRight();
		void setRotateLeft();
		void stopBoth();


};


// Message about capabilities of the class. What's not been implemented 
