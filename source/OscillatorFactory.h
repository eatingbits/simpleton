#ifndef __OscillatorFactory_h__
#define __OscillatorFactory_h__

#include <vector>
#include "EffectChangedCallback.h"
#include "OscillatorChangeCallback.h"

class OscillatorPrototype;
class EffectPrototype;
class Source;

class OscillatorFactory : public OscillatorChangeCallback, public EffectChangedCallback {
public:
	OscillatorFactory();
	~OscillatorFactory();
	void effectChanged(int slot, EffectPrototype *prototype);
	void oscillatorChanged(int slot, OscillatorPrototype *prototype);
	Source *createEffectChain(Source *source);
	Source *createOscillator(int samplesPerPeriod);
private:
	std::vector<EffectPrototype *> mEffectSlots;
	std::vector<OscillatorPrototype *> mOscillatorSlots;
};

#endif

