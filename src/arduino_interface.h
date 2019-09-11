/*
 * arduino_interface.h
 *
 *  Created on: 29 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef SRC_ARDUINO_INTERFACE_H_
#define SRC_ARDUINO_INTERFACE_H_

#include "Arduino.h"

/*
 * Arduino interface.
 */
class Arduino {
public:
	virtual ~Arduino() {};
	virtual void digitalWrite(int pin, int value) = 0;
	virtual void analogWrite(int pin, int value) = 0;
	virtual void pinMode(int pin, int mode) = 0;
	virtual void delay(unsigned long ms) = 0;
	virtual void shiftOut(int dataPin, int clockPin, int bitOrder, int value) = 0;
};

class RealArduino : public Arduino {
	void digitalWrite(int pin, int value);
	void analogWrite(int pin, int value);
	void pinMode(int pin, int mode);
	void delay(unsigned long ms);
	void shiftOut(int dataPin, int clockPin, int bitOrder, int value);
};

#endif /* SRC_ARDUINO_INTERFACE_H_ */
