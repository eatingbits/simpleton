/*
 *  NamedValueParameter.h
 *  Simpleton
 *
 *  Created by Nik Reiman on 2009-07-07.
 *  Copyright 2009 Singbox AB. All rights reserved.
 *
 */

#ifndef __NamedValueParameter_h__
#define __NamedValueParameter_h__

#include <cstdlib>
#include <string>
#include <vector>

#include "Parameter.h"

static const int kMaxNamedValueParameters = 100;

class NamedValueParameter : public Parameter {
public:
  NamedValueParameter(const char *name, const char *unit);
  void add(const char *value);
  
  void getDisplay(char *outBuffer) const;
  const float getCurrentValue() const;
  void onChange(const float newValue);
  
private:
  const int valueToIndex(const float value) const;
  
  float mValue;
  std::vector<std::string> mValues;
};

#endif