#ifndef __EffectFactory_h__
#define __EffectFactory_h__

#include <vector>
#include "EffectChangedCallback.h"

class EffectPrototype;
class Source;

class EffectFactory : public EffectChangedCallback {
public:
	EffectFactory();
	~EffectFactory();
	void effectChanged(int slot, EffectPrototype *prototype);
	Source *createEffectChain(Source *source);
private:
	std::vector<EffectPrototype *> mEffectSlots;
};

#endif

