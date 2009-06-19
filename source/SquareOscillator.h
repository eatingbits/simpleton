/*
 *  SquareOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __SquareOscillator__H
#define __SquareOscillator__H

#ifndef __Oscillator__H
#include "Oscillator.h"
#endif

class Buffer;

class SquareOscillator : public Oscillator {
public:
	SquareOscillator(Oscillator& previous, float samplesPerPeriod);
	virtual void noteOn() { mCurrentPeriod = 0; ++mPlaying; }
	virtual void noteOff() { if (mPlaying > 0) { --mPlaying; } }
	bool isPlaying() { return mPlaying > 0; }
	float nextSampleValue();
private:	
	float sampleValue(int currentPeriod, int half);
	int mCurrentPeriod;
	float mSamplesPerPeriod;
	int mPlaying;
};

#endif