#ifndef __Simpleton_H
#define __Simpleton_H

#include <math.h>
#include <stdio.h>

#ifndef __audioeffectx__
#include "audioeffectx.h"
#endif

#include "NoteList.h"
#include "Parameters.h"
#include "OscillatorPrototype.h"
#include "OscillatorChangeCallback.h"
#include "GeneralChangedCallback.h"

class Oscillator;
class OscillatorFactory;

class Simpleton : public GeneralChangedCallback {
public:
  Simpleton(const int32_t numOutputs, OscillatorFactory *oscillatorFactory);
  ~Simpleton();
	
	void requestSamples(float **outputs, int32_t samples);
  void noteOn(int32_t note, int32_t velocity);
  void noteOff(int32_t note);	
	
	void onChange(bool polyphony);
    
private:
  bool playing();
  bool initialize();

  
	const int32_t mNumOutputs;
	OscillatorFactory *mOscillatorFactory;
  
  // Note frequencies for all MIDI notes.  Generated during initialization
  float mMidiNoteFrequencies[128];
  NoteList noteList;
};

#endif
