/*
 *  SilenceOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "SilenceOscillator.h"

SilenceOscillator :: SilenceOscillator(float samplesPerPeriod, int currentPeriod, int numOutputs) : 
Oscillator(samplesPerPeriod, currentPeriod, numOutputs) {
}

float SilenceOscillator :: generateTune(int currentPeriod, float samplesPerPeriod) {
  return 0.0;
}


