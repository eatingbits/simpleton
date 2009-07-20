#include "Joiner.h"

using std::vector;

void Joiner :: addSource(Source *source) {
	mSources.push_back(source);
}

float Joiner :: sampleValue() {
	float total = 0.0;
	vector<Source *>::const_iterator it = mSources.begin();
	while (it != mSources.end()) {
		total += (*it)->sampleValue();
		++it;
	}
	return total;
}

bool Joiner :: isPlaying() {
	vector<Source *>::const_iterator it = mSources.begin();
	while (it != mSources.end()) {
		if ((*it)->isPlaying()) {
			return true;
		}
		++it;
	}
	return false;
}

bool Joiner :: isNoteOn() {
	vector<Source *>::const_iterator it = mSources.begin();
	while (it != mSources.end()) {
		if ((*it)->isNoteOn()) {
			return true;
		}
		++it;
	}
	return false;
}

void Joiner :: noteOn() {
	vector<Source *>::const_iterator it = mSources.begin();
	while (it != mSources.end()) {
		(*it)->noteOn();
		++it;
	}
}

void Joiner :: noteOff() {
	vector<Source *>::const_iterator it = mSources.begin();
	while (it != mSources.end()) {
		(*it)->noteOff();
		++it;
	}
}