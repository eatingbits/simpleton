/*
 *  Wave.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __Wave__H
#include "Wave.h"
#endif

Wave::Wave(const float frequency, const int periodLength) 
  : mFrequency(frequency),mPeriodLength(periodLength) {
}

Wave::~Wave() {
}

const float Wave::getFrequency() const {
  return mFrequency;
}

const int Wave::getPeriodLength() const {
  return mPeriodLength;
}

const float* Wave::getWave() const {
  return mWave;
}
