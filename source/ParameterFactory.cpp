#include "ParameterFactory.h"
#include "Parameters.h"
#include "OscillatorParameters.h"
#include "GeneralComponent.h"

Parameters *ParameterFactory :: createParameters(OscillatorChangeCallback *oscillatorCallback, GeneralChangedCallback *generalCallback) {
	Parameters *parameters = new Parameters();
  
	parameters->add(new GeneralComponent(generalCallback));
	parameters->add(new OscillatorParameters(0, oscillatorCallback, 1.0, 1.0));
	parameters->add(new OscillatorParameters(1, oscillatorCallback, 0.0, 0.0));
	parameters->add(new OscillatorParameters(2, oscillatorCallback, 0.0, 0.0));
	
	return parameters;
}