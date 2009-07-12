#ifndef __SAW_OSCILLATOR_H__
#define __SAW_OSCILLATOR_H__

#include "Oscillator.h"

class SawOscillator : public Oscillator {
public:
	SawOscillator(Oscillator *parent, float samplesPerPeriod, bool reverse);
	~SawOscillator() {}
	float nextSampleValue();
private:
	int mCurrentPeriod;
	float mSamplesPerPeriod;
	bool mReverse;
	int mHalfSamplesPerPeriod;
	float mDivider;
};

#endif
