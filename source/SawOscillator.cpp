/*
 *  SawOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "SawOscillator.h"

SawOscillator :: SawOscillator(Oscillator *parent, float samplesPerPeriod, bool reverse) : Oscillator(parent), mSamplesPerPeriod(samplesPerPeriod), mReverse(reverse) {
}

float SawOscillator :: nextSampleValue() {
	float amplitudeModifier = getAmplitudeModifier();
	int half = mSamplesPerPeriod / 2;
	float value = 0.0;
	if (mCurrentPeriod < half) {
		value = -1 + ((float) mCurrentPeriod * (1.0 / (float) half));
	} else {
		value = 0 + ((float) (mCurrentPeriod - half) * (1.0 / (float) half));
	}
	mCurrentPeriod = (mCurrentPeriod + 1) % (int) mSamplesPerPeriod;
	if (mReverse) {
		value *= -1;
	}
	return (amplitudeModifier * value);
}

