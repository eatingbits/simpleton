#ifndef __Simpleton_H
#include "Simpleton.h"
#endif

#include "SilenceOscillator.h"
#include "SineOscillator.h"
#include "SquareOscillator.h"
#include "LFO.h"
#include "ADSREnvelope.h"
#include "FloatValueParameter.h"
#include "NamedValueParameter.h"

Simpleton::Simpleton(const int32_t numOutputs) : mNumOutputs(numOutputs)
{
	mOscillatorPrototype = new OscillatorPrototype();
//	mOscillatorPrototype->add(kSineOscillator, 44100, 1.6, 0, -1.6, 7, 4);
//	mOscillatorPrototype->add(kSquareOscillator, 44100, 1.6, 0, -1.6, 7, 4);
//	mOscillatorPrototype->add(kSawOscillator, 44100, 1.0, 0, 0.0, 0, 0);
//	mOscillatorPrototype->add(kNoiseOscillator, 44100, 0.5, 0, -0.5, 10, 0);
//	mOscillatorPrototype->add(kSquareOscillator, 44100, 1.0, 0, -1.0, 6, 0);
	mOscillatorPrototype->add(kSineOscillator, 44100, 1.0, 0, 0.0, 0, 0);
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
	Oscillator *oscillator = mOscillatorPrototype->create(44100 / currentNoteFreq);
	oscillator->noteOn();
  noteList.add(note, oscillator);
}

void Simpleton::noteOff(const int32_t note) {
  if (playing()) {
		Oscillator *oscillator = noteList.getOscillator(note);
		if (oscillator != NULL) {
			oscillator->noteOff();
		}
  }
}

OscillatorType Simpleton :: fromString(const std::string& value) {
	if (value == "Sine") {
		return kSineOscillator;
	} else if (value == "Square") {
		return kSquareOscillator;
	} else if (value == "Saw") {
		return kSawOscillator;
	}
	return kSineOscillator;
}

void Simpleton::onOscillatorChange(const std::string& newType) {
	mOscillatorPrototype->clear();
	mOscillatorPrototype->add(fromString(newType), 44100, 1.0, 0, 0.0, 0, 0);
}

void Simpleton::onAttackChange(const float newAttack) {
	mOscillatorPrototype->setAttack(newAttack);
}

void Simpleton::onAttackTimeChange(const float newAttackTime) {
	mOscillatorPrototype->setAttackTime((int) newAttackTime);
}

void Simpleton::onDecayChange(const float newDecay) {
	mOscillatorPrototype->setDecay(-newDecay);
}

void Simpleton::onDecayTimeChange(const float newDecayTime) {
	mOscillatorPrototype->setDecayTime((int) newDecayTime);
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
