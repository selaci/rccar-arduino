/*
 * motortest.cpp
 *
 *  Created on: 24 Aug 2019
 *      Author: jordi.esteve
 */


#include <gtest/gtest.h>
#include <motor.h>

#include "mocks/mock_arduino_interface.h"

int EN  = 0;
int IN1 = 1;
int IN2 = 2;


TEST(MotorTest, stop) {
	MockArduino interface;
	Motor* motor = new RealMotor(&interface);
	motor->setPins(EN, IN1, IN2);

	EXPECT_CALL(interface, analogWrite(EN, LOW)).Times(1);

	motor->stop();
}

TEST(MotorTest, moveForward) {
	MockArduino interface;
	Motor* motor = new RealMotor(&interface);
	motor->setPins(EN, IN1, IN2);

	EXPECT_CALL(interface, digitalWrite(IN1, HIGH)).Times(1);
	EXPECT_CALL(interface, digitalWrite(IN2, LOW)).Times(1);
	EXPECT_CALL(interface, analogWrite(EN, 255)).Times(1);

	// Verify.
	motor->moveForward(255);
}

TEST(MotorTest, moveBackward) {
	MockArduino interface;
	Motor* motor = new RealMotor(&interface);
	motor->setPins(EN, IN1, IN2);

	EXPECT_CALL(interface, digitalWrite(IN1, LOW)).Times(1);
	EXPECT_CALL(interface, digitalWrite(IN2, HIGH)).Times(1);
	EXPECT_CALL(interface, analogWrite(EN, 255)).Times(1);

	// Verify.
	motor->moveBackward(255);
}

TEST(MotorTest, powerSanitizesTo0) {
	MockArduino interface;
	Motor* motor = new RealMotor(&interface);
	motor->setPins(EN, IN1, IN2);

	EXPECT_CALL(interface, digitalWrite(IN1, LOW)).Times(1);
	EXPECT_CALL(interface, digitalWrite(IN2, HIGH)).Times(1);
	EXPECT_CALL(interface, analogWrite(EN, 0)).Times(1);

	// Verify.
	motor->moveBackward(-10);
}

TEST(MotorTest, powerSanitizesTo255) {
	MockArduino interface;
	Motor* motor = new RealMotor(&interface);
	motor->setPins(EN, IN1, IN2);

	EXPECT_CALL(interface, digitalWrite(IN1, LOW)).Times(1);
	EXPECT_CALL(interface, digitalWrite(IN2, HIGH)).Times(1);
	EXPECT_CALL(interface, analogWrite(EN, 255)).Times(1);

	// Verify.
	motor->moveBackward(300);
}
