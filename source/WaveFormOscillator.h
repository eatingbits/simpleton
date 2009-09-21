#ifndef __WaveFormOscillator_h__
#define __WaveFormOscillator_h__

#include "Source.h"

class WaveForm;
class Envelope;

class WaveFormOscillator : public Source {
public:
	WaveFormOscillator(WaveForm *waveForm, Envelope *envelope, float samplesPerPeriod, float volume);

	virtual float sampleValue();
	virtual bool isPlaying();
	virtual void noteOn();
	virtual void noteOff();
	virtual bool isNoteOn(); // move this

private:
	int calculateNextSamplePeriod(float frequencyModifier);
	float modifiedSampleValue(float sampleValue);
	
	WaveForm *mWaveForm;
	Envelope *mEnvelope;
	float mSamplesPerPeriod;
	int mCurrentSample;
	float mVolume;
	bool mIsNoteOn;
};

#endif

