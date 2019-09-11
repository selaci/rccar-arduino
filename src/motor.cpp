/*
 * motor.cpp
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */

#include "motor.h"

RealMotor::RealMotor(Arduino* arduino) {
	_arduino = arduino;
	_en  = 0;
	_in1 = 0;
	_in2 = 0;
}

void RealMotor::setPins(int en, int in1, int in2) {
	_en  = en;
	_in1 = in1;
	_in2 = in2;
}

void RealMotor::stop() {
	_arduino->analogWrite(_en, LOW);
}

void RealMotor::moveForward(int power) {
	int sanitisedPower = sanitisePower(power);

	_arduino->digitalWrite(_in1, HIGH);
	_arduino->digitalWrite(_in2, LOW);
	_arduino->analogWrite(_en, sanitisedPower);
}

void RealMotor::moveBackward(int power) {
	int sanitisedPower = sanitisePower(power);

	_arduino->digitalWrite(_in1, LOW);
	_arduino->digitalWrite(_in2, HIGH);
	_arduino->analogWrite(_en, sanitisedPower);
}

int RealMotor::sanitisePower(int power) {
	if (power > 255) {
		return 255;
	} else if (power < 0) {
		return 0;
	}

	return power;
}
