#ifndef __EFfectChangedCallback_h__
#define __EFfectChangedCallback_h__

class EffectPrototype;

class EffectChangedCallback {
public:
	virtual ~EffectChangedCallback() {}
	virtual void effectChanged(int slot, EffectPrototype *prototype) = 0;
};

#endif

