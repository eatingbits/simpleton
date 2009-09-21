#ifndef __Simpleton_H
#include "Simpleton.h"
#endif

#include "Source.h"
#include "ChorusFactory.h"
#include "LowPass.h"
#include "OscillatorFactory.h"

Simpleton::Simpleton(const int32_t numOutputs, OscillatorFactory *oscillatorFactory) 
: mNumOutputs(numOutputs), mOscillatorFactory(oscillatorFactory) {
	initialize();
}

Simpleton::~Simpleton() {
}

bool Simpleton::initialize() {
  bool result = false;
	
  // Generate MIDI note table /////////////////////////////////////////////////
  // 12th root of 2 -- which is the factor used to calculate the frequency
  // between notes in a musical scale
  const float step = 1.059463094359f;
  // 440Hz = MIDI note A3.  So to find the lowest note on a keyboard, which is
  // C-2, we go down 6 octaves to A-3, then add 3 steps to go up to C-2
  const float baseFreq = 440.0f * pow(0.5f, 6) * step * step * step;
  float baseStep = 1.0; // step ^ 0
  for(int i = 0; i < 128; ++i) {
    mMidiNoteFrequencies[i] = baseFreq * baseStep;
    baseStep *= step;
  }
  
  // TODO: This is only hardcoded in here temporarily.  Other initialization
  // work might actually need to return a failure, in which case the user
  // should be warned.
  result = true;

  return result;
}

void Simpleton::noteOn(const int32_t note, const int32_t velocity) {
	float currentNoteFreq = mMidiNoteFrequencies[note];
	Source *oscillator = mOscillatorFactory->createOscillator(44100 / currentNoteFreq);
	Source *oscillatorWithEffects = mOscillatorFactory->createEffectChain(oscillator);
	oscillatorWithEffects->noteOn();
  noteList.add(note, oscillatorWithEffects);
}

void Simpleton::noteOff(const int32_t note) {
  if (playing()) {
		Source *source = noteList.getSource(note);
		if (source != NULL) {
			source->noteOff();
		}
  }
}

void Simpleton :: onChange(bool polyphony) {
	noteList.setPolyphony(polyphony);
}

bool Simpleton :: playing() {
	return (noteList.isPlaying());
}

void Simpleton::requestSamples(float **outputs, VstInt32 samples) {
	for (int sample = 0; sample < samples; ++sample) {
		float value = noteList.sampleValue();
		for (int channel = 0; channel < mNumOutputs; ++channel) {
			outputs[channel][sample] = value;
		}
	}
}
