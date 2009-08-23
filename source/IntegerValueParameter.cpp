#include "IntegerValueParameter.h"
#include <cstdio>

IntegerValueParameter::IntegerValueParameter(const char *name, const char *unit,
                                         const int lowValue, const int highValue, const float defaultValue, Scaler<int> *scaler) :
Parameter(name, unit),
mLowValue(lowValue),
mHighValue(highValue),
mValue(defaultValue),
mScaler(scaler)
{
}

void IntegerValueParameter::getDisplay(char *outBuffer) const {
  sprintf(outBuffer, "%d", intValue());
}

const float IntegerValueParameter::getCurrentValue() const {
  return mValue;
}

int IntegerValueParameter :: intValue() const {
	return mScaler->scale(mValue, mLowValue, mHighValue);
}

void IntegerValueParameter :: onChange(const float newValue) {
  mValue = newValue;
}
