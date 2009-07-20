
#ifndef __Chorus_h__
#define __Chorus_h__

#include <queue>
#include "Source.h"

class Chorus : public Source {
public:
	Chorus(int delayMs, Source& source);
	float sampleValue();
	bool isPlaying();
	bool isNoteOn();
	void noteOn();
	void noteOff();
private:
	int msToSamples(int ms);
	int mDelay;
	Source& mSource;
	std::queue<float> mBuffer;
};

#endif