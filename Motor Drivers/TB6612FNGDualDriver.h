#pragma once
#include "Arduino.h"


/*
	Written by Kevin Quizhpi 
	For General Use at Rutgers IEEE
	Modified 7/2/17
*/

/*
	TB6612FNG Dual Motor Driver Carrier
	link: https://www.pololu.com/product/713
	
	*********Motor Driver Specifications*************

	Motor Voltage: 4.5V to 13.5V
	Logic Voltage: 2.7V to 5.5V
	Max Output Current: 3A per Channel
	Max PWM freq: 100kHz
	Reverse power protection on the motor supply


	Can be used to drive two bidirectional motors or
	a single bipolar stepper motor.

	************ To intpret enable modes***********
	Enables are set to HIGH and LOW to switch Mode
	Refer to chart below, page 4
	data sheet link: https://www.pololu.com/file/0J86/TB6612FNG.pdf


*/
class TB6612FNGDualDriver
{
	/*
		Variables correspond to the A and B channel.

		If STBY is set to LOW driver will not run
	*/
	private: 

		int AIN1;
		int AIN2;
		int APWM;	

		int BIN1;
		int BIN2;
		int BPWM;

		int STBY;


	public:
		TB6612FNGDualDriver(int Ain1, int Ain2, int Apwm, int Bin1, int Bin2, int Bpwm, int standby);	
		TB6612FNGDualDriver();	
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

		void setStandby(bool set);

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


};


// Get/set for pins  -> Only use I can think of if default constructor is used to create motor object

// Message about capabilities of the class. What's not been implemented 
