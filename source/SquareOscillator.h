#ifndef __SquareOscillator__H
#define __SquareOscillator__H

#ifndef __Oscillator__H
#include "Oscillator.h"
#endif

class Buffer;

class SquareOscillator : public Oscillator {
public:
	SquareOscillator(Oscillator *previous, float samplesPerPeriod);
	float nextSampleValue();
private:	
	float sampleValue(int currentPeriod, int half);
	int mCurrentPeriod;
	float mSamplesPerPeriod;
};

#endif