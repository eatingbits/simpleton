#ifndef __GeneralChangedCallback_h__
#define __GeneralChangedCallback_h__

class GeneralChangedCallback {
public:
	virtual ~GeneralChangedCallback() {}
	virtual void onChange(bool polyphony) = 0;
};

#endif