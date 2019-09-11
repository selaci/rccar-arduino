/*
 * lights.cpp
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef SRC_LIGHTS_CPP_
#define SRC_LIGHTS_CPP_

#include "lights.h"

RealLights::RealLights(Arduino* arduino) {
	_arduino = arduino;
	_dataPin = 0;
	_latchPin = 0;
	_clockPin = 0;
	_numSequences = 0;
	_currentSequence = 0;
}

void RealLights::setPins(int dataPin, int latchPin, int clockPin) {
	_dataPin = dataPin;
	_latchPin = latchPin;
	_clockPin = clockPin;
}

void RealLights::next() {
	if (_numSequences == 0) {
		return;
	}

	int next = _sequences[_currentSequence]->next();

	_arduino->digitalWrite(_latchPin, LOW);
	int value = next >> 8 & 0xFF;
	_arduino->shiftOut(_dataPin, _clockPin, MSBFIRST, value);

	value = next & 0xFF;
	_arduino->shiftOut(_dataPin, _clockPin, MSBFIRST, value);

	_arduino->digitalWrite(_latchPin, HIGH);
}

void RealLights::addSequence(Sequence* sequence) {
	_sequences[_numSequences] = sequence;
	_numSequences++;
	_numSequences = _numSequences % _maxSequences;
}

void RealLights::nextSequence() {
	_currentSequence++;
	_currentSequence = _currentSequence % _numSequences;
}

#endif /* SRC_LIGHTS_CPP_ */
