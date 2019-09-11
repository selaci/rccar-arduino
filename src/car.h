/*
 * car.h
 *
 *  Created on: 24 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef SRC_CAR_H_
#define SRC_CAR_H_

#include "motor.h"
#include "lights.h"

class Car {
public:
	virtual ~Car() {}
    virtual void stop() = 0;
    virtual void moveForward()            = 0;
    virtual void moveBackward()           = 0;
    virtual void rotateLeft()             = 0;
    virtual void rotateRight()            = 0;
    virtual void nextLight()              = 0;
    virtual void nextSequence()           = 0;
    virtual void setLeftSpeed(int speed)  = 0;
    virtual void setRightSpeed(int speed) = 0;
};

class RealCar : public Car {
private:
	Motor* _left;
	Motor* _right;
	Lights* _lights;

	int _maxPower;

	int _leftPower;
	int _rightPower;

public:
	RealCar(Motor* left, Motor* right, Lights* lights);
	void stop();
	void moveForward();
	void moveBackward();
	void rotateLeft();
	void rotateRight();
	void nextLight();
	void nextSequence();
	void setLeftSpeed(int speed);
	void setRightSpeed(int speed);
};

#endif /* SRC_CAR_H_ */
