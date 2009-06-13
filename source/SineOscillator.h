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

#ifndef __SineGen_H
#include "SineGen.h"
#endif

class SineOscillator : public Oscillator {
public:
  SineOscillator(float samplesPerPeriod, int currentPeriod, int numOutputs);
  ~SineOscillator();  
  virtual float generateTune(int currentPeriod, float samplesPerPeriod);
};

#endif