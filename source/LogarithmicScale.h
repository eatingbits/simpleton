#ifndef __LogarithmicScale_h__
#define __LogarithmicScale_h__

#include <cmath>

template <typename T>
class LogarithmicScale : public Scaler<T> {
public:
	virtual T scale(float value, T min, T max) {  /* 0.1 , 50, 20000 */
		float lmin = log10((float) min); 
		float lmax = log10((float) max); 
		float lvalue = value * (lmax - lmin) + lmin; 
		return pow(10, lvalue); 
	}
};

#endif

