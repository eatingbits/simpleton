#include "SimpletonVST.h"
#include "Parameters.h"
#include "ParameterFactory.h"
#include "Simpleton.h"
#include <cstdio>
#include <vector>
#include <string>

AudioEffect* createEffectInstance(audioMasterCallback audioMaster) {
	Simpleton *simpleton = new Simpleton(kNumOutputs);	
	ParameterFactory factory;
  Parameters *parameters = factory.createParameters(simpleton, simpleton);
	
	SimpletonVST *vst = new SimpletonVST(audioMaster, simpleton, parameters);
	return vst;
}

SimpletonVST::SimpletonVST(audioMasterCallback audioMaster, Simpleton *simpleton, Parameters *parameters)
: AudioEffectX(audioMaster, kNumPrograms, parameters->size()),
mSimpleton(simpleton), mParameters(parameters), mInitialized(false) 
{
  if(audioMaster != NULL) {
    setNumInputs(kNumInputs);
    setNumOutputs(kNumOutputs);
    setUniqueID(kUniqueId);
    canProcessReplacing();
    isSynth();
  }
  
  suspend();
}


VstInt32 SimpletonVST::canDo(char *text) {
  // TODO: Fill in according to your plugin's capabilities
  if(!strcmp(text, "receiveVstEvents")) {
		return 1;
  }
  else if(!strcmp(text, "receiveVstMidiEvent")) {
		return 1;
  }
	else if(!strcmp(text, "midiProgramNames")) {
		return 1;
  }
  
  // -1 => explicitly can't do; 0 => don't know
	return 0;
}

bool SimpletonVST::copyProgram(long destination) {
  // TODO: Copy program to destination
  return false;
}

VstInt32 SimpletonVST::getCurrentMidiProgram(VstInt32 channel, MidiProgramName *mpn) {
	if(channel < 0 || channel >= 16 || mpn == NULL) {
		return -1;
  }
  
	VstInt32 prg = 0;
  // TODO: Look up your current MIDI program and fill the MidiProgramName with it
	return prg;
}

bool SimpletonVST::getEffectName(char *name) {
  strncpy(name, "Simpleton", kVstMaxEffectNameLen);
  return true;
}

bool SimpletonVST::getMidiKeyName(VstInt32 channel, MidiKeyName *key) {
	// TODO: Fill in this information
  // key->thisProgramIndex;		// >= 0. fill struct for this program index.
	// key->thisKeyNumber;			// 0 - 127. fill struct for this key number.
	key->keyName[0] = 0;
	key->reserved = 0;				// zero
	key->flags = 0;					// reserved, none defined yet, zero.
	return true;
}

VstInt32 SimpletonVST::getMidiProgramCategory(VstInt32 channel, MidiProgramCategory *category) {
  // TODO: Get the MIDI program category
	return 0;
}

VstInt32 SimpletonVST::getMidiProgramName(VstInt32 channel, MidiProgramName *mpn) {
  // TODO: Return the MIDI program name
  return 0;
}

VstInt32 SimpletonVST::getNumMidiInputChannels() {
  // TODO: Change this value for polyphonic synths
  return 1;
}

VstInt32 SimpletonVST::getNumMidiOutputChannels() {
  // TODO: Change this value if you are sending MIDI output back to the host
  return 0;
}

bool SimpletonVST::getOutputProperties(VstInt32 index, VstPinProperties *properties) {
  if(index < kNumOutputs) {
    sprintf(properties->label, "%1ld Out", static_cast<long int>(index + 1));
		properties->flags = kVstPinIsActive;
		if(index < 2) {
			properties->flags |= kVstPinIsStereo;
    }
    return true;
  }
  return false;
}

float SimpletonVST::getParameter(VstInt32 index) {
  return mParameters->getParameterValue(index);
}

void SimpletonVST::getParameterDisplay(VstInt32 index, char *text) {
  mParameters->getParameterDisplay(index, text);
}

void SimpletonVST::getParameterLabel(VstInt32 index, char *text) {
  mParameters->getParameterUnit(index, text);
}

void SimpletonVST::getParameterName(VstInt32 index, char *text) {
  mParameters->getParameterName(index, text);
}

VstPlugCategory SimpletonVST::getPlugCategory() { 
  return kPlugCategSynth;
}

bool SimpletonVST::getProductString(char *text) {
  // TODO: Replace with actual description of your synth
  strncpy(text, "Simpleton", kVstMaxProductStrLen);
  return true;
}

void SimpletonVST::getProgramName(char *name) {
}

bool SimpletonVST::getProgramNameIndexed(VstInt32 category, VstInt32 index, char *text) {
  // TODO: Return program name for index
  return false;
}

bool SimpletonVST::getVendorString(char *text) {
  strncpy(text, "eatingbits", kVstMaxVendorStrLen);
  return true;
}

VstInt32 SimpletonVST::getVendorVersion() {
  return 1000;
}

bool SimpletonVST::hasMidiProgramsChanged(VstInt32 channel) {
  return false;
}

void SimpletonVST::setBlockSize(VstInt32 blockSize) {
  // TODO: Handle this call if necessary
	AudioEffectX::setBlockSize(blockSize);
}

void SimpletonVST::setParameter(VstInt32 index, float value) {
  mParameters->setParameter(index, value);
}

void SimpletonVST::setProgram(VstInt32 index) {
  // TOOD: Set local variables based on program parameters
}

void SimpletonVST::setProgramName(char *name) {
}

void SimpletonVST::setSampleRate(float sampleRate) {
	AudioEffectX::setSampleRate(sampleRate);
}

VstInt32 SimpletonVST::processEvents (VstEvents* ev) {
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
				mSimpleton->noteOff(note); //, event->deltaFrames);
      }
      else {
				mSimpleton->noteOn(note, velocity); //, event->deltaFrames);
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
					mSimpleton->noteOff(i); //, 0);
        }
      }
    }
	}
  
  // TODO: Should return only if everything went ok in the above code
	return 1;
}

void SimpletonVST::processReplacing(float **inputs, float **outputs, VstInt32 samples) {
	mSimpleton->requestSamples(outputs, samples);
}