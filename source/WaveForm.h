#ifndef __WaveForm_h__
#define __WaveForm_h__

#include <string>

class WaveForm {
public:
	virtual ~WaveForm() {}
	virtual float sampleValue(float samplesPerPeriod, int currentPeriod) = 0;
	virtual std::string name() = 0;
};

#endif

