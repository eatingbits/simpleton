/*
 *  SawOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SAW_OSCILLATOR_H__
#define __SAW_OSCILLATOR_H__

#include "Oscillator.h"

class SawOscillator : public Oscillator {
public:
	SawOscillator(Oscillator *parent, float samplesPerPeriod, bool reverse);
	~SawOscillator() {}
	virtual void noteOn() { mCurrentPeriod = 0; mPlaying++; }
	virtual void noteOff() { if (mPlaying > 0) { --mPlaying; } }
	
	bool isPlaying() { return (mPlaying > 0 || isInputPlaying()); }
	float nextSampleValue();
private:
	int mCurrentPeriod;
	float mSamplesPerPeriod;
	int mPlaying;	
	bool mReverse;
};

#endif
