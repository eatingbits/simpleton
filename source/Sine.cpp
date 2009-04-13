/*
 *  Sine - Sine.cpp
 *  Created by Rickard Lindroth on 4/11/09
 *  Copyright (c) 2009 __MyCompanyName__, All rights reserved
 */

#ifndef __Sine_H
#include "Sine.h"
#endif

AudioEffect* createEffectInstance(audioMasterCallback audioMaster) {
	return new Sine(audioMaster);
}

Sine::Sine(audioMasterCallback audioMaster)
: AudioEffectX(audioMaster, kNumPrograms, kNumParameters) {
  mCurrentNoteFreq = 0;
  mNoteFrame = 0;
  mNotePlaying = false;
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

Sine::~Sine() {
}

VstInt32 Sine::canDo(char *text) {
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

bool Sine::copyProgram(long destination) {
  // TODO: Copy program to destination
  return false;
}

void Sine::initialize() {
  // TODO: Other plugin initialiazation goes here
}

VstInt32 Sine::getCurrentMidiProgram(VstInt32 channel, MidiProgramName *mpn) {
	if(channel < 0 || channel >= 16 || mpn == NULL) {
		return -1;
  }
  
	VstInt32 prg = 0;
  // TODO: Look up your current MIDI program and fill the MidiProgramName with it
	return prg;
}

bool Sine::getEffectName(char* name) {
  strncpy(name, "Sine", kVstMaxEffectNameLen);
  return true;
}

bool Sine::getMidiKeyName(VstInt32 channel, MidiKeyName *key) {
	// TODO: Fill in this information
  // key->thisProgramIndex;		// >= 0. fill struct for this program index.
	// key->thisKeyNumber;			// 0 - 127. fill struct for this key number.
	key->keyName[0] = 0;
	key->reserved = 0;				// zero
	key->flags = 0;					// reserved, none defined yet, zero.
	return true;
}

VstInt32 Sine::getMidiProgramCategory(VstInt32 channel, MidiProgramCategory *category) {
  // TODO: Get the MIDI program category
	return 0;
}

VstInt32 Sine::getMidiProgramName(VstInt32 channel, MidiProgramName *mpn) {
  // TODO: Return the MIDI program name
  return 0;
}

VstInt32 Sine::getNumMidiInputChannels() {
  // TODO: Change this value for polyphonic synths
  return 1;
}

VstInt32 Sine::getNumMidiOutputChannels() {
  // TODO: Change this value if you are sending MIDI output back to the host
  return 0;
}

bool Sine::getOutputProperties(VstInt32 index, VstPinProperties *properties) {
  if(index < kNumOutputs) {
    sprintf(properties->label, "%1ld Out", index + 1);
		properties->flags = kVstPinIsActive;
		if(index < 2) {
			properties->flags |= kVstPinIsStereo;
    }
    return true;
  }
  return false;
}

float Sine::getParameter(VstInt32 index) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      return 0.0;
  }
}

void Sine::getParameterDisplay(VstInt32 index, char *text) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      strcpy(text, "ERROR");
      break;
  }
}

void Sine::getParameterLabel(VstInt32 index, char *text) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      strcpy(text, "ERROR");
      break;
  }
}

void Sine::getParameterName(VstInt32 index, char *text) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      strcpy(text, "ERROR");
      break;
  }
}

VstPlugCategory Sine::getPlugCategory() { 
  return kPlugCategSynth;
}

bool Sine::getProductString(char* text) {
  // TODO: Replace with actual description of your synth
  strncpy(text, "Sine", kVstMaxProductStrLen);
  return true;
}

void Sine::getProgramName(char *name) {
}

bool Sine::getProgramNameIndexed(VstInt32 category, VstInt32 index, char *text) {
  // TODO: Return program name for index
  return false;
}

bool Sine::getVendorString(char* text) {
  strncpy(text, "__MyCompanyName__", kVstMaxVendorStrLen);
  return true;
}

VstInt32 Sine::getVendorVersion() {
  return 1000;
}

bool Sine::hasMidiProgramsChanged(VstInt32 channel) {
  return false;
}

void Sine::setBlockSize(VstInt32 blockSize) {
  // TODO: Handle this call if necessary
	AudioEffectX::setBlockSize(blockSize);
}

void Sine::setParameter(VstInt32 index, float value) {
  switch(index) {
    // TODO: Add other parameter cases here
    default:
      break;
  }
}

void Sine::setProgram(VstInt32 index) {
  // TOOD: Set local variables based on program parameters
}

void Sine::setProgramName(char *name) {
}

void Sine::setSampleRate(float sampleRate) {
	AudioEffectX::setSampleRate(sampleRate);
}