/*
 *  osc_state.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/18/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __OscState_H
#include "OscState.h"
#endif

OscState::OscState() {
  
}

OscState::~OscState() {
  
}

const float OscState::getAmplitude() const{
  return mAmplitude;
}

void OscState::setAmplitude(const float amplitude) {
  mAmplitude = amplitude;
}

const float OscState::getFrequency() const{
  return mFrequency;
}

void OscState::setFrequency(const float frequency) {
  mFrequency = frequency;
}

const float OscState::getPosition() const{
  return mPosition;
}

void OscState::setPosition(const float position) {
  mPosition = position;
}