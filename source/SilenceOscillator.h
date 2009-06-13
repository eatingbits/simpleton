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
  SilenceOscillator(float samplesPerPeriod, int currentPeriod, int numOutputs);
  float generateTune(int currentPeriod, float samplesPerPeriod);
};
