#ifndef __LowPass_h__
#define __LowPass_h__

#include "Source.h"

class LowPass : public Source {
public:
	LowPass(Source& source) : mLastValue(0.0), mB(0.04), mSource(source) {}
	float sampleValue();
	bool isPlaying();
	bool isNoteOn();
	void noteOn();
	void noteOff();
	
private:
	float mLastValue;
	float mB;
	Source& mSource;
};

#endif

