#ifndef __GeneralComponent_h__
#define __GeneralComponent_h__

#include <vector>
#include <string>

#include "ParameterComponent.h"

class Parameter;
class NamedValueParameter;
class GeneralChangedCallback;

class GeneralComponent : public ParameterComponent {
public:
	GeneralComponent(GeneralChangedCallback *generalCallback);

  const char *getName(int index) const;
  const char *getUnit(int index) const;
	
	virtual int numberOfParameters() const;
  virtual void getDisplay(int index, char *outBuffer) const;
  virtual const float getCurrentValue(int index) const;
  virtual void onChange(int index, float newValue);	
	
private:
	Parameter* getParameter(int index) const;
//	void update();
	
private:
	GeneralChangedCallback *mCallback;
	std::vector<Parameter *> mParameters;	
	NamedValueParameter *mPolyphony;
};

#endif

