#include "SquareWave.h"

float SquareWave :: sampleValue(float samplesPerPeriod, int currentPeriod) {	
	int half = samplesPerPeriod / 2;
	if (currentPeriod < half) {
		return 1;
	}
	return -1;
}