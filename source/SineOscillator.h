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

class Buffer;

class SineOscillator : public Oscillator {
public:
  SineOscillator(Oscillator& previous);
  ~SineOscillator();
	virtual void reset() { mCurrentPeriod = 0; }

	float nextSampleValue(float samplesPerPeriod);
private:
	int mCurrentPeriod;
};

#endif