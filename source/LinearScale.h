#ifndef __LinearScale_h__
#define __LinearScale_h__

#include "Scaler.h"

template <typename T>
class LinearScale : public Scaler<T> {
public:
	virtual T scale(float value, T min, T max) { return value * (max - min) + min; }
};

#endif

