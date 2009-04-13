/*
 *  Sine - SineProc.cpp
 *  Created by Rickard Lindroth on 4/11/09
 *  Copyright (c) 2009 __MyCompanyName__, All rights reserved
 */

#ifndef __Sine_H
#include "Sine.h"
#endif

#ifndef __defaults_H
#include "defaults.h"
#endif

void Sine::noteOn(VstInt32 note, VstInt32 velocity, VstInt32 delta) {
  mCurrentNote = note;
  mNotePlaying = true;
}

void Sine::noteOff() {
  mNotePlaying = false;
}

VstInt32 Sine::processEvents (VstEvents* ev) {
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

void Sine::processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames) {
  for(int channel = 0; channel< kNumOutputs; ++channel) {
    for(int frame = 0; frame < sampleFrames; frame ++) {
      outputs[channel][frame] = 0.0f;  
    }
  }
}