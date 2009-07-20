#ifndef __ChorusFactory_h__
#define __ChorusFactory_h__

class Source;

class ChorusFactory {
public:
	Source *create(int nrOfVoices, int delay, Source& source);
};

#endif

