#include "GeneralComponent.h"
#include "GeneralChangedCallback.h"

#include "NamedValueParameter.h"

#include <string>

using std::string;
using std::vector;

GeneralComponent :: GeneralComponent(GeneralChangedCallback *generalCallback) : mCallback(generalCallback) {
	mPolyphony = new NamedValueParameter("Polyphony", "");
	mPolyphony->add("Off");
	mPolyphony->add("On");
	
	mParameters.push_back(mPolyphony);
}

int GeneralComponent :: numberOfParameters() const {
	return mParameters.size();
}

const char *GeneralComponent :: getName(int index) const {
	return getParameter(index)->getName();
}

const char *GeneralComponent :: getUnit(int index) const {
	return getParameter(index)->getUnit();
}

void GeneralComponent :: getDisplay(int index, char *outBuffer) const {
	getParameter(index)->getDisplay(outBuffer);
}

const float GeneralComponent :: getCurrentValue(int index) const {
	return getParameter(index)->getCurrentValue();
}

void GeneralComponent :: onChange(int index, float newValue) {
	getParameter(index)->onChange(newValue);
	if (mPolyphony->getCurrentValue() > 0.5) {
		mCallback->onChange(true);
	} else {
		mCallback->onChange(false);
	}
//	update();
}

Parameter* GeneralComponent :: getParameter(int index) const {
  return mParameters.at(index);
}
