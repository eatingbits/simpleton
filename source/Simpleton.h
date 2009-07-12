#ifndef __Simpleton_H
#define __Simpleton_H

#include <math.h>
#include <stdio.h>

#ifndef __audioeffectx__
#include "audioeffectx.h"
#endif

#include "NoteList.h"
#include "OscillatorPrototype.h"
#include "Parameters.h"

/*static const unsigned long kUniqueId = 'SIMP';
static const int kNumPrograms = 0;
static const int kNumInputs = 0;
static const int kNumOutputs = 2; */

class Oscillator;

class Simpleton {
public:
  Simpleton(const int32_t numOutputs);
  ~Simpleton();
	
	void requestSamples(float **outputs, int32_t samples);
  void noteOn(int32_t note, int32_t velocity);
  void noteOff(int32_t note);	
    
private:
  bool playing();
  bool initialize();
  
	const int32_t mNumOutputs;
  
  // Note frequencies for all MIDI notes.  Generated during initialization
  float mMidiNoteFrequencies[128];
  NoteList noteList;
	
  OscillatorType mCurrentOscillator;	
	OscillatorPrototype *mOscillatorPrototype;
};

#endif
