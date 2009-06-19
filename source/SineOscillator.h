/*
 *  SineOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SineOscillator__H
#define __SineOscillator__H

#ifndef __Oscillator__H
#include "Oscillator.h"
#endif

#include <iostream>

class Buffer;

class SineOscillator : public Oscillator {
public:
  SineOscillator(Oscillator& previous, float samplesPerPeriod);
  ~SineOscillator();
	virtual void noteOn() { std::cout << "s:on()" << std::endl; mCurrentPeriod = 0; mPlaying++; }
	virtual void noteOff() { std::cout << "s:off() playing:" << mPlaying << std::endl; if (mPlaying > 0) { std::cout<<"--playing" << std::endl; --mPlaying; } }

	bool isPlaying() { return (mPlaying > 0 || isInputPlaying()); }
	float nextSampleValue();
private:
	int mCurrentPeriod;
	float mSamplesPerPeriod;
	int mPlaying;
};

#endif