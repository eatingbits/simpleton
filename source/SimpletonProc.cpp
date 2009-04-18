/*
 *  Simpleton - SimpletonProc.cpp
 *  Created by Rickard Lindroth on 4/11/09
 *  Copyright (c) 2009 eatingbits, All rights reserved
 */

#ifndef __Simpleton_H
#include "Simpleton.h"
#endif

#ifndef __defaults_H
#include "defaults.h"
#endif

float Simpleton::calcFreqFromMidi(const int note){
  static const float stepSize = 1.059463094359f;
  static const float baseNoteFreq = 440.0 * pow(0.5f, 6) * stepSize * stepSize * stepSize;
  float noteFreq = baseNoteFreq * pow(stepSize, note);
  printf("%f \n", noteFreq);
  return noteFreq;
}

void Simpleton::noteOn(VstInt32 note, VstInt32 velocity, VstInt32 delta) {
  mCurrentNoteFreq = calcFreqFromMidi(note);
  mNotePlaying = true;
}

void Simpleton::noteOff() {
  mNotePlaying = false;
  mNoteFrame = 0;
}

VstInt32 Simpleton::processEvents (VstEvents* ev) {
	for(VstInt32 i = 0; i < ev->numEvents; i++) {
		if((ev->events[i])->type != kVstMidiType) {
			continue;
    }
    
		VstMidiEvent* event = (VstMidiEvent*)ev->events[i];
		char* midiData = event->midiData;
		VstInt32 status = midiData[0] & 0xf0; // ignoring channel
		if(status == 0x90 || status == 0x80) { // we only look at notes
			VstInt32 note = midiData[1] & 0x7f;
			VstInt32 velocity = midiData[2] & 0x7f;
			if(status == 0x80) {
				velocity = 0;	// note off by velocity 0
      }
			if(!velocity) {
				noteOff();
      }
      else {
				noteOn(note, velocity, event->deltaFrames);
      }
    }
    else if(status == 0xb0) {
			if(midiData[1] == 0x7e || midiData[1] == 0x7b) { // all notes off
				noteOff();
      }
    }
    event++;
	}
	return 1;
}

void Simpleton::processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames) {
  
  for(int frame = 0; frame < sampleFrames; frame ++) {
    mNoteFrame++;
    for(int channel = 0; channel< kNumOutputs; ++channel) {
      if(mNotePlaying) {
        outputs[channel][frame] = sin( (mNoteFrame / (44100 / mCurrentNoteFreq) * 2*M_PI));// + phaseOffset );
      } else {
        outputs[channel][frame] = 0;
      }
    }
  }
}