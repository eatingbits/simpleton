#ifndef __OSCILLATOR_INPUT_H__
#define __OSCILLATOR_INPUT_H__

class OscillatorInput {
public:
	virtual ~OscillatorInput() {}
	virtual float sampleValue() = 0;
};

class StaticOscillatorInput : public OscillatorInput {
public:
	StaticOscillatorInput(float value) : mValue(value) {}
	virtual float sampleValue() { return mValue; }
private:
	float mValue;
};

#endif

	

