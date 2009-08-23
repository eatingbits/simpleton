#ifndef __HighPass_h__
#define __HighPass_h__

#include "Source.h"
#include <vector>

class HighPass : public Source {
public:
	HighPass(Source& source, float frequency, float resonance, int sampleRate);
	float sampleValue();
	bool isPlaying();
	bool isNoteOn();
	void noteOn();
	void noteOff();
	
private:
  enum Constants { kNumPreviousPoints = 2 };
  
  void calculateCoefficients(float frequency, float resonance, int sampleRate);
  
  std::vector<float> mInputPoints;
  std::vector<float> mOutputPoints;
  
  float mInputCoeff1;
  float mInputCoeff2;
  float mOutputCoeff1;
  float mOutputCoeff2;
	Source& mSource;
};

#endif

