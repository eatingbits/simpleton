/*
 *  SineOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SineOscillator__H
#define __SineOscillator__H

#ifndef __Oscillator__H
#include "Oscillator.h"
#endif

class Buffer;

class SineOscillator : public Oscillator {
public:
  SineOscillator();
  ~SineOscillator();
	void setSamplesPerPeriodModifier(float value) { mSamplesPerPeriodModifier = value; }
	virtual void reset() { mCurrentPeriod = 0; }
	virtual void generateFrames(Buffer& buffer, int channels, int framesToGenerate, float samplesPerPeriod);
private:
	int mCurrentPeriod;
	float mSamplesPerPeriodModifier;
	float sampleValue(float samplesPerPeriod);
};

#endif