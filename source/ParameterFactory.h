#ifndef __ParameterFactory_h__
#define __ParameterFactory_h__

class Parameters;
class OscillatorChangeCallback;
class GeneralChangedCallback;
class EffectChangedCallback;

class ParameterFactory {
public:
	Parameters *createParameters(OscillatorChangeCallback *oscillatorCallback, GeneralChangedCallback *generalCallback, EffectChangedCallback *effectChanged);
};

#endif

