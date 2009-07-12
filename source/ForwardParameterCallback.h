#ifndef	__ForwardParameterCallback_h__
#define	__ForwardParameterCallback_h__

#include "ParameterCallback.h"
#include <string>

template <class RECEIVER>
class ForwardParameterCallback : public ParameterCallback {
public:
	ForwardParameterCallback(RECEIVER *receiver, void (RECEIVER::*floatCallback)(float), 
													 void (RECEIVER::*stringCallback)(const std::string&),
													 void (RECEIVER::*integerCallback)(const int)
	);
	void floatValueChanged(const float newFloat) const;
	void stringValueChanged(const std::string& newValue) const;
	void integerValueChanged(const int newValue) const;
private:
	RECEIVER *mReceiver;
	void (RECEIVER::*mFloatCallback)(const float);
	void (RECEIVER::*mStringCallback)(const std::string&);
	void (RECEIVER::*mIntegerCallback)(const int);
};

template <class RECEIVER>
ForwardParameterCallback<RECEIVER> :: ForwardParameterCallback(RECEIVER *receiver, 
																															void (RECEIVER::*floatCallback)(float), 
																															void (RECEIVER::*stringCallback)(const std::string&),
																															void (RECEIVER::*integerCallback)(const int)) :
mReceiver(receiver), mFloatCallback(floatCallback), mStringCallback(stringCallback), mIntegerCallback(integerCallback) {
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

template <class RECEIVER>
void ForwardParameterCallback<RECEIVER> :: integerValueChanged(const int newValue) const {
	if (mIntegerCallback != NULL) {
		(this->mReceiver->*mIntegerCallback)(newValue);
	}
}

template <class RECEIVER>
class IntForwardParameterCallback : public ForwardParameterCallback<RECEIVER> {
public:
	IntForwardParameterCallback(RECEIVER *receiver, void (RECEIVER::*integerCallback)(const int));
};

template <class RECEIVER>
IntForwardParameterCallback<RECEIVER> :: IntForwardParameterCallback(RECEIVER *receiver, void (RECEIVER::*integerCallback)(const int)) :
ForwardParameterCallback<RECEIVER>(receiver, NULL, NULL, integerCallback) {
}

template <class RECEIVER>
class FloatForwardParameterCallback : public ForwardParameterCallback<RECEIVER> {
public:
	FloatForwardParameterCallback(RECEIVER *receiver, void (RECEIVER::*floatCallback)(const float));
};

template <class RECEIVER>
FloatForwardParameterCallback<RECEIVER> :: FloatForwardParameterCallback(RECEIVER *receiver, void (RECEIVER::*floatCallback)(const float)) :
ForwardParameterCallback<RECEIVER>(receiver, floatCallback, NULL, NULL) {
}

template <class RECEIVER>
class StringForwardParameterCallback : public ForwardParameterCallback<RECEIVER> {
public:
	StringForwardParameterCallback(RECEIVER *receiver, void (RECEIVER::*callback)(const std::string&));
};

template <class RECEIVER>
StringForwardParameterCallback<RECEIVER> :: StringForwardParameterCallback(RECEIVER *receiver, void (RECEIVER::*callback)(const std::string&)) :
ForwardParameterCallback<RECEIVER>(receiver, NULL, callback, NULL) {
}

#endif

