/*
 * arduino_interface.cpp
 *
 *  Created on: 24 Aug 2019
 *      Author: jordi.esteve
 */

#include "arduino_interface.h"

void RealArduino::digitalWrite(int pin, int value) {
	::digitalWrite(pin, value);
}

void RealArduino::analogWrite(int pin, int value) {
	::analogWrite(pin, value);
}

void RealArduino::pinMode(int pin, int mode) {
	::pinMode(pin, mode);
};

void RealArduino::delay(unsigned long ms) {
	::delay(ms);
}

void RealArduino::shiftOut(int dataPin, int clockPin, int bitOrder, int value) {
	::shiftOut(dataPin, clockPin, bitOrder, value);
}
