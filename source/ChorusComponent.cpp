#include "ChorusComponent.h"
#include "IntegerValueParameter.h"
#include "EffectChangedCallback.h"
#include "ChorusFactory.h"

ChorusComponent :: ChorusComponent() {
	mNrOfVoices = new IntegerValueParameter("Voices", "", 1, 4, 1);
	mDelay = new IntegerValueParameter("Delay", "ms", 1, 200, 1);
	mParameters.push_back(mNrOfVoices);
	mParameters.push_back(mDelay);
}

void ChorusComponent :: reset() {
	mNrOfVoices->onChange(0.0);
	mDelay->onChange(0.0);
}

Source *ChorusComponent :: create(Source *source) {
	ChorusFactory factory;
	return factory.create(mNrOfVoices->intValue(), mDelay->intValue(), *source);
}