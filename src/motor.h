/*
 * motor.h
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef SRC_MOTOR_H_
#define SRC_MOTOR_H_

#include "arduino_interface.h"

class Motor {
public:
	virtual ~Motor() {}
	virtual void setPins(int en, int in1, int in2) = 0;
	virtual void stop() = 0;
	virtual void moveForward(int power) = 0;
	virtual void moveBackward(int power) = 0;
};

class RealMotor : public Motor {
private:
	Arduino* _arduino;
	int _en;
	int _in1;
	int _in2;
	int sanitisePower(int power);

public:
	RealMotor(Arduino* arduino);
	void setPins(int en, int in1, int in2);
	void stop();
	void moveForward(int power);
	void moveBackward(int power);
};

#endif /* SRC_MOTOR_H_ */
