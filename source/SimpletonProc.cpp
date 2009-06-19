/*
 *  Simpleton - SimpletonProc.cpp
 *  Created by Rickard Lindroth on 4/11/09
 *  Copyright (c) 2009 eatingbits, All rights reserved
 */

#ifndef __Simpleton_H
#include "Simpleton.h"
#endif

#include "SineOscillator.h"
#include "SquareOscillator.h"
#include "SilenceOscillator.h"
#include "Buffer.h"

void Simpleton::noteOn(const VstInt32 note, const VstInt32 velocity, const VstInt32 delta) {
  mCurrentNoteFreq = mMidiNoteFrequencies[note];
	mSquareOscillator->reset();
	mSineOscillator->reset();
  mNotePlaying += 1;
  noteList.add(note);
}

void Simpleton::noteOff(const VstInt32 note, const VstInt32 delta) {
  if (mNotePlaying > 0) {
	  mNotePlaying -= 1;
	  if (noteList.current() == note) {
		  mNoteFrame = 0;
	  }
	  noteList.remove(note);
	  
	  
    VstInt32 oldNote = noteList.current();
    mCurrentNoteFreq = mMidiNoteFrequencies[oldNote];
  }
}

VstInt32 Simpleton::processEvents (VstEvents* ev) {
	for(VstInt32 i = 0; i < ev->numEvents; ++i) {
    // We are only interested in catching MIDI note events here
		if((ev->events[i])->type != kVstMidiType) {
			continue;
    }
    
    // Sadly, reinterpret_cast is needed here, or else we must use a
    // C-style cast, which is even uglier.
		VstMidiEvent *event = reinterpret_cast<VstMidiEvent*>(ev->events[i]);
		const char *midiData = event->midiData;
    // Ignore the MIDI channel, since this is a single-part synth anyways
		VstInt32 status = midiData[0] & 0xf0;
    
    // MIDI note on and note off events, respectively
		if(status == 0x90 || status == 0x80) {
      // The host should technically not deliver events which have the highest
      // bit set, but it never hurts to be extra careful.
			const VstInt32 note = midiData[1] & 0x7f;
      VstInt32 velocity = midiData[2] & 0x7f;
			if(status == 0x80) {
        // Note off events can actually have non-zero velocities, but our synth
        // doesn't have any special handling for such events, so we set the
        // velocity to zero for all note off events.
				velocity = 0;
      }   
      
      // Many keyboards send MIDI note on (0x90) with velocity 0 for note off
      // events, so if we only check the velocity then we can catch both cases.
			if(velocity == 0) {
				noteOff(note, event->deltaFrames);
      }
      else {
				noteOn(note, velocity, event->deltaFrames);
      }
    }
    // MIDI control change (CC) messages
    else if(status == 0xb0) {
      // MIDI 0x7b -> All sound off, usually a "panic" message instructing
      // the synth to stop playing all sound immediately
      // MIDI 0x7e -> All notes off, meaning that all notes should receive
      // a note off message.  This is sometimes sent by sequencers at the
      // end of a song.
			if(midiData[1] == 0x7e || midiData[1] == 0x7b) {
        for(int i = 0; i < 128; ++i) {
          noteOff(i, 0);
        }
      }
    }
	}
  
  // TODO: Should return only if everything went ok in the above code
	return 1;
}

Oscillator *Simpleton :: currentOscillator() {
  if (!playing()) {
    return mSilenceOscillator;
  }
  
  switch (mCurrentOscillator) {
    case kSineOscillator:
      return mSineOscillator;
    case kSquareOscillator:
      return mSquareOscillator;
    default:
      return mSilenceOscillator;

  }
}

void Simpleton::processReplacing(float **inputs, float **outputs, VstInt32 samples) {
	Oscillator *oscillator = currentOscillator();
	float samplesPerPeriod = 44100 / mCurrentNoteFreq;
	for (int sample = 0; sample < samples; ++sample) {
		float value = oscillator->sampleValue(samplesPerPeriod);
		for (int channel = 0; channel < kNumOutputs; ++channel) {
			outputs[channel][sample] = value;
		}
	}
}