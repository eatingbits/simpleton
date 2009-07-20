#ifndef __Joiner_h__
#define __Joiner_h__

#include <vector>
#include "Source.h"

class Joiner : public Source {
public:
	void addSource(Source *source);
	float sampleValue();
	bool isPlaying();
	bool isNoteOn();
	void noteOn();
	void noteOff();
private:
	std::vector<Source *> mSources;
};

#endif
