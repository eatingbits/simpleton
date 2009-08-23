#include "LowPass.h"
#include <cmath>

LowPass :: LowPass(Source& source, float frequency, float resonance, int sampleRate) :
mSource(source) {
  for(int i = 0; i < kNumPreviousPoints; ++i) {
    mInputPoints.push_back(0.0);
    mOutputPoints.push_back(0.0);
  }
  calculateCoefficients(frequency, resonance, sampleRate);
}

float LowPass :: sampleValue() {
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

void LowPass :: calculateCoefficients(float frequency, float resonance, int sampleRate) {
  float filterConstant = 1.0 / tan(M_PI * frequency / (float)sampleRate);
  float filterConstantSquared = filterConstant * filterConstant;
  mInputCoeff1 = 1.0 / (1.0 + (resonance * filterConstant) + filterConstantSquared);
  mInputCoeff2 = 2.0 * mInputCoeff1;
  mOutputCoeff1 = 2.0 * mInputCoeff1 * (1.0 - filterConstantSquared);
  mOutputCoeff2 = mInputCoeff1 * (1.0 - (resonance * filterConstant) + filterConstantSquared);
}

bool LowPass :: isPlaying() {
	return mSource.isPlaying();
}

bool LowPass :: isNoteOn() {
	return mSource.isNoteOn();
}

void LowPass :: noteOn() {
	mSource.noteOn();
}

void LowPass :: noteOff() {
	mSource.noteOff();
}