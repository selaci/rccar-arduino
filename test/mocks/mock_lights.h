/*
 * mock_lights.h
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef TEST_MOCKS_MOCK_LIGHTS_H_
#define TEST_MOCKS_MOCK_LIGHTS_H_

#include <gmock/gmock.h>
#include "lights.h"

class MockLights : public Lights {
public:
	MOCK_METHOD3(setPins, void(int, int, int));
	MOCK_METHOD1(addSequence, void(Sequence*));
	MOCK_METHOD0(next, void());
	MOCK_METHOD0(nextSequence, void());
};

#endif /* TEST_MOCKS_MOCK_LIGHTS_H_ */
