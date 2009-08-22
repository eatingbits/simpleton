#include "LowPass.h"

float LowPass :: sampleValue() {
	float sample = mSource.sampleValue();
	float result = sample * mB + mLastValue * (1.0 - mB);
	mLastValue = sample;
	return result;
}

bool LowPass :: isPlaying() {
	return mSource.isPlaying();
}

bool LowPass :: isNoteOn() {
	return mSource.isNoteOn();
}

void LowPass :: noteOn() {
	mSource.noteOn();
}

void LowPass :: noteOff() {
	mSource.noteOff();
}