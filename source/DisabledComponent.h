#ifndef __DisabledComponent_h__
#define __DisabledComponent_h__

class DisabledComponent : public EffectParameterComponent {
public:
  const char *getName(int index) const { return "Disabled"; }
  const char *getUnit(int index) const { return ""; }
	
	virtual int numberOfParameters() const { return 0; }
  virtual void getDisplay(int index, char *outBuffer) const {}
  virtual const float getCurrentValue(int index) const { return 0; }
  virtual void onChange(int index, float newValue) {}
	virtual void reset() {}
	
};

#endif

