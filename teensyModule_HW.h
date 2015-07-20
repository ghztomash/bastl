
/*
teensyModule hardware library
this library is to be used with Bastl Instruments eurorack hardware and Teensy 3.1
MOZZI library compatible
documentation of the library you find here:

Created by Tomash Ghzegowsky 2015 http://tomashg.com/
for Bastl Instruments http://www.bastl-instruments.com/
*/

#ifndef teensyHWR_h
#define teensyHWR_h

#include "Arduino.h"
#include <avr/pgmspace.h>

#define NUMBER_OF_KNOBS 4
#define NUMBER_OF_CVIN 5
#define NUMBER_OF_BUTTONS 2
#define NUMBER_OF_LEDS 5

// pin definitions //

#define KNOB_A_PIN A0
#define KNOB_B_PIN A1
#define KNOB_C_PIN A2
#define KNOB_D_PIN A3

#define BUTTON_A_PIN 12
#define SWITCH_PIN 11

#define LED_A_PIN 10
#define LED_B_PIN 9
#define LED_C_PIN 6
#define LED_D_PIN 5
#define LED_E_PIN 4

// class definition //

class teensyHWR {
	public:
		teensyHWR(); // constructor
		void initialize();
		void initializeMozzi();
		void update();
		void mozziUpdate();
	private:
};
#endif //teensyHWR_h