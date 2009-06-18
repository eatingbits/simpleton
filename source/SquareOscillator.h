/*
 *  SquareOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __SquareOscillator__H
#define __SquareOscillator__H

#ifndef __Oscillator__H
#include "Oscillator.h"
#endif

class Buffer;

class SquareOscillator : public Oscillator {
public:
	SquareOscillator();
	void setSamplesPerPeriodModifier(float value) { mSamplesPerPeriodModifier = value; }
	virtual void reset() { mCurrentPeriod = 0; }
	void generateFrames(Buffer& buffer, int channels, int framesToGenerate, float samplesPerPeriod);
private:	
	int mCurrentPeriod;
	float mSamplesPerPeriodModifier;
};

#endif