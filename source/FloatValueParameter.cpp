#include "FloatValueParameter.h"
#include "ParameterCallback.h"

FloatValueParameter::FloatValueParameter(const char *name, const char *unit,
                                         const float lowValue, const float hiValue) :
Parameter(name, unit),
mLowValue(lowValue),
mHiValue(hiValue),
mValue(0.0f)
{
}

void FloatValueParameter::getDisplay(char *outBuffer) const {
  sprintf(outBuffer, "%3.2f", getCurrentValue());
}

const float FloatValueParameter::getCurrentValue() const {
  return mValue * (mHiValue - mLowValue) + mLowValue;
}

void FloatValueParameter::onChange(const float newValue, ParameterCallback *callback) {
  mValue = newValue;
	if (callback != NULL) {
		callback->floatValueChanged(getCurrentValue());
	}
}

void FloatValueParameter::update(ParameterCallback *callback) {
	onChange(mValue, callback);
}