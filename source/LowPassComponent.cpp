#include "LowPassComponent.h"
#include "FloatValueParameter.h"
#include "LowPass.h"

LowPassComponent :: LowPassComponent() {
  mFrequency = new FloatValueParameter("Frequency", "Hz", 60, 5000, 1);
  mResonance = new FloatValueParameter("Resonance", "", 0.1, 1.414213562373095, 0);
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