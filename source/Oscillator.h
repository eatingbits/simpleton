/*
 *  oscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/18/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __Oscillator__H
#define __Oscillator__H

#include <cstdlib>
#include "OscillatorInput.h"
#include "Envelope.h"

class Buffer;

class Oscillator : public OscillatorInput {
public:
	Oscillator(Oscillator* oscillator)  : mInput(oscillator), mFrequencyModifier(NULL), mEnvelope(NULL)  {}
	virtual ~Oscillator();

	void noteOn() { if (mEnvelope != NULL) mEnvelope->noteOn(); if (mInput != NULL) mInput->noteOn(); }
	void noteOff() { if (mEnvelope != NULL) mEnvelope->noteOff(); if (mInput != NULL) mInput->noteOff(); }
	
	/* Sets a frequency modifier input */
	void setFrequencyModifier(OscillatorInput *freqMod) { mFrequencyModifier = freqMod; }	
	void setEnvelope(Envelope *envelope) { mEnvelope = envelope; }
	/* Returns the next sample value */
	float sampleValue();
	virtual bool isPlaying() { return (mEnvelope != NULL && mEnvelope->isPlaying()); }
protected:
	/* Implemented by sub classes */
	virtual float nextSampleValue() = 0;
	/* Returns the current frequency modifier */
	float getFrequencyModifier();
	/* Returns the current amplitude modifier */
	float getAmplitudeModifier();
	/* Returns the base input value */
	virtual float inputValue();
	
private:
	Oscillator *mInput;
	OscillatorInput *mFrequencyModifier;
	Envelope *mEnvelope;
};

#endif