#include "IntegerValueParameter.h"
#include <cstdio>

IntegerValueParameter::IntegerValueParameter(const char *name, const char *unit,
                                         const int lowValue, const int highValue) :
Parameter(name, unit),
mLowValue(lowValue),
mHighValue(highValue),
mValue(0.0f)
{
}

void IntegerValueParameter::getDisplay(char *outBuffer) const {
  sprintf(outBuffer, "%d", intValue());
}

const float IntegerValueParameter::getCurrentValue() const {
  return (float) mValue * (mHighValue - mLowValue) + mLowValue;
}

int IntegerValueParameter :: intValue() const {
	return mValue * (mHighValue - mLowValue) + mLowValue;
}

void IntegerValueParameter::onChange(const float newValue) {
  mValue = newValue;
}
