/*
 *  oscillator.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 4/18/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#ifndef __Oscillator__H
#define __Oscillator__H

class Buffer;

class Oscillator {
public:
	Oscillator() {}
	virtual ~Oscillator() {}
	
	virtual void setSamplesPerPeriodModifier(float value) = 0;
	virtual void reset() = 0;
	virtual void generateFrames(Buffer& buffer, int channels, int framesToGenerate, float samplesPerPeriod) = 0;
private:
};

#endif