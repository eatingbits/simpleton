/*
 *  SineOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

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