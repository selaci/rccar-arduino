/*
 * driver.cpp
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */

#include "driver.h"

RealDriver::RealDriver(Car* car) {
	_car = car;
}

void RealDriver::conduct(int command) {
	int speed;

	switch(command & 0x07) {
		case Driver::STOP:
			_car->stop();
			break;
		case Driver::MOVE_FORWARD:
			_car->moveForward();
			break;
		case Driver::MOVE_BACKWARD:
			_car->moveBackward();
			break;
		case Driver::ROTATE_LEFT:
			_car->rotateLeft();
			break;
		case Driver::ROTATE_RIGHT:
			_car->rotateRight();
			break;
		case Driver::NEXT_SEQUENCE:
			_car->nextSequence();
			break;
		case Driver::LEFT_SPEED:
			speed = (command & 0XF0) >> 4;
			_car->setLeftSpeed(speed);
			break;
		case Driver::RIGHT_SPEED:
			speed = (command & 0XF0) >> 4;
			_car->setRightSpeed(speed);
			break;
	}
}

void RealDriver::nextLight() {
	_car->nextLight();
}

