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
  
  // TODO: Add additional handling here
}

void Sine::noteOff() {
  // TODO: Add additional handling here
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
  float *in_left = inputs[0];
  float *in_right = inputs[1];
  float *out_left = outputs[0];
  float *out_right = outputs[1];
}