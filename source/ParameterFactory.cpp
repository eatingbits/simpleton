#include "ParameterFactory.h"
#include "Parameters.h"
#include "Parameter.h"
#include "FloatValueParameter.h"
#include "NamedValueParameter.h"
#include "IntegerValueParameter.h"

Parameters *ParameterFactory :: createParameters() {
	Parameters *parameters = new Parameters();
  
	NamedValueParameter *nv1 = new NamedValueParameter("Oscillator", "");
	nv1->add("Noise");
  nv1->add("Sine");
  nv1->add("Square");
  nv1->add("Saw");
	parameters->add(nv1);
	Parameter *attack = new FloatValueParameter("Attack", "", 0.0, 2.0);
	parameters->add(attack);
	Parameter *attackTime = new IntegerValueParameter("Attack time", "ms", 0, 400);
	parameters->add(attackTime);
	Parameter *decay = new FloatValueParameter("Decay", "", 0.0, 2.0);
	parameters->add(decay);
	Parameter *decayTime = new IntegerValueParameter("Decay time", "ms", 0, 400);
	parameters->add(decayTime);
	Parameter *releaseTime = new IntegerValueParameter("Release time", "ms", 0, 400);
	parameters->add(releaseTime);
	
	return parameters;
}