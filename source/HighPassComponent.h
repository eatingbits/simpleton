#ifndef __HighPassComponent_h__
#define __HighPassComponent_h__

#include "EffectParameterComponent.h"

class FloatValueParameter;
class Source;

class HighPassComponent : public EffectParameterComponent {
public:
	HighPassComponent();
	virtual void reset();
	virtual Source *create(Source *source);
private:
  FloatValueParameter *mFrequency;
  FloatValueParameter *mResonance;
};

#endif