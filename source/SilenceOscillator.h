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
	/* Silence is always 0 */
	float nextSampleValue(float samplesPerPeriod) { return 0.0; }
	/* Silence doesn't need a previous value, so just terminate the chain */
	float inputValue(float samplesPerPeriod) { return 0.0; }
private:
};
