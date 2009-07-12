#ifndef	__ForwardParameterCallback_h__
#define	__ForwardParameterCallback_h__

#include "ParameterCallback.h"
#include <string>

template <class RECEIVER>
class ForwardParameterCallback : public ParameterCallback {
public:
	ForwardParameterCallback(RECEIVER *receiver, void (RECEIVER::*floatCallback)(float), void (RECEIVER::*stringCallback)(const std::string&));
	void floatValueChanged(const float newFloat) const;
	void stringValueChanged(const std::string& newValue) const;
private:
	RECEIVER *mReceiver;
	void (RECEIVER::*mFloatCallback)(float);
	void (RECEIVER::*mStringCallback)(const std::string&);
};

template <class RECEIVER>
ForwardParameterCallback<RECEIVER> :: ForwardParameterCallback(RECEIVER *receiver, 
																															void (RECEIVER::*floatCallback)(float), 
																															void (RECEIVER::*stringCallback)(const std::string&)) :
mReceiver(receiver), mFloatCallback(floatCallback), mStringCallback(stringCallback) {
}

template <class RECEIVER>
void ForwardParameterCallback<RECEIVER> :: floatValueChanged(const float newFloat) const {
	if (mFloatCallback != NULL) {
		(mReceiver->*mFloatCallback)(newFloat);
	}
}

template <class RECEIVER>
void ForwardParameterCallback<RECEIVER> :: stringValueChanged(const std::string& newValue) const {
	if (mStringCallback != NULL) {
		(this->mReceiver->*mStringCallback)(newValue);
	}
}

#endif

