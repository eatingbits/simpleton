#ifndef __IntegerValueParameter_h__
#define __IntegerValueParameter_h__

#include "Parameter.h"

class IntegerValueParameter : public Parameter {
public:
  IntegerValueParameter(const char *name, const char *unit, const int lowValue, const int highValue);
  
  void getDisplay(char *outBuffer) const;
  const float getCurrentValue() const;
	const int getCurrentIntValue() const;
  void onChange(const float newValue, ParameterCallback *callback);
	void update(ParameterCallback *callback);	
  
private:
  const float mLowValue;
  const float mHighValue;
  float mValue;
};

#endif

