#ifndef __SineOscillator__H
#define __SineOscillator__H

#ifndef __Oscillator__H
#include "Oscillator.h"
#endif

class SineOscillator : public Oscillator {
public:
  SineOscillator(Oscillator *previous, float samplesPerPeriod);
  ~SineOscillator();
	float nextSampleValue();
private:
	int mCurrentPeriod;
	float mSamplesPerPeriod;
};

#endif