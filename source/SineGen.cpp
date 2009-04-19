/*
 *  SineGen.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __SineGen__H
#include "SineGen.h"
#endif

SineGen::SineGen() {

}

SineGen::~SineGen() {
  
}

const Wave& SineGen::generatePeriod(const float frequency, const int bufferLength) {
  //Do we already have a wave with the same frequency, bufferLength?
    //return old wave
  //else
    //Generate a wave, store it and return a reference.
}
