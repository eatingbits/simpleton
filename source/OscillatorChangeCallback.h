#ifndef __OscillatorChangeCallback_h__
#define __OscillatorChangeCallback_h__

class Prototype;

class OscillatorChangeCallback {
public:
	virtual ~OscillatorChangeCallback() {}
	virtual void oscillatorChanged(int index, Prototype *prototype) = 0;
};

#endif

