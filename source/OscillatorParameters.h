#ifndef __OscillatorParameters_h__
#define __OscillatorParameters_h__

#include "OscillatorPrototype.h"
#include "ParameterComponent.h"
#include "WaveForm.h"
#include <vector>
#include <string>

class Parameter;
class NamedValueParameter;
class IntegerValueParameter;
class FloatValueParameter;
class OscillatorChangeCallback;
class Oscillator;

class OscillatorParameters : public ParameterComponent, public OscillatorPrototype {
public:
	OscillatorParameters(int index, OscillatorChangeCallback *callback, float defaultAttack, float defaultSustain);
	
  const char *getName(int index) const;
  const char *getUnit(int index) const;

	virtual int numberOfParameters() const;
  virtual void getDisplay(int index, char *outBuffer) const;
  virtual const float getCurrentValue(int index) const;
  virtual void onChange(int index, float newValue);	
	virtual Source *create(int samplesPerPeriod);

private:
	Parameter* getParameter(int index) const;
	std::string parameterName(const std::string& name);
	OscillatorType getType() const;
	void update();
	static OscillatorType typeFromString(const std::string& name);
	
	const int mIndex;
	NamedValueParameter *mType;
	FloatValueParameter *mAttack;
	FloatValueParameter *mSustain;
	IntegerValueParameter *mAttackDelay;
	IntegerValueParameter *mDecayDelay;
	IntegerValueParameter *mReleaseDelay;
	FloatValueParameter *mVolume;
	std::vector<Parameter *> mParameters;
	std::vector<WaveForm *> mWaveForms;
	OscillatorChangeCallback *mCallback;
	
};

#endif

