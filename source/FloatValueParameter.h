/*
 *  FloatValueParameter.h
 *  Simpleton
 *
 *  Created by Nik Reiman on 2009-07-07.
 *  Copyright 2009 Singbox AB. All rights reserved.
 *
 */

#ifndef __FloatValueParameter_h__
#define __FloatValueParameter_h__

#include <stdio.h>
#include <cstdlib>
#include "Parameter.h"

class FloatValueParameter : public Parameter {
public:
  FloatValueParameter(const char *name, const char *unit, const float lowValue, const float hiValue);
  
  void getDisplay(char *outBuffer) const;
  const float getCurrentValue() const;
  void onChange(const float newValue);
  
private:
  const float mLowValue;
  const float mHiValue;
  float mValue;
};

#endif