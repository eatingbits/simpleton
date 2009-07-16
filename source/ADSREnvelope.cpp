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
	if (mCurrentSample > mAttackTime) {
		mCurrentAmplitude = mAttackAmplitude;
		setState(kDecay);
	}
	return mCurrentAmplitude;
}

/* In mDecayTime frames we are to move from mAttackAmplitude to mAttackAmplitude + mDecayAmplitude 
 (mDecayAmplitude is supposed to be delta). 
 The current amplitude is calculated as the percentage of the decay time passed 
 multiplied by the mDecayAmplitude to get the current amount to decrease with
 The final value is mAttackAmplitude - the amount to decrease with */
float ADSREnvelope :: getDecayAmplitudeModifier() {
	mCurrentSample++;
	/* Make sure we never divide by zero */
	float percent = (float) mCurrentSample / ((float) (mDecayTime > 1 ? mDecayTime : 1)) ;
	mCurrentAmplitude = mAttackAmplitude + ((mDecayAmplitude) * percent);
	
	if (mCurrentSample > mDecayTime) {
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
	return (ms * (mSampleRate / 1000));
}
