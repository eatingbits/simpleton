#include "WaveFormOscillator.h"
#include "WaveForm.h"
#include "Envelope.h"

WaveFormOscillator :: WaveFormOscillator(WaveForm *waveForm, Envelope *envelope, float samplesPerPeriod, float volume) 
: mWaveForm(waveForm), mEnvelope(envelope), mSamplesPerPeriod(samplesPerPeriod), mCurrentSample(0), mVolume(volume), mIsNoteOn(false) {
}

float WaveFormOscillator :: sampleValue() {
	mCurrentSample = calculateNextSamplePeriod(0.0f);
	float sampleValue = mWaveForm->sampleValue(mSamplesPerPeriod, mCurrentSample);
	return modifiedSampleValue(sampleValue);
}

float WaveFormOscillator :: modifiedSampleValue(float sampleValue) {
	return mVolume * (mEnvelope->getAmplitudeModifier() * sampleValue);
}

void WaveFormOscillator :: noteOn() {
	mIsNoteOn = true;
	mEnvelope->noteOn();
}

void WaveFormOscillator :: noteOff() {
	mIsNoteOn = false;
	mEnvelope->noteOff();
}

bool WaveFormOscillator :: isNoteOn() {
	return mIsNoteOn;
}

bool WaveFormOscillator :: isPlaying() {
	return mEnvelope->isPlaying();
}

int WaveFormOscillator :: calculateNextSamplePeriod(float frequencyModifier) {
	return (mCurrentSample + 1) % (int) (mSamplesPerPeriod + frequencyModifier);
}

