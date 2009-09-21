#include "SineWave.h"
#include <cmath>

/* for sine samplesPerPeriod needs to be samplesPerPeriod + freqMod */
float SineWave :: sampleValue(float samplesPerPeriod, int currentPeriod) {	
	float value = sin(currentPeriod / (samplesPerPeriod) * 2 * M_PI);
	return value;
}

