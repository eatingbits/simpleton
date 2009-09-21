#ifndef __OscillatorPrototype_h__
#define __OscillatorPrototype_h__

class Source;

enum OscillatorType {
	kSineOscillator,
	kSquareOscillator,
	kSawOscillator,
	kNoiseOscillator
};

class OscillatorPrototype {
public:
	virtual ~OscillatorPrototype() {}
	virtual Source *create(int samplesPerSecond) = 0;
};

#endif
