#include "OscillatorPrototype.h"
#include "Oscillator.h"
#include "SineOscillator.h"
#include "SquareOscillator.h"
#include "SilenceOscillator.h"
#include "SawOscillator.h"
#include "NoiseOscillator.h"
#include "ADSREnvelope.h"
#include <cstdlib>

Oscillator *Prototype :: create(Oscillator *parent, float samplesPerPeriod) {
	Oscillator *oscillator = NULL;
	if (mType == kSineOscillator) {
		oscillator = new SineOscillator(parent, samplesPerPeriod);
	} else if (mType == kSquareOscillator) {
		oscillator = new SquareOscillator(parent, samplesPerPeriod);
	} else if (mType == kSawOscillator) {
		oscillator = new SawOscillator(parent, samplesPerPeriod, false);
	} else if (mType == kReverseSawOscillator) {
		oscillator = new SawOscillator(parent, samplesPerPeriod, true);
	} else if (mType == kNoiseOscillator) {
		oscillator = new NoiseOscillator(parent);
	}
	
	ADSREnvelope *envelope = new ADSREnvelope(mSampleRate);
	envelope->setAttack(mAttackAmplitude, mAttackTime);
	envelope->setDecay(mDecayAmplitude, mDecayTime);
	envelope->setRelease(mReleaseTime);
	
	oscillator->setEnvelope(envelope);
	oscillator->setVolume(mVolume);
	return oscillator;
}

OscillatorType Prototype :: typeFromString(const std::string& value) {
	if (value == "Sine") {
		return kSineOscillator;
	} else if (value == "Square") {
		return kSquareOscillator;
	} else if (value == "Saw") {
		return kSawOscillator;
	} else if (value == "Noise") {
		return kNoiseOscillator;
	}
	return kSineOscillator;
}

OscillatorPrototype :: OscillatorPrototype() : mPrototypeSize(0) {
	for (int i = 0; i < 4; ++i) {
		mPrototypes[i] = NULL;
	}
}

void OscillatorPrototype :: add(OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime) {
	Prototype *prototype = new Prototype(type, sampleRate, attackAmplitude, attackTime, decayAmplitude, decayTime, releaseTime, 1.0);
	mPrototypes[mPrototypeSize++] = prototype;
}

void OscillatorPrototype :: replace(int index, Prototype *prototype) {
	Prototype *old = mPrototypes[index];
	mPrototypes[index] = prototype;
	if (old != NULL) {
		delete old;
	}
	for (int i = 0; i < 4; ++i) {
		if (mPrototypes[i] == NULL) {
			mPrototypeSize = i;
			break;
		}
	}
}

void OscillatorPrototype :: clear() {
	if (mPrototypeSize > 0) {
		for (int i = mPrototypeSize - 1; i >= 0; i--) {
			Prototype *prototype = mPrototypes[i];
			mPrototypes[i] = NULL;
			delete prototype;
		}
	}
	mPrototypeSize = 0;
}

Oscillator *OscillatorPrototype :: create(float samplesPerPeriod) {
	SilenceOscillator *silence = new SilenceOscillator();
	Oscillator *current = silence;
	
	for (int oscillator = 0; oscillator < mPrototypeSize; ++oscillator) {
		Prototype *prototype = mPrototypes[oscillator];
		if (!prototype->isSilent()) {
			current = prototype->create(current, samplesPerPeriod);
		}
	}
	return current;
}
