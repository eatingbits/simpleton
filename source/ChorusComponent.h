#ifndef __ChorusComponent_h__
#define __ChorusComponent_h__

#include "EffectParameterComponent.h"
#include "EffectPrototype.h"

class IntegerValueParameter;
class EffectChangedCallback;
class Source;

class ChorusComponent : public EffectParameterComponent {
public:
	ChorusComponent();
	virtual void reset();
	virtual Source *create(Source *source);
private:
	IntegerValueParameter *mNrOfVoices;
	IntegerValueParameter *mDelay;
};

#endif

