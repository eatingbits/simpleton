#ifndef __Scaler_h__
#define __Scaler_h__

template <typename T>
class Scaler {
public:
	virtual ~Scaler() {}
	virtual T scale(float value, T min, T max) = 0;
};

#endif

