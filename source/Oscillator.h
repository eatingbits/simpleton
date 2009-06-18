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
	Oscillator(Oscillator& oscillator)  : previous(oscillator) {}
	virtual ~Oscillator() {}
	
	virtual void reset() {};
//	virtual void generateFrames(Buffer& buffer, int channels, int framesToGenerate, float samplesPerPeriod) = 0;
	
	float sampleValue(float samplesPerPeriod) {
		float previous = previousValue(samplesPerPeriod);
		float nValue = previous + nextSampleValue(samplesPerPeriod);
		return nValue;
	}
	
	virtual float nextSampleValue(float samplesPerPeriod) = 0;
protected:
	virtual float previousValue(float samplesPerPeriod) {
		return previous.sampleValue(samplesPerPeriod);
	}
private:
	Oscillator& previous;
};

#endif