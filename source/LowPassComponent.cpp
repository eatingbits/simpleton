#include "LowPassComponent.h"
#include "FloatValueParameter.h"
#include "LowPass.h"
#include "LinearScale.h"
#include "LogarithmicScale.h"

LowPassComponent :: LowPassComponent() {
  mFrequency = new FloatValueParameter("Frequency", "Hz", 60, 18000, 1, new LogarithmicScale<float>());
  mResonance = new FloatValueParameter("Resonance", "", 0.1, 1.414213562373095, 0, new LinearScale<float>());
	mParameters.push_back(mFrequency);
	mParameters.push_back(mResonance);
}

void LowPassComponent :: reset() {
  mFrequency->onChange(1.0);
	mResonance->onChange(0.0);
}

Source *LowPassComponent :: create(Source *source) {
  return new LowPass(*source, mFrequency->floatValue(), mResonance->floatValue(), 44100);
}