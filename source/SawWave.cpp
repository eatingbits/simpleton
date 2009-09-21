#include "SawWave.h"

float SawWave :: sampleValue(float samplesPerPeriod, int currentPeriod) {	
	float halfSamplesPerPeriod = samplesPerPeriod / 2;
	float divider = (1.0 / (float) halfSamplesPerPeriod);
	
	float value = 0.0;								 
									 
	if (currentPeriod < halfSamplesPerPeriod) {
		 value = -1 + ((float) currentPeriod * divider);
	} else {
		value = 0 + ((float) (currentPeriod - halfSamplesPerPeriod) * divider);
	}
	return value;
}



