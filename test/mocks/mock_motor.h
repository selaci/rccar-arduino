#include <gmock/gmock.h>

#include "motor.h"

class MockMotor : public Motor {
public:
	MOCK_METHOD0(stop, void());
	MOCK_METHOD3(setPins, void(int, int, int));
	MOCK_METHOD1(moveForward, void(int power));
	MOCK_METHOD1(moveBackward, void(int power));
	MOCK_METHOD1(sanatisePower, void(int power));
};
