#include "OscillatorParameters.h"

#include "NamedValueParameter.h"
#include "FloatValueParameter.h"
#include "IntegerValueParameter.h"
#include "OscillatorChangeCallback.h"
#include "Decibel.h"
#include "LinearScale.h"
#include "LogarithmicScale.h"
#include "SineWave.h"
#include "SquareWave.h"
#include "SawWave.h"
#include "NoiseWave.h"
#include "ADSREnvelope.h"
#include "WaveFormOscillator.h"

#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

OscillatorParameters :: OscillatorParameters(int index, OscillatorChangeCallback *callback, float defaultAttack, float defaultSustain) : mIndex(index), mCallback(callback) {
	
	mWaveForms.push_back(new SineWave());
	mWaveForms.push_back(new SquareWave());
	mWaveForms.push_back(new SawWave());
	mWaveForms.push_back(new NoiseWave());
	
	mType = new NamedValueParameter(parameterName("type").c_str(), "");
	for (std::vector<WaveForm *>::iterator it = mWaveForms.begin(); it != mWaveForms.end(); ++it) {
		mType->add((*it)->name().c_str());
	}
	
	mVolume = new FloatValueParameter(parameterName("volume").c_str(), "dB", -60.0, 0.0, 1.0, new LinearScale<float>());
	mAttack = new FloatValueParameter(parameterName("attack").c_str(), "dB", -60.0, 0.0, defaultAttack, new LinearScale<float>());
	mSustain = new FloatValueParameter(parameterName("sustain").c_str(), "dB", -60.0, 0.0, defaultSustain, new LinearScale<float>());
	mAttackDelay = new IntegerValueParameter(parameterName("attack delay").c_str(), "ms", 1, 200, 0.0, new LogarithmicScale<int>());
	mDecayDelay = new IntegerValueParameter(parameterName("decay delay").c_str(), "ms", 1, 500, 0.0, new LogarithmicScale<int>());
	mReleaseDelay = new IntegerValueParameter(parameterName("release delay").c_str(), "ms", 10, 2000, 0.0, new LogarithmicScale<int>());
	
	mParameters.push_back(mType);
	mParameters.push_back(mVolume);
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
		mCallback->oscillatorChanged(mIndex, this);
	}
}	

Source *OscillatorParameters :: create(int samplesPerPeriod) {
	Decibel attack(mAttack->floatValue());
	Decibel sustain(mSustain->floatValue());
	Decibel volume(mVolume->floatValue());
	float linearAttack = attack.toLinear();
	float linearSustain = sustain.toLinear();
	float linearDecay = linearSustain - linearAttack;
	float linearVolume = volume.toLinear();
	
	ADSREnvelope *envelope = new ADSREnvelope(44100);
	envelope->setDecay(linearDecay, mDecayDelay->intValue());
	envelope->setAttack(linearAttack, mAttackDelay->intValue());
	envelope->setRelease(mReleaseDelay->intValue());
	
	return new WaveFormOscillator(mWaveForms.at(mType->currentIndex()), envelope, samplesPerPeriod, linearVolume);
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