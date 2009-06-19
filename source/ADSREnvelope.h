/*
 *  ADSREnvelope.h
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ADSR_ENVELOPE_H__
#define __ADSR_ENVELOPE_H__

#include "Envelope.h"

class ADSREnvelope : public Envelope {
public:
	enum AdsrState {
		kAttack,
		kDecay,
		kSustain,
		kRelease,
		kQuiet
	};
	
	ADSREnvelope(int sampleRate) : mAttackAmplitude(1.0), mAttackTime(0), mDecayAmplitude(0.0), mDecayTime(0), mReleaseTime(0), 
		mSampleRate(sampleRate), mCurrentState(kQuiet), mCurrentSample(0), mCurrentAmplitude(0.0) {}
	
	void setAttack(float attackAmplitude, int attackTime) { mAttackAmplitude = attackAmplitude; mAttackTime = msToSamples(attackTime); }
	void setDecay(float decayAmplitude, int decayTime) { mDecayAmplitude = decayAmplitude; mDecayTime = msToSamples(decayTime); }
	void setRelease(int releaseTime) { mReleaseTime = msToSamples(releaseTime); }
	
	float getAmplitudeModifier();
	bool isPlaying();
	void noteOn();
	void noteOff();
	
private:
	int msToSamples(int ms);
	void setState(AdsrState newState) { mCurrentState = newState; mCurrentSample = 0; }
	float getAttackAmplitudeModifier();
	float getDecayAmplitudeModifier();
	float getReleaseAmplitudeModifier();
	
	float mAttackAmplitude;
	int mAttackTime;
	float mDecayAmplitude;
	int mDecayTime;
	int mReleaseTime;
	int mSampleRate;
	AdsrState mCurrentState;
	int mCurrentSample;
	float mCurrentAmplitude;
	
	// 1 / (44100 * 1000);
};

#endif

