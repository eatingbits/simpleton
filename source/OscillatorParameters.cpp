#include "OscillatorParameters.h"

#include "NamedValueParameter.h"
#include "FloatValueParameter.h"
#include "IntegerValueParameter.h"
#include "OscillatorChangeCallback.h"
#include "Decibel.h"

#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

OscillatorParameters :: OscillatorParameters(int index, OscillatorChangeCallback *callback) : mIndex(index), mCallback(callback) {
	mType = new NamedValueParameter(parameterName("type").c_str(), "");
	mType->add("Noise");
  mType->add("Sine");
  mType->add("Square");
  mType->add("Saw");
	
	mAttack = new FloatValueParameter(parameterName("attack").c_str(), "dB", -60.0, 0.0);
	mSustain = new FloatValueParameter(parameterName("sustain").c_str(), "dB", -60.0, 0.0);
	mAttackDelay = new IntegerValueParameter(parameterName("attack delay").c_str(), "ms", 1, 200);
	mDecayDelay = new IntegerValueParameter(parameterName("decay delay").c_str(), "ms", 1, 500);
	mReleaseDelay = new IntegerValueParameter(parameterName("release delay").c_str(), "ms", 1, 2000);
	
	mParameters.push_back(mType);
	mParameters.push_back(mAttack);
	mParameters.push_back(mAttackDelay);
	mParameters.push_back(mDecayDelay);
	mParameters.push_back(mSustain);
	mParameters.push_back(mReleaseDelay);
	update();
}

int OscillatorParameters :: numberOfParameters() const {
	return mParameters.size();
}

const char *OscillatorParameters :: getName(int index) const {
	return getParameter(index)->getName();
}

const char *OscillatorParameters :: getUnit(int index) const {
	return getParameter(index)->getUnit();
}

void OscillatorParameters :: getDisplay(int index, char *outBuffer) const {
	getParameter(index)->getDisplay(outBuffer);
}

const float OscillatorParameters :: getCurrentValue(int index) const {
	return getParameter(index)->getCurrentValue();
}

void OscillatorParameters :: onChange(int index, float newValue) {
	getParameter(index)->onChange(newValue);
	update();
}

void OscillatorParameters :: update() {
	if (mCallback != NULL) {
		Decibel attack(mAttack->floatValue());
		Decibel sustain(mSustain->floatValue());
		float linearAttack = attack.toLinear();
		float linearSustain = sustain.toLinear();
		float linearDecay = linearSustain - linearAttack;
		//OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime
		Prototype *prototype = new Prototype(getType(), 44100, linearAttack, mAttackDelay->intValue(), linearDecay, 
																				 mDecayDelay->intValue(), mReleaseDelay->intValue());
		mCallback->oscillatorChanged(mIndex, prototype);
	}
}	

OscillatorType OscillatorParameters :: getType() const {
	string selected = mType->selectedValue();
	return Prototype::typeFromString(selected);
}

Parameter* OscillatorParameters :: getParameter(int index) const {
  return mParameters.at(index);
}

string OscillatorParameters :: parameterName(const std::string& name) {
	stringstream oscName;
	int readableIndex = mIndex + 1;
	oscName << "Osc " << readableIndex << " ";
	string parameter = oscName.str() + name;
	return parameter;
}