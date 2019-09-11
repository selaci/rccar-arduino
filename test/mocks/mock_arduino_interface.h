/*
 * mock_arduino_interface.h
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef TEST_MOCKS_MOCK_ARDUINO_INTERFACE_H_
#define TEST_MOCKS_MOCK_ARDUINO_INTERFACE_H_

#include "arduino_interface.h"
#include <gmock/gmock.h>

class MockArduino : public Arduino {
public:
	MOCK_METHOD2(digitalWrite, void(int, int));
	MOCK_METHOD2(analogWrite, void(int, int));
	MOCK_METHOD2(pinMode, void(int, int));
	MOCK_METHOD1(delay, void(unsigned long));
	MOCK_METHOD4(shiftOut, void(int, int, int, int));
};

#endif /* TEST_MOCKS_MOCK_ARDUINO_INTERFACE_H_ */
