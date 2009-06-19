/*
 *  ADSREnvelope.cpp
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ADSREnvelope.h"

float ADSREnvelope :: getAmplitudeModifier() {
	if (mCurrentState == kAttack) {
		return getAttackAmplitudeModifier();
	} else if (mCurrentState == kDecay) {
		return getDecayAmplitudeModifier();
	} else if (mCurrentState == kSustain) {
		return mCurrentAmplitude;
	} else if (mCurrentState == kRelease) {
		return getReleaseAmplitudeModifier();
	}
	return 0.0;
}

float ADSREnvelope :: getAttackAmplitudeModifier() {
	mCurrentSample++;
	float deltaPerSample = mAttackAmplitude / (mAttackTime > 1 ? mAttackTime : 1);
	mCurrentAmplitude += deltaPerSample;
	if (++mCurrentSample > mAttackTime) {
		mCurrentAmplitude = mAttackAmplitude;
		setState(kDecay);
	}
	return mCurrentAmplitude;
}

float ADSREnvelope :: getDecayAmplitudeModifier() {
	mCurrentSample++;
	float deltaPerSample = mDecayAmplitude / (mDecayTime > 1 ? mDecayTime : 1);
	mCurrentAmplitude += deltaPerSample;
	if (++mCurrentSample > mDecayTime) {
		mCurrentAmplitude = mAttackAmplitude + mDecayAmplitude;
		setState(kSustain);
	}
	return mCurrentAmplitude;
}

float ADSREnvelope :: getReleaseAmplitudeModifier() {
	mCurrentSample++;
	float delta = -mCurrentAmplitude;
	int remainingSamples = (mReleaseTime - mCurrentSample);
	if (remainingSamples == 0) {
		mCurrentAmplitude = 0.0;
		mCurrentState = kQuiet;
	} else {
		float perSample = (delta / remainingSamples);
		mCurrentAmplitude += perSample;
	}
	return mCurrentAmplitude;
}

bool ADSREnvelope :: isPlaying() {
	return mCurrentState != kQuiet;
}

void ADSREnvelope :: noteOn() {
	mCurrentAmplitude = 0;
	setState(kAttack);
}

void ADSREnvelope :: noteOff() {
	if (mReleaseTime > 0 && mCurrentAmplitude != 0.0) {
		setState(kRelease);
	} else {
		setState(kQuiet);
	}
}

int ADSREnvelope :: msToSamples(int ms) {
	return (ms * (44100 / 1000));
//	return (ms / (mSampleRate * 1000));
}
