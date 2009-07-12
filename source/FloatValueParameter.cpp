#include "FloatValueParameter.h"

FloatValueParameter::FloatValueParameter(const char *name, const char *unit,
                                         const float lowValue, const float hiValue) :
Parameter(name, unit),
mLowValue(lowValue),
mHiValue(hiValue),
mValue(0.0f)
{
}

void FloatValueParameter::getDisplay(char *outBuffer) const {
  sprintf(outBuffer, "%3.2f", mValue);
}

const float FloatValueParameter::getCurrentValue() const {
  return mValue;
}

void FloatValueParameter::onChange(const float newValue) {
  mValue = newValue * (mHiValue - mLowValue) + mLowValue;
}