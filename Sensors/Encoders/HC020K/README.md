# HC020K - Encoders

The purpose of these encoders is to measure wheel rotations, which it does by shining a light through a spoked wheel.

The data signal on an encoder needs to be connected to an interrupt port, which should just add one tick.
In order to debounce the signal, connect a capacitor between data and ground

Note that this model of encoder is not that great, because it will tell you about a tick, but not which direction, so it's on you to set the direction the wheel is moving in.

## Using the Library

Initialize the encoder on whichever pin you plan to use it with.
Also, wrap the countTicks() function and pass it to the encoder in init.
Finally, since the encoder doesn't know which direction it's going in, you need to use setDirection()

'''c
#include <HC020K.h>

HC020K enc(2);

void count() {
	enc.countTicks();
}

void setup() {
	enc.init(&count);
	enc1.setDirection(HC020K::FORWARD);
}

void loop() {
	enc.getTicks();
}
'''

*Written by Rupesh Chinta - September 17th*