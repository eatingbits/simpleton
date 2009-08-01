#include "Decibel.h"
#include <cmath>

Decibel :: Decibel(float value) : mValue(value) {
}

float Decibel :: toLinear() {
	float linear = pow(10, (mValue / 20.0));
	return linear;
}
