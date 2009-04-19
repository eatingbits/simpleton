/*
 *  WaveGen.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __WaveGen_H
#define __WaveGen_H

#ifndef __Wave__H
#include "Wave.h"
#endif

class WaveGen {
public:  
  WaveGen() {};
  virtual ~WaveGen() {};
  virtual const Wave& generatePeriod(const float frequency, const int periodLength) = 0;
};

#endif

