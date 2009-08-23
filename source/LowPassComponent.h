#ifndef __LowPassComponent_h__
#define __LowPassComponent_h__

#include "EffectParameterComponent.h"

class FloatValueParameter;
class Source;

class LowPassComponent : public EffectParameterComponent {
public:
	LowPassComponent();
	virtual void reset();
	virtual Source *create(Source *source);
private:
  FloatValueParameter *mFrequency;
  FloatValueParameter *mResonance;
};

#endif