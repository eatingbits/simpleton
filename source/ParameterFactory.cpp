#include "ParameterFactory.h"
#include "Parameters.h"
#include "OscillatorParameters.h"
#include "GeneralComponent.h"
#include "EffectComponent.h"
#include "ChorusComponent.h"

Parameters *ParameterFactory :: createParameters(OscillatorChangeCallback *oscillatorCallback, GeneralChangedCallback *generalCallback) {
	Parameters *parameters = new Parameters();
  
	parameters->add(new GeneralComponent(generalCallback));
	
	EffectComponent *effect1  = new EffectComponent();
	effect1->add("Chorus", new ChorusComponent());
	EffectComponent *effect2 = new EffectComponent();
	effect2->add("Chorus", new ChorusComponent());
	
	
/*	slotOn(slot);
	slotOff(slot);
	chorusChanged(slot, chorusValues);
	reverbChanged(slot, reverbValues);
*/	
	
	
	parameters->add(effect1);
	parameters->add(effect2);
//	parameters->add(new EffectComponent());
//	parameters->add(new EffectComponent());
	parameters->add(new OscillatorParameters(0, oscillatorCallback, 1.0, 1.0));
	parameters->add(new OscillatorParameters(1, oscillatorCallback, 0.0, 0.0));
	parameters->add(new OscillatorParameters(2, oscillatorCallback, 0.0, 0.0));
	
	return parameters;
}