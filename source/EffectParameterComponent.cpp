#include "EffectParameterComponent.h"
#include "Parameter.h"

EffectParameterComponent :: EffectParameterComponent() {
}

int EffectParameterComponent :: numberOfParameters() const {
	return mParameters.size();
}

const char *EffectParameterComponent :: getName(int index) const {
	return getParameter(index)->getName();
}

const char *EffectParameterComponent :: getUnit(int index) const {
	return getParameter(index)->getUnit();
}

void EffectParameterComponent :: getDisplay(int index, char *outBuffer) const {
	getParameter(index)->getDisplay(outBuffer);
}

const float EffectParameterComponent :: getCurrentValue(int index) const {
	return getParameter(index)->getCurrentValue();
}

void EffectParameterComponent :: onChange(int index, float newValue) {
	getParameter(index)->onChange(newValue);
}

Parameter* EffectParameterComponent :: getParameter(int index) const {
  return mParameters.at(index);
}
