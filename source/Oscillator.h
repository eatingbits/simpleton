#ifndef __Oscillator__H
#define __Oscillator__H

#include <cstdlib>
#include "OscillatorInput.h"
#include "Envelope.h"
#include "Source.h"

class Oscillator : public OscillatorInput, public Source {
public:
	Oscillator(Oscillator* oscillator)  : mInput(oscillator), mFrequencyModifier(NULL), mEnvelope(NULL), mNoteOn(false)  {}
	virtual ~Oscillator();

	void noteOn() { mNoteOn = true; if (mEnvelope != NULL) mEnvelope->noteOn(); if (mInput != NULL) mInput->noteOn(); }
	void noteOff() { mNoteOn = false; if (mEnvelope != NULL) mEnvelope->noteOff(); if (mInput != NULL) mInput->noteOff(); }
	
	/* Sets a frequency modifier input */
	void setFrequencyModifier(OscillatorInput *freqMod) { mFrequencyModifier = freqMod; }	
	void setEnvelope(Envelope *envelope) { mEnvelope = envelope; }
	/* Returns the next sample value */
	virtual float sampleValue();
	virtual bool isPlaying() { return (mEnvelope != NULL && mEnvelope->isPlaying()); }
	bool isNoteOn() { return mNoteOn; }
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
	bool mNoteOn;
};

#endif