#include "SquareOscillator.h"

SquareOscillator::SquareOscillator(Oscillator *previous, float samplesPerPeriod) : Oscillator(previous), mCurrentPeriod(0), 
	mSamplesPerPeriod(samplesPerPeriod) {
}

float SquareOscillator :: nextSampleValue() {
	float amplitudeModifier = getAmplitudeModifier();
	float frequencyModifier = getFrequencyModifier();
	int half = ((mSamplesPerPeriod + frequencyModifier) / 2);
	
	/* Add 1 to the period and wrap it at samplesPerPerd + frequencyModifier */
	mCurrentPeriod = (mCurrentPeriod + 1) % (int) (mSamplesPerPeriod + frequencyModifier);
	return amplitudeModifier * sampleValue(mCurrentPeriod, half);
}

float SquareOscillator :: sampleValue(int currentPeriod, int half) {
	if (currentPeriod > half) {
		return -1.0;
	}
	return 1.0;
}

