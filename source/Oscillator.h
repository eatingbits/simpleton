/*
 *  oscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/18/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __Oscillator__H
#define __Oscillator__H

#include <cstdlib>
#include "OscillatorInput.h"

class Buffer;

class Oscillator : public OscillatorInput {
public:
	Oscillator(Oscillator& oscillator)  : mInput(oscillator), mFrequencyModifier(NULL)  {}
	virtual ~Oscillator() {}
	/* Resets the current position of the oscillator */
	virtual void reset() {};
	/* Sets a frequency modifier input */
	void setFrequencyModifier(OscillatorInput *freqMod) { mFrequencyModifier = freqMod; }	
	/* Returns the next sample value */
	float sampleValue(float samplesPerPeriod);
protected:
	/* Implemented by sub classes */
	virtual float nextSampleValue(float samplesPerPeriod) = 0;
	/* Returns the current frequency modifier */
	float getFrequencyModifier(float samplesPerPeriod);
	/* Returns the base input value */
	virtual float inputValue(float samplesPerPeriod);
	
private:
	Oscillator& mInput;
	OscillatorInput *mFrequencyModifier;	
};

#endif