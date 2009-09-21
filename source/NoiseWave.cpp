#include "NoiseWave.h"
#include <cmath>

float NoiseWave :: sampleValue(float samplesPerPeriod, int currentSample) {
	long value = random();
	return ((float) (1000 - (value % 2000))) / 1000.0;
}