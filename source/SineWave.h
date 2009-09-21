#ifndef __SineWave_h__
#define __SineWave_h__

#include "WaveForm.h"

class SineWave : public WaveForm {
public:
	float sampleValue(float samplesPerPeriod, int currentSample);
	std::string name() { return "Sine"; }
};

#endif

