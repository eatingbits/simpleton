#ifndef __ChorusComponent_h__
#define __ChorusComponent_h__

#include "EffectParameterComponent.h"

class IntegerValueParameter;

class ChorusComponent : public EffectParameterComponent {
public:
	ChorusComponent();
	virtual void onChange(int index, float newValue);
	virtual void reset();
private:
	IntegerValueParameter *mNrOfVoices;
	IntegerValueParameter *mDelay;
};

#endif

