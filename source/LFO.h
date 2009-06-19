/*
 *  LFO.h
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __LFO_H__
#define __LFO_H__

#include "OScillator.h"
#include "OscillatorInput.h"

class LFO : public OscillatorInput {
public:
	LFO(Oscillator& oscillator, float frequency, float amplitude) : mOscillator(oscillator), mFrequency(frequency), mAmplitude(amplitude) {}
	float sampleValue(float samplesPerPeriod) { return mAmplitude * mOscillator.sampleValue(mFrequency); }
private:
	Oscillator& mOscillator;
	float mFrequency;
	float mAmplitude;
};

#endif

