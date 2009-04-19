/*
 *  SineGen.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __SineGen_H
#define __SineGen_H

#ifndef __WaveGen__H
#include "WaveGen.h"
#endif

class SineGen : public WaveGen {
public:
  SineGen();
  ~SineGen();
  const Wave & generatePeriod(const float frequency, const int periodLength);
};

#endif