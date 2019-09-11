/*
 * driver.h
 *
 *  Created on: 24 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef SRC_DRIVER_H_
#define SRC_DRIVER_H_

#include "car.h"

class Driver {
public:
	static const char STOP          = 0x00;
	static const char MOVE_FORWARD  = 0x01;
	static const char MOVE_BACKWARD = 0x02;
	static const char ROTATE_LEFT   = 0x03;
	static const char ROTATE_RIGHT  = 0x04;
	static const char NEXT_SEQUENCE = 0x05;
	static const char LEFT_SPEED    = 0X06;
	static const char RIGHT_SPEED   = 0x07;

	virtual ~Driver() {}
	virtual void conduct(int command) = 0;
	virtual void nextLight() = 0;
};

class RealDriver : public Driver {
private:
	Car* _car;

public:
	RealDriver(Car* car);
	void conduct(int command);
	void nextLight();
};

#endif /* SRC_DRIVER_H_ */
