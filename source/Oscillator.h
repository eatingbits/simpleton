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
  Oscillator(float *output) {};
  virtual ~Oscillator() {};
  virtual void process(OscState &state) = 0;
};

#endif