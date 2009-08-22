#include "EffectFactory.h"
#include "EffectPrototype.h"
#include "Source.h"

EffectFactory :: EffectFactory() : mEffectSlots(2) {
}

EffectFactory :: ~EffectFactory() {
	std::vector<EffectPrototype *>::iterator it = mEffectSlots.begin();
	while (it != mEffectSlots.end()) {
//		delete *it; // as below
		it++;
	}
}

void EffectFactory :: effectChanged(int slot, EffectPrototype *prototype) {
	EffectPrototype *oldPrototype = mEffectSlots.at(slot);
	if (oldPrototype) {
		//delete oldPrototype; // since we reuse the parameters we can't delete here, just let go of the reference
	}
	mEffectSlots[slot] = prototype;
}

Source *EffectFactory :: createEffectChain(Source *source) {
	Source *current = source;
	for (unsigned int i = 0; i < mEffectSlots.size(); ++i) {
		EffectPrototype *prototype = mEffectSlots.at(i);
		if (prototype != NULL) {
			current = prototype->create(current);
		}
	}
	return current;
}