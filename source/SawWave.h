#ifndef __SawWave_h__
#define __SawWave_h__

#include "WaveForm.h"

class SawWave : public WaveForm {
public:
	float sampleValue(float samplesPerPeriod, int currentSample);
	std::string name() { return "Saw"; }	
};

#endif

