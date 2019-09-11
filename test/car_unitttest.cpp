#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "car.h"
#include "lights.h"
#include "mocks/mock_motor.h"
#include "mocks/mock_lights.h"

TEST(CarTest, stop) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, stop).Times(1);
	EXPECT_CALL(right, stop).Times(1);

	Car* car = new RealCar(&left, &right, NULL);

	car->stop();
}

TEST(CarTest, moveForward) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, moveForward).Times(1);
	EXPECT_CALL(right, moveForward).Times(1);

	Car* car = new RealCar(&left, &right, NULL);

	car->moveForward();
}

TEST(CarTest, moveBackward) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, moveBackward).Times(1);
	EXPECT_CALL(right, moveBackward).Times(1);

	Car* car= new RealCar(&left, &right, NULL);

	car->moveBackward();
}

TEST(CarTest, rotateLeft) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, moveBackward).Times(1);
	EXPECT_CALL(right, moveForward).Times(1);

	Car* car= new RealCar(&left, &right, NULL);

	car->rotateLeft();
}

TEST(CarTest, rotateRight) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, moveForward).Times(1);
	EXPECT_CALL(right, moveBackward).Times(1);

	Car* car= new RealCar(&left, &right, NULL);

	car->rotateRight();
}

TEST(CarTest, nextLight) {
	MockLights lights;

	Car* car = new RealCar(NULL, NULL, &lights);

	EXPECT_CALL(lights, next()).Times(1);

	car->nextLight();
}

TEST(CarTest, nextSequence) {
	MockLights lights;

	Car* car = new RealCar(NULL, NULL, &lights);

	EXPECT_CALL(lights, nextSequence());

	car->nextSequence();
}

TEST(CarTest, leftPowerIs255ByDefault) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, moveForward(255)).Times(1);
	EXPECT_CALL(right, moveForward).Times(1);

	Car* car= new RealCar(&left, &right, NULL);

	car->moveForward();
}

TEST(CarTest, leftPowerIs178IfSpeedIs7) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, moveForward(178)).Times(1);
	EXPECT_CALL(right, moveForward).Times(1);

	Car* car= new RealCar(&left, &right, NULL);

	car->setLeftSpeed(7);
	car->moveForward();
}

TEST(CarTest, rightPowerIs255ByDefault) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, moveForward(255)).Times(1);
	EXPECT_CALL(right, moveForward).Times(1);

	Car* car= new RealCar(&left, &right, NULL);

	car->moveForward();
}

TEST(CarTest, rightPowerIs76IfSpeedIs3) {
	MockMotor left;
	MockMotor right;

	EXPECT_CALL(left, moveForward).Times(1);
	EXPECT_CALL(right, moveForward(76)).Times(1);

	Car* car= new RealCar(&left, &right, NULL);

	car->setRightSpeed(3);
	car->moveForward();
}



TEST(CarTest, setRightPower) {

}

// TODO: virtual void setLeftSpeed(int speed)  = 0;
// TODO: virtual void setRightSpeed(int speed) = 0;
