#ifndef __SquareWave_h__
#define __SquareWave_h__

#include "WaveForm.h"

class SquareWave : public WaveForm {
public:
	float sampleValue(float samplesPerPeriod, int currentSample);
	std::string name() { return "Square"; }	
};

#endif

