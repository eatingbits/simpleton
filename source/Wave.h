/*
 *  Wave.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __Wave__H
#define __Wave__H

class Wave {
public:
  Wave(const float frequency, const int periodLength);
  ~Wave();
  const float getFrequency() const;
  const int getPeriodLength() const;
  const float* getWave() const;
  
private:
  const float mFrequency;
  const int mPeriodLength;
  const float *mWave;
};

#endif
