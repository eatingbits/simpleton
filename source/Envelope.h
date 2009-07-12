#ifndef __ENVELOPE_H__
#define __ENVELOPE_H__

class Envelope {
public:
	virtual ~Envelope() {}
	virtual float getAmplitudeModifier() = 0;
	virtual bool isPlaying() = 0; 
	virtual void noteOn() = 0;
	virtual void noteOff() = 0;
};

#endif

