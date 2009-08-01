#include "FloatValueParameter.h"

FloatValueParameter::FloatValueParameter(const char *name, const char *unit,
                                         const float lowValue, const float hiValue, const float defaultValue) :
Parameter(name, unit),
mLowValue(lowValue),
mHiValue(hiValue),
mValue(defaultValue)
{
}

void FloatValueParameter::getDisplay(char *outBuffer) const {
  sprintf(outBuffer, "%3.2f", floatValue());
}

float FloatValueParameter::floatValue() const {
  return mValue * (mHiValue - mLowValue) + mLowValue;
}

const float FloatValueParameter::getCurrentValue() const {
	return mValue;
}

void FloatValueParameter::onChange(float newValue) {
  mValue = newValue;
}