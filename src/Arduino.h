/*
 * Arduino.h
 *
 *  Created on: 24 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef SRC_ARDUINO_H_
#define SRC_ARDUINO_H_

static void digitalWrite(int pin, int value) {}
static void analogWrite(int pin, int value) {}
static void pinMode(int pin, int mode) {}
static void delay(int ms) {}
static void shiftOut(int dataPin, int clockPin, int bitOrder, int value) {}

const int LOW      = 0;
const int HIGH     = 1;
const int INPUT    = 2;
const int OUTPUT   = 3;
const int MSBFIRST = 4;

class Serial {
public:
	static void begin(int speed) {}
	static int available() { return 1; }
	static int read() { return 0x00; }
};

static Serial Serial;

#endif /* SRC_ARDUINO_H_ */
