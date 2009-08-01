#ifndef __Decibel_h__
#define __Decibel_h__

class Decibel {
public:
	Decibel(float value);
	float toLinear();
private:
	float mValue;
};

#endif

