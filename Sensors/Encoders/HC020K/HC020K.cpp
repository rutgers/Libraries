#include "HC020K.h"

HC020K::HC020K(int dataPin) {
	pin = dataPin;
}

void HC020K::countTicks() {
	if (forward) {
		ticks++;
	}
	else {
		ticks--;
	}
}

void HC020K::setDirection(bool forw) {
	forward = forw;
}

void HC020K::init(void (*handler)()) {
	// A tick is counted on the falling edge of the signal.
	attachInterrupt(digitalPinToInterrupt(pin), handler, FALLING);
}

int HC020K::getTicks() {
	return ticks;
}

void HC020K::resetTicks() {
	ticks = 0;
}

/**	
 *	09/17/17 - Rupesh Chinta: Created Library
 */