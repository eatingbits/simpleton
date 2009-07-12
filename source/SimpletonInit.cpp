#ifndef __Simpleton_H
#include "Simpleton.h"
#endif

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