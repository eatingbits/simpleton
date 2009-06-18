/*
 *  SilenceOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "Oscillator.h"

class SilenceOscillator : public Oscillator {
public:
	SilenceOscillator();
	float nextSampleValue(float samplesPerPeriod) { return 0.0; }
	float previousValue(float samplesPerPeriod) { return 0.0; }
private:
};
