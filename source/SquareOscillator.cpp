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

SquareOscillator::SquareOscillator() : mSamplesPerPeriodModifier(0.0) {
}


void SquareOscillator :: generateFrames(Buffer& buffer, int channels, int framesToGenerate, float samplesPerPeriod) {
	int half = (samplesPerPeriod + mSamplesPerPeriodModifier) / 2;
	for (int frame = 0; frame < framesToGenerate; ++frame) {
		mCurrentPeriod = (mCurrentPeriod + 1) % (int) (samplesPerPeriod + mSamplesPerPeriodModifier);
		for (int channel = 0; channel < channels; ++channel) {
			if (mCurrentPeriod > half) {
				buffer.setValue(channel, frame, -1.0);
			} else {
				buffer.setValue(channel, frame, 1.0);
			}
		}
	}
}
