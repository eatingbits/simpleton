/*
 *  osc_state.h
 *  Sine
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
  const float getAmplitude():
  void setAmplitude(const float);
  
  const float getFrequency();
  void setFrequency(const float);
  
  const float getPosition();
  void setPosition();
  
private:
  float mAplitude;
  float mFrequency;
  float mPosition;
};

#endif