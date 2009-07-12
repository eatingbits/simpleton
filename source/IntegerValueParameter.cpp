#include "IntegerValueParameter.h"

#include "ParameterCallback.h"

IntegerValueParameter::IntegerValueParameter(const char *name, const char *unit,
                                         const int lowValue, const int highValue) :
Parameter(name, unit),
mLowValue(lowValue),
mHighValue(highValue),
mValue(0.0f)
{
}

void IntegerValueParameter::getDisplay(char *outBuffer) const {
  sprintf(outBuffer, "%d", getCurrentIntValue());
}

const float IntegerValueParameter::getCurrentValue() const {
  return (float) mValue * (mHighValue - mLowValue) + mLowValue;
}

const int IntegerValueParameter :: getCurrentIntValue() const {
	return mValue * (mHighValue - mLowValue) + mLowValue;
}

void IntegerValueParameter::onChange(const float newValue, ParameterCallback *callback) {
  mValue = newValue;
	if (callback != NULL) {
		callback->integerValueChanged(getCurrentValue());
	}
}

void IntegerValueParameter::update(ParameterCallback *callback) {
	onChange(mValue, callback);
}