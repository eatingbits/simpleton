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

class Oscillator {
public:
  Oscillator();
  virtual ~Oscillator();
  void process(OscState &state);
  
  
}

#endif