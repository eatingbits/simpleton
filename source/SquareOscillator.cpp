/*
 *  SquareOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "SquareOscillator.h"
#include "Buffer.h"

SquareOscillator::SquareOscillator(Oscillator& previous) : Oscillator(previous), mCurrentPeriod(0) {
}

float SquareOscillator :: nextSampleValue(float samplesPerPeriod) {
	int half = ((int) samplesPerPeriod / 2);
	mCurrentPeriod = (mCurrentPeriod + 1) % (int) samplesPerPeriod;
	if (mCurrentPeriod > half) {
		return -1.0;
	}
	return 1.0;
}

