
#ifndef __Splitter_h__
#define __Splitter_h__

#include "Source.h"

class Splitter : public Source {
public:
	Splitter(int targets, Source& source);
	float sampleValue();
	bool isPlaying();
	bool isNoteOn();
	void noteOn();
	void noteOff();
private:
	bool next();
	int mTargets;
	Source& mSource;
	int mCount;
	float mSampleValue;
	bool mIsPlaying;
	bool mIsNoteOn;
};

#endif
