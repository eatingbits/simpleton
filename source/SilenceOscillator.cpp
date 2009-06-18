/*
 *  SilenceOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "SilenceOscillator.h"
#include "Buffer.h"

SilenceOscillator :: SilenceOscillator() : 
Oscillator() {
}

void SilenceOscillator :: generateFrames(Buffer& buffer, int channels, int framesToGenerate, float samplesPerPeriod) {
	buffer.zero();
}



