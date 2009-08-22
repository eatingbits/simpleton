#ifndef __EffectComponent_h__
#define __EffectComponent_h__

#include <vector>
#include "ParameterComponent.h"

class NamedValueParameter;
class IntegerValueParameter;
class EffectParameterComponent;
class Parameter;
class EffectChangedCallback;

class EffectComponent : public ParameterComponent {
public:
	EffectComponent(int slot, EffectChangedCallback *effectChanged);
	
  const char *getName(int index) const;
  const char *getUnit(int index) const;
	
	void add(const char *name, EffectParameterComponent *component);
	
	virtual int numberOfParameters() const;
  virtual void getDisplay(int index, char *outBuffer) const;
  virtual const float getCurrentValue(int index) const;
  virtual void onChange(int index, float newValue);	
	
private:
	NamedValueParameter *createEffectSlot(const char *name);
	
	int mSlot;
	EffectChangedCallback *mEffectChanged;
	
	NamedValueParameter *mEffectSlot;
	EffectParameterComponent *mCurrentComponent;
	std::vector<EffectParameterComponent *> mComponents;
};

#endif

