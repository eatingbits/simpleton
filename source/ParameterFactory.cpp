#include "ParameterFactory.h"
#include "Parameters.h"
#include "Parameter.h"
#include "FloatValueParameter.h"
#include "NamedValueParameter.h"

Parameters *ParameterFactory :: createParameters() {
	Parameters *parameters = new Parameters();
  
  NamedValueParameter *nv1 = new NamedValueParameter("Oscillator", "");
  nv1->add("Sine");
  nv1->add("Square");
  nv1->add("Saw");
	parameters->add(nv1);
	FloatValueParameter *attack = new FloatValueParameter("Attack", "", 0.0, 2.0);
	parameters->add(attack);
	FloatValueParameter *attackTime = new FloatValueParameter("Attack time", "ms", 0.0, 400.0);
	parameters->add(attackTime);
	FloatValueParameter *decay = new FloatValueParameter("Decay", "", 0.0, 2.0);
	parameters->add(decay);
	FloatValueParameter *decayTime = new FloatValueParameter("Decay time", "ms", 0.0, 400.0);
	parameters->add(decayTime);
	FloatValueParameter *releaseTime = new FloatValueParameter("Release time", "ms", 0.0, 400.0);
	parameters->add(releaseTime);
	
	return parameters;
}