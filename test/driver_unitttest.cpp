#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "driver.h"
#include "mocks/mock_car.h"

const int STOP            = 0x00;
const int MOVE_FORWARD    = 0x01;
const int MOVE_BACKWARD   = 0X02;
const int ROTATE_LEFT     = 0x03;
const int ROTATE_RIGHT    = 0x04;
const int NEXT_SEQUENCE   = 0x05;

TEST(DriverTest, stop) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, stop()).Times(1);

	driver->conduct(STOP);
}

TEST(DriverTest, moveForward) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, moveForward()).Times(1);

	driver->conduct(MOVE_FORWARD);
}

TEST(DriverTest, moveBackward) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, moveBackward()).Times(1);

	driver->conduct(MOVE_BACKWARD);
}

TEST(DriverTest, rotateLeft) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, rotateLeft()).Times(1);

	driver->conduct(ROTATE_LEFT);
}

TEST(DriverTest, rotateRight) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, rotateRight()).Times(1);

	driver->conduct(ROTATE_RIGHT);
}

TEST(DriverTest, next) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, nextLight).Times(1);

	driver->nextLight();
}

TEST(DriverTest, nextSequence) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, nextSequence()).Times(1);

	driver->conduct(NEXT_SEQUENCE);
}

TEST(DriverTest, setLeftSpeedTo5) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, setLeftSpeed).Times(1);

	driver->conduct(86); // 86 = 0101(5) + 0110(6)
}

TEST(DriverTest, setLeftSpeedTo2) {
	MockCar car;

	Driver* driver = new RealDriver(&car);

	EXPECT_CALL(car, setRightSpeed).Times(1);

	driver->conduct(39); // 39 = 0010(2) + 0111(7)

}
