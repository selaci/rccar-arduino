/*
 * lights_unittest.cpp
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "mocks/mock_arduino_interface.h"
#include "lights.h"

const int DATA_PIN  = 0;
const int LATCH_PIN = 1;
const int CLOCK_PIN = 2;

TEST(LightsTest, doesNothingIfNoSequence) {
	MockArduino arduino;

	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, LOW)).Times(0);
	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, HIGH)).Times(0);

	Lights* lights = new RealLights(&arduino);
	lights->setPins(DATA_PIN, LATCH_PIN, CLOCK_PIN);

	lights->next();
}

TEST(LightsTest, returnsNextLight) {
	MockArduino arduino;

	Lights* lights = new RealLights(&arduino);
	lights->setPins(DATA_PIN, LATCH_PIN, CLOCK_PIN);

	class TestSequence : public Sequence {
	public:
		unsigned int next() {
			return 384; // 1 (0000 0001) + 128 (1000 0000)
		}
	};

	lights->addSequence(new TestSequence());

	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, LOW)).Times(1);
	EXPECT_CALL(arduino, shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 1));
	EXPECT_CALL(arduino, shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 128));
	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, HIGH)).Times(1);

	lights->next();
}

TEST(LightsTest, nextSequence) {
	MockArduino arduino;

	Lights* lights = new RealLights(&arduino);
	lights->setPins(DATA_PIN, LATCH_PIN, CLOCK_PIN);

	class TestSequence : public Sequence {
	public:
		unsigned int next() {
			return 384; // 1 (0000 0001) + 128 (1000 0000)
		}
	};

	class OtherSequence : public Sequence {
	public:
		unsigned int next() {
			return 576; // 2 (0000 0010) + 64 (0100 0000)
		}
	};

	lights->addSequence(new TestSequence());
	lights->addSequence(new OtherSequence());
	lights->nextSequence();

	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, LOW)).Times(1);
	EXPECT_CALL(arduino, shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 2));
	EXPECT_CALL(arduino, shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 64));
	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, HIGH)).Times(1);

	lights->next();
}

TEST(LightsTest, cyclesThroughAllSequences) {
	MockArduino arduino;

	Lights* lights = new RealLights(&arduino);
	lights->setPins(DATA_PIN, LATCH_PIN, CLOCK_PIN);

	class TestSequence : public Sequence {
	public:
		unsigned int next() {
			return 384; // 1 (0000 0001) + 128 (1000 0000)
		}
	};

	class OtherSequence : public Sequence {
	public:
		unsigned int next() {
			return 576; // 2 (0000 0010) + 64 (0100 0000)
		}
	};

	lights->addSequence(new TestSequence());
	lights->addSequence(new OtherSequence());
	lights->nextSequence();
	lights->nextSequence();

	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, LOW)).Times(1);
	EXPECT_CALL(arduino, shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 1));
	EXPECT_CALL(arduino, shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 128));
	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, HIGH)).Times(1);

	lights->next();
}

TEST(LightsTest, overrideSequencesIfMaxSequenceReached) {
	MockArduino arduino;

	Lights* lights = new RealLights(&arduino);
	lights->setPins(DATA_PIN, LATCH_PIN, CLOCK_PIN);

	class TestSequence : public Sequence {
	public:
		unsigned int next() {
			return 384; // 1 (0000 0001) + 128 (1000 0000)
		}
	};

	class OtherSequence : public Sequence {
	public:
		unsigned int next() {
			return 576; // 2 (0000 0010) + 64 (0100 0000)
		}
	};

	lights->addSequence(new TestSequence());  //  1
	lights->addSequence(new OtherSequence()); //  2
	lights->addSequence(new OtherSequence()); //  3
	lights->addSequence(new OtherSequence()); //  4
	lights->addSequence(new OtherSequence()); //  5
	lights->addSequence(new OtherSequence()); //  6
	lights->addSequence(new OtherSequence()); //  7
	lights->addSequence(new OtherSequence()); //  8
	lights->addSequence(new OtherSequence()); //  9
	lights->addSequence(new OtherSequence()); // 10
	lights->addSequence(new OtherSequence()); // 11 -> 1

	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, LOW)).Times(1);
	EXPECT_CALL(arduino, shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 2));
	EXPECT_CALL(arduino, shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 64));
	EXPECT_CALL(arduino, digitalWrite(LATCH_PIN, HIGH)).Times(1);

	lights->next();
}
