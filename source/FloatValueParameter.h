#ifndef __FloatValueParameter_h__
#define __FloatValueParameter_h__

#include <stdio.h>
#include <cstdlib>
#include "Parameter.h"

class FloatValueParameter : public Parameter {
public:
  FloatValueParameter(const char *name, const char *unit, const float lowValue, const float hiValue, const float defaultValue);
  
  void getDisplay(char *outBuffer) const;
  const float getCurrentValue() const;
  void onChange(const float newValue);
	float floatValue() const;
  
private:
  const float mLowValue;
  const float mHiValue;
  float mValue;
};

#endif