/*
 *  SquareOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "SquareOscillator.h"
#include <iostream>

SquareOscillator::SquareOscillator(float samplesPerPeriod, int currentPeriod, int numOutputs) : 
Oscillator(samplesPerPeriod, currentPeriod, numOutputs) {
}


float SquareOscillator :: generateTune(int currentPeriod, float samplesPerPeriod) {
  int half = ((int) samplesPerPeriod) / 2;\
  //std::cout << "p: " << currentPeriod << " h: " << half;
  if(currentPeriod > half) {
    //std::cout << " v: -1" << std::endl;
    return -1.0;
  }
  //std::cout << " v: 1" << std::endl;
  return 1.0;
}