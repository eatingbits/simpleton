/*
 *  oscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/18/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __Oscillator__H
#define __Oscillator__H

#ifndef __OscState_H
#include "OscState.h"
#endif

class Oscillator {
public:
  Oscillator(float samplesPerPeriod, int currentPeriod, int numOutputs);
  virtual ~Oscillator() {};
  virtual float generateTune(int currentPeriod, float samplesPerPeriod) = 0;
  void generateFrames(float **outputs, int framesToGenerate);
private:
  float mSamplesPerPeriod;
  int mCurrentPeriod;
  int mNumOutputs;
};

#endif