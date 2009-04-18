/*
 *  osc_state.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/18/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */
#ifndef __OscState_H
#define __OscState_H

class OscState {
  OscState();
  ~OscState();
  
public:
  const float getAmplitude();
  void setAmplitude(const float amplitude);
  
  const float getFrequency();
  void setFrequency(const float frequency);
  
  const float getPosition();
  void setPosition(const float position);
  
private:
  float mAmplitude;
  float mFrequency;
  float mPosition;
};

#endif