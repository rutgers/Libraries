#pragma once
#include "Arduino.h"

/**
 *	For use by Rutgers IEEE
 *
 *	This class is used with the DRV8835 motor driver from Pololu
 *	This class treats the two motors as motor 0 (A) and motor 1 (B)
 *	It can set motor speeds, both positive and negative, and keep
 *	track of motors being inverted (making consistent wiring easier).
 *
 *	Note, this only covers Phase/Enable mode currently.
 */

class DRV8835 {

	private: 
		const int NUM_MOTORS = 2;
		// Arrays to store the pins of the motor, and its inverted state
		int *phase, *enable;
		bool *inverted;
		// This keeps track of what mode the controller is in
		bool modeState;
		int modePin;

	public:
		DRV8835(int phase1, int enable1, int phase2, int enable2, int mode);
		DRV8835(int phase1, int enable1, int phase2, int enable2, bool mode);
		// Sets up pins as output pins, call this in setup
		void init();
		// Given a motor number, sets the speed to that motor.
		// The speed is constrained to be between -255 and 255.
		void setSpeed(int motor, int speed);
		// Sets the inverted state of a motor. If a motor is inverted,
		// calling setSpeed(255) actually sets its speed to -255.
		void setInverted(int motor, bool invert);

};

/**	
 *	08/24/17 - Rupesh Chinta: Created Library
 *  10/03/17 - Rupesh Chinta: Added constructor for no mode pin
 */