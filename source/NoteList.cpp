/*
 *  NoteList.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "NoteList.h"
#include "Oscillator.h"
#include <cstdlib>
#include <iostream>

void NoteList :: add(int value, Oscillator *oscillator) {
	mElements[mSize] = value;
	mOscillators[mSize++] = oscillator;
}

/* Removes the first occurance of the tone we want to remove */
void NoteList :: remove(int value) { 
	bool found = false;
	for (int i = 0; i < mSize; ++i) {
		if (mElements[i] == value) {
			found = true;
			delete mOscillators[i];
		}
		if (found && i < mSize - 1) {
			mElements[i] = mElements[i+1];
			mOscillators[i] = mOscillators[i+1];
		}
	}
	if (found) {
		--mSize;
	}
}

Oscillator *NoteList :: getOscillator(int note) {
	for (int i = 0; i < mSize; i++) {
		if (mElements[i] == note) {
			return mOscillators[i];
		}
	}
	return NULL;
}

float NoteList :: sampleValue() {
	float value = 0.0;
	
	if (isPlaying()) {
		for (int i = mSize - 1; i >= 0; --i) {
			if (!mOscillators[i]->isPlaying()) {
				remove(mElements[i]);
			}
		}
		
		for (int i = 0; i < mSize; ++i) {
			value = mOscillators[i]->sampleValue();
		}
	}
	if (value < -1.0 || value > 1.0) {
		std::cout << "Value:" << value << std::endl;
	}
	return value;
}

