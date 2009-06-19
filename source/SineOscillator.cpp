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

SineOscillator::SineOscillator(Oscillator& previous) : 
Oscillator(previous), mCurrentPeriod(0) {
}

SineOscillator::~SineOscillator() {
}

float SineOscillator :: nextSampleValue(float samplesPerPeriod) {	
	float mod = getFrequencyModifier(samplesPerPeriod);
	mCurrentPeriod = (mCurrentPeriod + 1) % (int) (samplesPerPeriod + mod);
	float value = sin(mCurrentPeriod / (samplesPerPeriod + mod) * 2 * M_PI);
	return value;
}
