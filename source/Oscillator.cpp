/*
 *  Oscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "Oscillator.h"

float Oscillator :: sampleValue(float samplesPerPeriod) {
	float previous = inputValue(samplesPerPeriod);
	float nValue = previous + nextSampleValue(samplesPerPeriod);
	return nValue;
}

float Oscillator :: getFrequencyModifier(float samplesPerPeriod) {
	if (mFrequencyModifier == NULL) {
		return 0.0;
	}
	return mFrequencyModifier->sampleValue(samplesPerPeriod);
}


float Oscillator :: inputValue(float samplesPerPeriod) {
	return mInput.sampleValue(samplesPerPeriod);
}



