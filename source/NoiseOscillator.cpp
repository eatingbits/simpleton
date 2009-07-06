/*
 *  NoiseOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "NoiseOscillator.h"
#include <cstdlib>

float NoiseOscillator :: nextSampleValue() {
	float amplitudeModifier = getAmplitudeModifier();
	long value = random();
	float ret = ((float) (1000 - (value % 2000))) / 1000.0;
	return amplitudeModifier * ret;
}
