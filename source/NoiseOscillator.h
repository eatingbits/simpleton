#ifndef __NOISE_OSCILLATOR_H__
#define __NOISE_OSCILLATOR_H__

#include "Oscillator.h"

class NoiseOscillator : public Oscillator {
public:
	NoiseOscillator(Oscillator *parent) : Oscillator(parent) {}
	float nextSampleValue();
private:
};

#endif

