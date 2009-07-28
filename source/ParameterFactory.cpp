#include "ParameterFactory.h"
#include "Parameters.h"
#include "OscillatorParameters.h"

Parameters *ParameterFactory :: createParameters(OscillatorChangeCallback *oscillatorCallback) {
	Parameters *parameters = new Parameters();
  
	parameters->add(new OscillatorParameters(0, oscillatorCallback));
	parameters->add(new OscillatorParameters(1, oscillatorCallback));
	parameters->add(new OscillatorParameters(2, oscillatorCallback));
	
	return parameters;
}