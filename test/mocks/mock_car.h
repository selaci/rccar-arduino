#include <gmock/gmock.h>
#include "car.h"

class MockCar : public Car {
public:
	MOCK_METHOD0(stop, void());
	MOCK_METHOD0(moveForward, void());
	MOCK_METHOD0(moveBackward, void());
	MOCK_METHOD0(rotateLeft, void());
	MOCK_METHOD0(rotateRight, void());
	MOCK_METHOD0(nextLight, void());
	MOCK_METHOD0(nextSequence, void());
	MOCK_METHOD1(setLeftSpeed, void(int));
	MOCK_METHOD1(setRightSpeed, void(int));
};
