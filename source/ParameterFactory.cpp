#include "ParameterFactory.h"
#include "Parameters.h"
#include "OscillatorParameters.h"
#include "GeneralComponent.h"
#include "EffectComponent.h"
#include "ChorusComponent.h"
#include "LowPassComponent.h"
#include "EffectChangedCallback.h"

Parameters *ParameterFactory :: createParameters(OscillatorChangeCallback *oscillatorCallback, GeneralChangedCallback *generalCallback, EffectChangedCallback *effectChanged) {
	Parameters *parameters = new Parameters();
  
	parameters->add(new GeneralComponent(generalCallback));
	
	EffectComponent *effect1  = new EffectComponent(0, effectChanged);
	effect1->add("Chorus", new ChorusComponent());
  effect1->add("Lowpass", new LowPassComponent());
	EffectComponent *effect2 = new EffectComponent(1, effectChanged);
	effect2->add("Chorus", new ChorusComponent());
  effect2->add("Lowpass", new LowPassComponent());
	
	
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