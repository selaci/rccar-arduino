/*
 * car.cpp
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */

#include "car.h"

RealCar::RealCar(Motor* left, Motor* right, Lights* lights) {
	_left       = left;
	_right      = right;
	_lights     = lights;

	_maxPower   = 255;
	_leftPower  = 255;
	_rightPower = 255;
}

void RealCar::stop() {
	_left->stop();
	_right->stop();
}

void RealCar::moveForward() {
	_left->moveForward(_leftPower);
	_right->moveForward(_rightPower);
}

void RealCar::moveBackward() {
	_left->moveBackward(_leftPower);
	_right->moveBackward(_rightPower);
}

void RealCar::rotateLeft() {
	_left->moveBackward(_leftPower / 2);
	_right->moveForward(_rightPower / 2);
}

void RealCar::rotateRight() {
	_left->moveForward(_leftPower / 2);
	_right->moveBackward(_rightPower / 2);
}

void RealCar::nextLight() {
	_lights->next();
}

void RealCar::nextSequence() {
	_lights->nextSequence();
}

void RealCar::setLeftSpeed(int speed) {
	_leftPower = (255 * speed) / 10;
}

void RealCar::setRightSpeed(int speed) {
	_rightPower = (255 * speed) / 10;
}
