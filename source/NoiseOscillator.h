/*
 *  NoiseOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __NOISE_OSCILLATOR_H__
#define __NOISE_OSCILLATOR_H__

#include "Oscillator.h"

class NoiseOscillator : public Oscillator {
public:
	NoiseOscillator(Oscillator *parent) : Oscillator(parent) {}
	virtual void noteOn() { mPlaying++; }
	virtual void noteOff() { if (mPlaying > 0) { --mPlaying; } }
	
	bool isPlaying() { return (mPlaying > 0 || isInputPlaying()); }
	float nextSampleValue();
private:
	int mPlaying;	
};

#endif

