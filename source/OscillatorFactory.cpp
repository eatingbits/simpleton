#include "OscillatorFactory.h"
#include "EffectPrototype.h"
#include "Source.h"
#include "ChainingOscillator.h"
#include "OscillatorPrototype.h"

OscillatorFactory :: OscillatorFactory() : mEffectSlots(2), mOscillatorSlots(3) {
}

OscillatorFactory :: ~OscillatorFactory() {
	std::vector<EffectPrototype *>::iterator it = mEffectSlots.begin();
	while (it != mEffectSlots.end()) {
		//		delete *it; // as below
		it++;
	}
}

void OscillatorFactory :: effectChanged(int slot, EffectPrototype *prototype) {
	EffectPrototype *oldPrototype = mEffectSlots.at(slot);
	if (oldPrototype) {
		//delete oldPrototype; // since we reuse the parameters we can't delete here, just let go of the reference
	}
	mEffectSlots[slot] = prototype;
}

void OscillatorFactory :: oscillatorChanged(int slot, OscillatorPrototype *prototype) {
	OscillatorPrototype *oldPrototype = mOscillatorSlots.at(slot);
	if (oldPrototype) {
		//delete oldPrototype; // since we use parameters as prototypes, no deletion here
	}
	mOscillatorSlots[slot] = prototype;
}

Source *OscillatorFactory :: createEffectChain(Source *source) {
	Source *current = source;
	for (unsigned int i = 0; i < mEffectSlots.size(); ++i) {
		EffectPrototype *prototype = mEffectSlots.at(i);
		if (prototype != NULL) {
			current = prototype->create(current);
		}
	}
	return current;
}

Source *OscillatorFactory :: createOscillator(int samplesPerPeriod) {
	ChainingOscillator *oscillator = new ChainingOscillator();
	for (unsigned int i = 0; i < mOscillatorSlots.size(); ++i) {
		OscillatorPrototype *prototype = mOscillatorSlots.at(i);
		if (prototype != NULL) {
			oscillator->addOscillator(prototype->create(samplesPerPeriod));
		}
	}
	return oscillator;
}