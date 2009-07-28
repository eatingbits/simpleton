#ifndef __ParameterFactory_h__
#define __ParameterFactory_h__

class Parameters;
class OscillatorChangeCallback;

class ParameterFactory {
public:
	Parameters *createParameters(OscillatorChangeCallback *oscillatorCallback);
};

#endif

