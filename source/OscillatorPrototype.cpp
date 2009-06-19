/*
 *  OscillatorPrototype.cpp
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "OscillatorPrototype.h"
#include "Oscillator.h"
#include "SineOscillator.h"
#include "SquareOscillator.h"
#include "SilenceOscillator.h"
#include "ADSREnvelope.h"
#include <cstdlib>

Oscillator *Prototype :: create(Oscillator& parent, float samplesPerPeriod) {
	Oscillator *oscillator = NULL;
	if (mType == kSineOscillator) {
		oscillator = new SineOscillator(parent, samplesPerPeriod);
	} else if (mType == kSquareOscillator) {
		oscillator = new SquareOscillator(parent, samplesPerPeriod);
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

Oscillator *OscillatorPrototype :: create(float samplesPerPeriod) {
	SilenceOscillator *silence = new SilenceOscillator();
	Oscillator *current = silence;
	
	for (int oscillator = 0; oscillator < mPrototypeSize; ++oscillator) {
		Prototype *prototype = mPrototypes[oscillator];
		current = prototype->create(*current, samplesPerPeriod);
	}
	return current;
}
