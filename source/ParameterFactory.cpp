#include "ParameterFactory.h"
#include "Parameters.h"
#include "Parameter.h"
#include "FloatValueParameter.h"
#include "NamedValueParameter.h"

Parameters *ParameterFactory :: createParameters() {
	Parameters *parameters = new Parameters();
  parameters->add(new FloatValueParameter("test", "stuff", 0.0, 1.0));
  parameters->add(new FloatValueParameter("test2", "db", 0.0, 2.0));
  
  NamedValueParameter *nv1 = new NamedValueParameter("named1", "aoeu");
  nv1->add("one");
  nv1->add("two");
  nv1->add("three");
  nv1->add("four");
	parameters->add(nv1);
	return parameters;
}