#include "Splitter.h"

Splitter :: Splitter(int targets, Source& source) : mTargets(targets), mSource(source), mCount(0), mSampleValue(0.0), mIsPlaying(true), mIsNoteOn(true) {
}

float Splitter :: sampleValue() {
	if (next()) {
		mSampleValue = mSource.sampleValue();
	}
	return mSampleValue;
}
		
bool Splitter :: isPlaying() {
	if (next()) {
		mIsPlaying = mSource.isPlaying();
	}
	return mIsPlaying;
}

bool Splitter :: isNoteOn() {
	if (next()) {
		mIsNoteOn = mSource.isNoteOn();
	}
	return mIsNoteOn;
}

void Splitter :: noteOn() {
	if (next()) {
		mSource.noteOn();
	}
}

void Splitter :: noteOff() {
	if (next()) {
		mSource.noteOff();
	}
}

bool Splitter :: next() {
	if (mCount % mTargets == 0) {
		mCount = 1;
		return true;
	}
	++mCount;
	return false;
}