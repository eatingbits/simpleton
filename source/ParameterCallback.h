#ifndef __ParameterCallback_h__
#define __ParameterCallback_h__

#include <string>

class ParameterCallback {
public:
	virtual ~ParameterCallback() {}
	virtual void floatValueChanged(const float newFloat) const = 0;
	virtual void stringValueChanged(const std::string& newValue) const = 0;
	virtual void integerValueChanged(const int newValue) const = 0;
};

#endif

