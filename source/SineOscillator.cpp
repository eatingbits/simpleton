/*
 *  SineOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SineOscillator__H
#include "SineOscillator.h"
#endif
#include <math.h>

SineOscillator::SineOscillator(float samplesPerPeriod, int currentPeriod, int numOutputs) : 
Oscillator(samplesPerPeriod, currentPeriod, numOutputs) {
}

SineOscillator::~SineOscillator() {
  
}

float SineOscillator :: generateTune(int currentPeriod, float samplesPerPeriod) {
  return sin(currentPeriod / (samplesPerPeriod) * 2 * M_PI);
}
