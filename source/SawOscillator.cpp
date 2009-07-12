#include "SawOscillator.h"

SawOscillator :: SawOscillator(Oscillator *parent, float samplesPerPeriod, bool reverse) : Oscillator(parent), 
mCurrentPeriod(0), mSamplesPerPeriod(samplesPerPeriod), mReverse(reverse), mHalfSamplesPerPeriod(samplesPerPeriod / 2), mDivider(1.0 / (float) mHalfSamplesPerPeriod) {
}

float SawOscillator :: nextSampleValue() {
	float amplitudeModifier = getAmplitudeModifier();
	float value = 0.0;
	if (mCurrentPeriod < mHalfSamplesPerPeriod) {
		value = -1 + ((float) mCurrentPeriod * mDivider);
	} else {
		value = 0 + ((float) (mCurrentPeriod - mHalfSamplesPerPeriod) * mDivider);
	}
	mCurrentPeriod = (mCurrentPeriod + 1) % (int) mSamplesPerPeriod;
	if (mReverse) {
		value *= -1;
	}
	float ret = (amplitudeModifier * value);
	return ret;
}

