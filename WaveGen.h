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

class WaveGen {
  WaveGen() {};
  virtual ~WaveGen() {};
public:
  virtual const float *period generatePeriod() = 0;
};

#endif

