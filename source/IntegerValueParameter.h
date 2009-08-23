#ifndef __IntegerValueParameter_h__
#define __IntegerValueParameter_h__

#include "Parameter.h"
#include "Scaler.h"

class IntegerValueParameter : public Parameter {
public:
  IntegerValueParameter(const char *name, const char *unit, const int lowValue, const int highValue, const float defaultValue, Scaler<int> *scaler);
  
  void getDisplay(char *outBuffer) const;
  const float getCurrentValue() const;
	int intValue() const;
  void onChange(const float newValue);
  
private:
  const float mLowValue;
  const float mHighValue;
  float mValue;
	Scaler<int> *mScaler;
};

#endif

