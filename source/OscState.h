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
public:
  OscState();
  ~OscState();
  
  const float getAmplitude() const;
  void setAmplitude(const float amplitude);
  
  const float getFrequency() const;
  void setFrequency(const float frequency);
  
  const float getPosition() const;
  void setPosition(const float position);
  
private:
  float mAmplitude;
  float mFrequency;
  float mPosition;
};

#endif