#ifndef __Source_h__
#define __Source_h__

class Source {
public:
	virtual ~Source() {}
	virtual float sampleValue() = 0;
	virtual bool isPlaying() = 0;
	virtual void noteOn() = 0;
	virtual void noteOff() = 0;
	virtual bool isNoteOn() = 0; /* Doesn't quite fit here though */
};

#endif

