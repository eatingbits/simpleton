/*
 *  SilenceOscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "Oscillator.h"

class SilenceOscillator : public Oscillator {
public:
	SilenceOscillator();
	virtual void reset() { mCurrentPeriod = 0; }
	void generateFrames(Buffer& buffer, int channels, int framesToGenerate, float samplesPerPeriod);
	void setSamplesPerPeriodModifier(float value) {}
private:
	float generateTune(int currentPeriod, float samplesPerPeriod);
	int mCurrentPeriod;
};
