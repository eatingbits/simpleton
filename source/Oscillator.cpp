#include "Oscillator.h"
#include "Envelope.h"

Oscillator :: ~Oscillator() {
	if (mEnvelope != NULL) {
		delete mEnvelope;
	}
	if (mFrequencyModifier != NULL) {
		delete mFrequencyModifier;
	}
	if (mInput != NULL) {
		delete mInput;
	}
}

float Oscillator :: sampleValue() {
	float previous = inputValue();
	float nValue = previous + nextSampleValue()  * mVolume;
	
	return nValue;
}

float Oscillator :: getFrequencyModifier() {
	if (mFrequencyModifier == NULL) {
		return 0.0;
	}
	return mFrequencyModifier->sampleValue();
}

float Oscillator :: getAmplitudeModifier() {
	if (mEnvelope == NULL) {
		return 1.0;
	}
	return mEnvelope->getAmplitudeModifier();
}


float Oscillator :: inputValue() {
	return mInput->sampleValue();
}

bool Oscillator :: inputIsPlaying() {
	return mInput->isPlaying();
}



