/*
 *  SquareOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "SquareOscillator.h"
#include "Buffer.h"

SquareOscillator::SquareOscillator(Oscillator& previous) : Oscillator(previous), mCurrentPeriod(0) {
}

float SquareOscillator :: nextSampleValue(float samplesPerPeriod) {
	float frequencyModifier = getFrequencyModifier(samplesPerPeriod);
	int half = ((samplesPerPeriod + frequencyModifier) / 2);
	
	/* Add 1 to the period and wrap it at samplesPerPerd + frequencyModifier */
	mCurrentPeriod = (mCurrentPeriod + 1) % (int) (samplesPerPeriod + frequencyModifier);
	if (mCurrentPeriod > half) {
		return -1.0;
	}
	return 1.0;
}

