#include "GeneralComponent.h"
#include "GeneralChangedCallback.h"

#include "NamedValueParameter.h"
#include "IntegerValueParameter.h"

#include <string>
#include <iostream>
#include <pthread.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;

GeneralComponent :: GeneralComponent(GeneralChangedCallback *generalCallback) : mCallback(generalCallback) {
	
	mPolyphony = new NamedValueParameter("Polyphony", "");
	mPolyphony->add("Off");
	mPolyphony->add("On");
	
	mParameters.push_back(new IntegerValueParameter("Live 8 bug fix", "", 0, 0, 0));
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
	cout << "GetCurrentValue" << endl;	
	return getParameter(index)->getCurrentValue();
}

void GeneralComponent :: onChange(int index, float newValue) {
	getParameter(index)->onChange(newValue);

	int choice = mPolyphony->currentIndex();
	char buf[256];
	mPolyphony->getDisplay(buf);
	pthread_t id = pthread_self();
	cout << id << " P: " << newValue << " " << index << " " << mPolyphony->getCurrentValue() << " c: " << choice << " d: " << buf << endl;
	if (choice == 0) {
		mCallback->onChange(false);
	} else {
		mCallback->onChange(true);
	}
}

Parameter* GeneralComponent :: getParameter(int index) const {
  return mParameters.at(index);
}
