/*
 *  Simpleton - Simpleton.cpp
 *  Created by Rickard Lindroth on 4/11/09
 *  Copyright (c) 2009 eatingbits, All rights reserved
 */

#ifndef __Simpleton_H
#include "Simpleton.h"
#endif

AudioEffect* createEffectInstance(audioMasterCallback audioMaster) {
	return new Simpleton(audioMaster);
}

Simpleton::Simpleton(audioMasterCallback audioMaster)
: AudioEffectX(audioMaster, kNumPrograms, kNumParameters) {
  mCurrentNoteFreq = 0;
  mNoteFrame = 0;
  mNotePlaying = 0;
  if(audioMaster != NULL) {
    setNumInputs(kNumInputs);
    setNumOutputs(kNumOutputs);
    setUniqueID(kUniqueId);
    canProcessReplacing();
    isSynth();
  }
  
  initialize();
  suspend();
}

Simpleton::~Simpleton() {
}

VstInt32 Simpleton::canDo(char *text) {
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

bool Simpleton::copyProgram(long destination) {
  // TODO: Copy program to destination
  return false;
}

VstInt32 Simpleton::getCurrentMidiProgram(VstInt32 channel, MidiProgramName *mpn) {
	if(channel < 0 || channel >= 16 || mpn == NULL) {
		return -1;
  }
  
	VstInt32 prg = 0;
  // TODO: Look up your current MIDI program and fill the MidiProgramName with it
	return prg;
}

bool Simpleton::getEffectName(char *name) {
  strncpy(name, "Simpleton", kVstMaxEffectNameLen);
  return true;
}

bool Simpleton::getMidiKeyName(VstInt32 channel, MidiKeyName *key) {
	// TODO: Fill in this information
  // key->thisProgramIndex;		// >= 0. fill struct for this program index.
	// key->thisKeyNumber;			// 0 - 127. fill struct for this key number.
	key->keyName[0] = 0;
	key->reserved = 0;				// zero
	key->flags = 0;					// reserved, none defined yet, zero.
	return true;
}

VstInt32 Simpleton::getMidiProgramCategory(VstInt32 channel, MidiProgramCategory *category) {
  // TODO: Get the MIDI program category
	return 0;
}

VstInt32 Simpleton::getMidiProgramName(VstInt32 channel, MidiProgramName *mpn) {
  // TODO: Return the MIDI program name
  return 0;
}

VstInt32 Simpleton::getNumMidiInputChannels() {
  // TODO: Change this value for polyphonic synths
  return 1;
}

VstInt32 Simpleton::getNumMidiOutputChannels() {
  // TODO: Change this value if you are sending MIDI output back to the host
  return 0;
}

bool Simpleton::getOutputProperties(VstInt32 index, VstPinProperties *properties) {
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

float Simpleton::getParameter(VstInt32 index) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      return 0.0;
  }
}

void Simpleton::getParameterDisplay(VstInt32 index, char *text) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      strcpy(text, "ERROR");
      break;
  }
}

void Simpleton::getParameterLabel(VstInt32 index, char *text) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      strcpy(text, "ERROR");
      break;
  }
}

void Simpleton::getParameterName(VstInt32 index, char *text) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      strcpy(text, "ERROR");
      break;
  }
}

VstPlugCategory Simpleton::getPlugCategory() { 
  return kPlugCategSynth;
}

bool Simpleton::getProductString(char *text) {
  // TODO: Replace with actual description of your synth
  strncpy(text, "Simpleton", kVstMaxProductStrLen);
  return true;
}

void Simpleton::getProgramName(char *name) {
}

bool Simpleton::getProgramNameIndexed(VstInt32 category, VstInt32 index, char *text) {
  // TODO: Return program name for index
  return false;
}

bool Simpleton::getVendorString(char *text) {
  strncpy(text, "eatingbits", kVstMaxVendorStrLen);
  return true;
}

VstInt32 Simpleton::getVendorVersion() {
  return 1000;
}

bool Simpleton::hasMidiProgramsChanged(VstInt32 channel) {
  return false;
}

bool Simpleton::playing() {
  return mNotePlaying > 0;
}

void Simpleton::setBlockSize(VstInt32 blockSize) {
  // TODO: Handle this call if necessary
	AudioEffectX::setBlockSize(blockSize);
}

void Simpleton::setParameter(VstInt32 index, float value) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      break;
  }
}

void Simpleton::setProgram(VstInt32 index) {
  // TOOD: Set local variables based on program parameters
}

void Simpleton::setProgramName(char *name) {
}

void Simpleton::setSampleRate(float sampleRate) {
	AudioEffectX::setSampleRate(sampleRate);
}