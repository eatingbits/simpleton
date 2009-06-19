/*
 *  OscillatorInput.h
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/18/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __OSCILLATOR_INPUT_H__
#define __OSCILLATOR_INPUT_H__

class OscillatorInput {
public:
	virtual ~OscillatorInput() {}
	virtual float sampleValue(float samplesPerPeriod) = 0;
};

class StaticOscillatorInput : public OscillatorInput {
public:
	StaticOscillatorInput(float value) : mValue(value) {}
	virtual float sampleValue(float samplesPerPeriod) { return mValue; }
private:
	float mValue;
};

#endif

	

