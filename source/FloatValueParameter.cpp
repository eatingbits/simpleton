#include "FloatValueParameter.h"

FloatValueParameter::FloatValueParameter(const char *name, const char *unit,
                                         const float lowValue, const float hiValue, const float defaultValue, Scaler<float> *scaler) :
Parameter(name, unit),
mLowValue(lowValue),
mHiValue(hiValue),
mValue(defaultValue),
mScaler(scaler)
{
}

void FloatValueParameter::getDisplay(char *outBuffer) const {
  sprintf(outBuffer, "%3.2f", floatValue());
}

float FloatValueParameter::floatValue() const {
  return mScaler->scale(mValue, mLowValue, mHiValue);
}

const float FloatValueParameter::getCurrentValue() const {
	return mValue;
}

void FloatValueParameter::onChange(float newValue) {
  mValue = newValue;
}