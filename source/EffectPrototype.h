#ifndef __EffectPrototype_h__
#define __EffectPrototype_h__

class Source;

class EffectPrototype {
public:
	virtual ~EffectPrototype() {}
	virtual Source *create(Source *source) = 0;
private:
};

#endif

