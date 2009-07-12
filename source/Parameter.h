#ifndef __Parameter_h__
#define __Parameter_h__

#include <cstring>

class ParameterCallback;

class Parameter {
public:
  Parameter(const char *name, const char *unit) {
    strncpy(mName, name, kParameterNameLength);
    strncpy(mUnit, unit, kParameterUnitLength);
  }
  
  virtual ~Parameter() {};
  const char *getName() const { return mName; };
  const char *getUnit() const { return mUnit; };
  
  virtual void getDisplay(char *outBuffer) const = 0;
  virtual const float getCurrentValue() const = 0;
  virtual void onChange(const float newValue, ParameterCallback *callback) = 0;
	virtual void update(ParameterCallback *callback) = 0;
private:
	
	enum kFieldLengths {
		kParameterNameLength = 64,
		kParameterUnitLength = 8
	};
	
  char mName[kParameterNameLength];
  char mUnit[kParameterUnitLength];
};

#endif