#ifndef __OscillatorChangeCallback_h__
#define __OscillatorChangeCallback_h__

class OscillatorPrototype;

class OscillatorChangeCallback {
public:
	virtual ~OscillatorChangeCallback() {}
	virtual void oscillatorChanged(int index, OscillatorPrototype *prototype) = 0;
};

#endif

