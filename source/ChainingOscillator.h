#ifndef __ChainingOscillator_h__
#define __ChainingOscillator_h__

#include "Source.h"
#include <vector.h>

class ChainingOscillator : public Source {
public:
	ChainingOscillator();
	~ChainingOscillator();
	
	virtual float sampleValue();
	virtual bool isPlaying();
	virtual void noteOn();
	virtual void noteOff();
	virtual bool isNoteOn();
	
	void addOscillator(Source *oscillator);
	
private:
	std::vector<Source *> mOscillators;
	bool mIsNoteOn;
};

#endif

