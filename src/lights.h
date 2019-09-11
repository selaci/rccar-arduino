/*
 * lights.h
 *
 *  Created on: 30 Aug 2019
 *      Author: jordi.esteve
 */

#ifndef SRC_LIGHTS_H_
#define SRC_LIGHTS_H_

#include "arduino_interface.h"
#include "sequence.h"

class Lights {
public:
	virtual ~Lights() {};
	virtual void setPins(int dataPin, int latchPin, int clockPin) = 0;
	virtual void addSequence(Sequence* sequence) = 0;
	virtual void next() = 0;
	virtual void nextSequence() = 0;
};

class RealLights : public Lights {
private:
	Arduino* _arduino;
	int _dataPin;
	int _latchPin;
	int _clockPin;
	int _numSequences;
	int _currentSequence;
	static const int _maxSequences = 10;
	Sequence* _sequences[_maxSequences];

public:
	RealLights(Arduino* arduino);
	void setPins(int dataPin, int latchPin, int clockPin);
	void addSequence(Sequence* sequence);
	void next();
	void nextSequence();
};


#endif /* SRC_LIGHTS_H_ */
