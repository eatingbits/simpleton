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
	return oscillator;
}

void OscillatorPrototype :: add(OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime) {
	Prototype *prototype = new Prototype(type, sampleRate, attackAmplitude, attackTime, decayAmplitude, decayTime, releaseTime);
	mPrototypes[mPrototypeSize++] = prototype;
}

void OscillatorPrototype :: setAttack(float attackAmplitude) {
	mPrototypes[mPrototypeSize-1]->setAttack(attackAmplitude);
}

void OscillatorPrototype :: setAttackTime(int attackTime) {
	mPrototypes[mPrototypeSize-1]->setAttackTime(attackTime);
}

void OscillatorPrototype :: setDecay(float decayAmplitude) {
	mPrototypes[mPrototypeSize-1]->setDecay(decayAmplitude);
}

void OscillatorPrototype :: setDecayTime(int decayTime) {
	mPrototypes[mPrototypeSize-1]->setDecayTime(decayTime);
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
		current = prototype->create(current, samplesPerPeriod);
	}
	return current;
}
