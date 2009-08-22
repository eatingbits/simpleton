#include "EffectComponent.h"
#include "NamedValueParameter.h"
#include "IntegerValueParameter.h"
#include "EffectParameterComponent.h"
#include "ChorusComponent.h"
#include "DisabledComponent.h"

EffectComponent :: EffectComponent() {
	mEffectSlot = new NamedValueParameter("Effect", "");
	mCurrentComponent = new DisabledComponent();	
	add("Disabled", mCurrentComponent);
}

NamedValueParameter *EffectComponent :: createEffectSlot(const char *name) {
	NamedValueParameter *effectSlot = new NamedValueParameter(name, "");
	effectSlot->add("Off");
	effectSlot->add("Chorus");
	return effectSlot;
}

int EffectComponent :: numberOfParameters() const {
	return 1 + 2;
}

void EffectComponent :: add(const char *name, EffectParameterComponent *component) {
	mEffectSlot->add(name);
	mComponents.push_back(component);
}

const char *EffectComponent :: getName(int index) const {
	if (index == 0) {
		return mEffectSlot->getName();
	} 
	return mCurrentComponent->getName(index-1);
}

const char *EffectComponent :: getUnit(int index) const {
	if (index == 0) {
		return mEffectSlot->getUnit();
	} 
	return mCurrentComponent->getUnit(index - 1);
}

void EffectComponent :: getDisplay(int index, char *outBuffer) const {
	if (index == 0) {
		return mEffectSlot->getDisplay(outBuffer);
	}
	return mCurrentComponent->getDisplay(index - 1, outBuffer);
}

const float EffectComponent :: getCurrentValue(int index) const {
	if (index == 0) {
		return mEffectSlot->getCurrentValue();
	}
	return mCurrentComponent->getCurrentValue(index - 1);
}

void EffectComponent :: onChange(int index, float newValue) {
	if (index == 0) {
		mEffectSlot->onChange(newValue);
		int selected = mEffectSlot->currentIndex();
		mCurrentComponent = mComponents.at(selected);
		mCurrentComponent->reset();
	} else {
		mCurrentComponent->onChange(index - 1, newValue);
	}
	
/*	if (mPolyphony->getCurrentValue() > 0.5) {
		mCallback->onChange(true);
	} else {
		mCallback->onChange(false);
	}*/
	//	update();
}
