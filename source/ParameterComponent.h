#ifndef __ParameterComponent_h__
#define __ParameterComponent_h__

class ParameterComponent {
public:
	virtual ~ParameterComponent() {}
	
  virtual const char *getName(int index) const = 0;
  virtual const char *getUnit(int index) const = 0;
	
  virtual void getDisplay(int index, char *outBuffer) const = 0;
  virtual const float getCurrentValue(int index) const = 0;
  virtual void onChange(int index, float newValue) = 0;
	virtual int numberOfParameters() const = 0;
};

#endif

