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

SineOscillator::SineOscillator() : 
Oscillator(), mSamplesPerPeriodModifier(0.0)	{
}

SineOscillator::~SineOscillator() {
}

void SineOscillator :: generateFrames(Buffer& buffer, int channels, int framesToGenerate, float samplesPerPeriod) {
	for (int frame = 0; frame < framesToGenerate; ++frame) {
		mCurrentPeriod = (mCurrentPeriod + 1) % (int) (samplesPerPeriod + mSamplesPerPeriodModifier);
		for (int channel = 0; channel < channels; ++channel) {
			buffer.setValue(channel, frame, sampleValue(samplesPerPeriod));
//			outputs[channel][frame] = generateTune(mCurrentPeriod, mSamplesPerPeriod);
		}
	}
}

float SineOscillator :: sampleValue(float samplesPerPeriod) {
	return sin(mCurrentPeriod / (samplesPerPeriod + mSamplesPerPeriodModifier) * 2 * M_PI);
}

/*float SineOscillator :: generateTune(int currentPeriod, float samplesPerPeriod) {
  return sin(currentPeriod / (samplesPerPeriod) * 2 * M_PI);
}*/
