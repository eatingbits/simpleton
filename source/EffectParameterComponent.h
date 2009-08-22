#ifndef __EffectParameterComponent_h__
#define __EffectParameterComponent_h__

#include <vector>
#include "ParameterComponent.h"

class Parameter;

class EffectParameterComponent : public ParameterComponent {
public:
	EffectParameterComponent();
	
  const char *getName(int index) const;
  const char *getUnit(int index) const;
	
	virtual int numberOfParameters() const;
  virtual void getDisplay(int index, char *outBuffer) const;
  virtual const float getCurrentValue(int index) const;
  virtual void onChange(int index, float newValue);	
	virtual void reset() = 0;
	
protected:
	Parameter *getParameter(int index) const;
	std::vector<Parameter *> mParameters;
};

#endif

