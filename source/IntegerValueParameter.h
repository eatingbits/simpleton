#ifndef __IntegerValueParameter_h__
#define __IntegerValueParameter_h__

#include "Parameter.h"

class IntegerValueParameter : public Parameter {
public:
  IntegerValueParameter(const char *name, const char *unit, const int lowValue, const int highValue, const float defaultValue);
  
  void getDisplay(char *outBuffer) const;
  const float getCurrentValue() const;
	int intValue() const;
  void onChange(const float newValue);
  
private:
  const float mLowValue;
  const float mHighValue;
  float mValue;
};

#endif

