#include "HighPassComponent.h"
#include "FloatValueParameter.h"
#include "HighPass.h"
#include "LinearScale.h"
#include "LogarithmicScale.h"

HighPassComponent :: HighPassComponent() {
  mFrequency = new FloatValueParameter("Frequency", "Hz", 60, 18000, 0, new LogaritmicScale<float>());
  mResonance = new FloatValueParameter("Resonance", "", 0.1, 1.414213562373095, 0, new LinearScale<float>());
	mParameters.push_back(mFrequency);
	mParameters.push_back(mResonance);
}

void HighPassComponent :: reset() {
  mFrequency->onChange(0.0);
	mResonance->onChange(0.0);
}

Source *HighPassComponent :: create(Source *source) {
  return new HighPass(*source, mFrequency->floatValue(), mResonance->floatValue(), 44100);
}