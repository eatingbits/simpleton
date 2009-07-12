#ifndef __SineOscillator__H
#include "SineOscillator.h"
#endif
#include <math.h>

SineOscillator::SineOscillator(Oscillator *previous, float samplesPerPeriod) : 
Oscillator(previous), mCurrentPeriod(0), mSamplesPerPeriod(samplesPerPeriod) {
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
