/*
 *  SquareOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __SquareOscillator__H
#define __SquareOscillator__H

#ifndef __Oscillator__H
#include "Oscillator.h"
#endif


class SquareOscillator : public Oscillator {
public:
  SquareOscillator(float samplesPerPeriod, int currentPeriod, int numOutputs);
  virtual float generateTune(int currentPeriod, float samplesPerPeriod);
};

#endif