#ifndef __NoiseWave_h__
#define __NoiseWave_h__

#include "WaveForm.h"

class NoiseWave : public WaveForm {
public:
	float sampleValue(float samplesPerPeriod, int currentSample);
	std::string name() { return "Noise"; }		
};

#endif

