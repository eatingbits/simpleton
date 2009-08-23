#include "HighPass.h"
#include <cmath>

HighPass :: HighPass(Source& source, float frequency, float resonance, int sampleRate) :
mSource(source) {
  for(int i = 0; i < kNumPreviousPoints; ++i) {
    mInputPoints.push_back(0.0);
    mOutputPoints.push_back(0.0);
  }
  calculateCoefficients(frequency, resonance, sampleRate);
}

float HighPass :: sampleValue() {
  float currentValue = mSource.sampleValue();
  
  float result = (mInputCoeff1 * currentValue) +
                 (mInputCoeff2 * mInputPoints.at(0)) +
                 (mInputCoeff1 * mInputPoints.at(1)) -
                 (mOutputCoeff1 * mOutputPoints.at(0)) -
                 (mOutputCoeff2 * mOutputPoints.at(1));
  
  mInputPoints.insert(mInputPoints.begin(), currentValue);         
  mInputPoints.pop_back();
  mOutputPoints.insert(mOutputPoints.begin(), result);
  mOutputPoints.pop_back();
  
	return result;
}

void HighPass :: calculateCoefficients(float frequency, float resonance, int sampleRate) {
  float filterConstant = tan(M_PI * frequency / (float)sampleRate);
  float filterConstantSquared = filterConstant * filterConstant;
  mInputCoeff1 = 1.0 / (1.0 + (resonance * filterConstant) + filterConstantSquared);
  mInputCoeff2 = -2.0 * mInputCoeff1;
  mOutputCoeff1 = 2.0 * mInputCoeff1 * (filterConstantSquared - 1.0);
  mOutputCoeff2 = mInputCoeff1 * (1.0 - (resonance * filterConstant) + filterConstantSquared);
}

bool HighPass :: isPlaying() {
	return mSource.isPlaying();
}

bool HighPass :: isNoteOn() {
	return mSource.isNoteOn();
}

void HighPass :: noteOn() {
	mSource.noteOn();
}

void HighPass :: noteOff() {
	mSource.noteOff();
}