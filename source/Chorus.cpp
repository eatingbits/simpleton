#include "Chorus.h"

Chorus :: Chorus(int delayMs, Source& source) : mDelay(msToSamples(delayMs)), mSource(source) {
	for (int i = 0; i < mDelay; i++) {
		mBuffer.push(0.0);
	}
}

float Chorus :: sampleValue() {
	if (mSource.isPlaying()) {
		mBuffer.push(mSource.sampleValue());
	}
	if (mBuffer.size() == 0) {
		return 0.0;
	}
	float bufferedValue = mBuffer.front();
	mBuffer.pop();
	return bufferedValue;
}

bool Chorus :: isPlaying() {
	if (mSource.isPlaying() || mBuffer.size() > 0) {
		return true;
	}
	return false;
}

bool Chorus :: isNoteOn() {
	return mSource.isNoteOn();
}

void Chorus :: noteOn() {
	mSource.noteOn();
}

void Chorus :: noteOff() {
	mSource.noteOff();
}

/* Move away to a common place */
int Chorus :: msToSamples(int ms) {
	return (ms * (44100 / 1000));
}