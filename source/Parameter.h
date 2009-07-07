/*
 *  Parameter.h
 *  Simpleton
 *
 *  Created by Nik Reiman on 2009-07-07.
 *  Copyright 2009 Singbox AB. All rights reserved.
 *
 */

#ifndef __Parameter_h__
#define __Parameter_h__

#include <cstring>

const int kParameterNameLength = 64;
const int kParameterUnitLength = 8;

class Parameter {
public:
  Parameter(const char *name, const char *unit) {
    strncpy(mName, name, kParameterNameLength);
    strncpy(mUnit, unit, kParameterUnitLength);
  }
  
  virtual ~Parameter() {};
  const char *getName() const { return mName; };
  const char *getUnit() const { return mUnit; };
  
  virtual void getDisplay(char *outBuffer) const = 0;
  virtual const float getCurrentValue() const = 0;
  virtual void onChange(const float newValue) = 0;
  
private:
  char mName[kParameterNameLength];
  char mUnit[kParameterUnitLength];
};

#endif