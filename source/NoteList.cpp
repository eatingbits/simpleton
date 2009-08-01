#include "NoteList.h"
#include "Oscillator.h"
#include <cstdlib>

void NoteList :: add(int value, Source *source) {
	mElements[mSize] = value;
	mOscillators[mSize++] = source;
}

/* Removes the first occurance of the tone we want to remove */
void NoteList :: remove(int value) { 
	bool found = false;
	for (int i = 0; i < mSize; ++i) {
		if (found == false && mElements[i] == value) {
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

Source *NoteList :: getSource(int note) {
	for (int i = 0; i < mSize; i++) {
		if (mElements[i] == note && mOscillators[i]->isNoteOn()) {
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
			if (mPolyphony) {
				value += mOscillators[i]->sampleValue();
			} else {
				value = mOscillators[i]->sampleValue();
			}
		}
	}
	return value;
}

