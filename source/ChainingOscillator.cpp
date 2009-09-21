#include "ChainingOscillator.h"
#include "Source.h"

using std::vector;

ChainingOscillator :: ChainingOscillator() : mIsNoteOn(false) {
}

ChainingOscillator :: ~ChainingOscillator() {
	vector<Source *>::iterator it = mOscillators.begin(), end = mOscillators.end();  
	for (; it != end; ++it) {
		delete (*it);
	}
	mOscillators.clear();
}

void ChainingOscillator :: addOscillator(Source *oscillator) {
	mOscillators.push_back(oscillator);
}

float ChainingOscillator :: sampleValue() {
	float result = 0.0f;
	vector<Source *>::iterator it = mOscillators.begin(), end = mOscillators.end();  
	for (; it != end; ++it) {
		result += (*it)->sampleValue();
	}
	return result;
}

bool ChainingOscillator :: isPlaying() {
	vector<Source *>::iterator it = mOscillators.begin(), end = mOscillators.end();  
	for (; it != end; ++it) {
		if ((*it)->isPlaying()) {
			return true;
		}
	}	
	return false;
}

void ChainingOscillator :: noteOn() {
	mIsNoteOn = true;
	vector<Source *>::iterator it = mOscillators.begin(), end = mOscillators.end();  
	for (; it != end; ++it) {
		(*it)->noteOn();
	}
}

void ChainingOscillator :: noteOff() {
	mIsNoteOn = false;
	vector<Source *>::iterator it = mOscillators.begin(), end = mOscillators.end();  
	for (; it != end; ++it) {
		(*it)->noteOff();
	}
}

bool ChainingOscillator :: isNoteOn() {
	return mIsNoteOn;
}


