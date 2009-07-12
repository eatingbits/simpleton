#include "NoiseOscillator.h"
#include <cstdlib>

float NoiseOscillator :: nextSampleValue() {
	float amplitudeModifier = getAmplitudeModifier();
	long value = random();
	float ret = ((float) (1000 - (value % 2000))) / 1000.0;
	return amplitudeModifier * ret;
}
