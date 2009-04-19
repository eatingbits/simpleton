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

SineOscillator::SineOscillator(float *output) : Oscillator(output) {
  mPeriodGenerator = new SineGen();
}

SineOscillator::~SineOscillator() {
  
}

void SineOscillator::process(OscState &state) {
  //Call SineGen until block is full, save in state.

}
