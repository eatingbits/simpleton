/*
 *  SineOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SineOscillator__H
#include "SineOscillator.h"
#endif
#include <math.h>
#include "Buffer.h"

SineOscillator::SineOscillator(Oscillator *previous, float samplesPerPeriod) : 
Oscillator(previous), mCurrentPeriod(0), mSamplesPerPeriod(samplesPerPeriod), mPlaying(0) {
}

SineOscillator::~SineOscillator() {
}

float SineOscillator :: nextSampleValue() {	
	float amplitudeModifier = getAmplitudeModifier();
	float frequencyModifier = getFrequencyModifier();
	mCurrentPeriod = (mCurrentPeriod + 1) % (int) (mSamplesPerPeriod + frequencyModifier);
	float value = sin(mCurrentPeriod / (mSamplesPerPeriod + frequencyModifier) * 2 * M_PI);
	return amplitudeModifier * value;
}
