/*
 *  Simpleton - Simpleton.cpp
 *  Created by Rickard Lindroth on 4/11/09
 *  Copyright (c) 2009 eatingbits, All rights reserved
 */

#ifndef __Simpleton_H
#include "Simpleton.h"
#endif

#include "SilenceOscillator.h"
#include "SineOscillator.h"
#include "SquareOscillator.h"
#include "LFO.h"
#include "ADSREnvelope.h"
#include "FloatValueParameter.h"
#include "NamedValueParameter.h"

AudioEffect* createEffectInstance(audioMasterCallback audioMaster) {
  Parameters *parameters = new Parameters();
  parameters->add(new FloatValueParameter("test", "stuff", 0.0, 1.0));
  parameters->add(new FloatValueParameter("test2", "db", 0.0, 2.0));
  
  NamedValueParameter *nv1 = new NamedValueParameter("named1", "aoeu");
  nv1->add("one");
  nv1->add("two");
  nv1->add("three");
  nv1->add("four");
  parameters->add(nv1);
  
	return new Simpleton(audioMaster, parameters);
}

Simpleton::Simpleton(audioMasterCallback audioMaster, Parameters *parameters)
: AudioEffectX(audioMaster, kNumPrograms, parameters->size()),
mParameters(parameters) 
{
  mCurrentNoteFreq = 0;
  if(audioMaster != NULL) {
    setNumInputs(kNumInputs);
    setNumOutputs(kNumOutputs);
    setUniqueID(kUniqueId);
    canProcessReplacing();
    isSynth();
  }
  
	mOscillatorPrototype = new OscillatorPrototype();
//	mOscillatorPrototype->add(kSineOscillator, 44100, 1.6, 0, -1.6, 7, 4);
//	mOscillatorPrototype->add(kSquareOscillator, 44100, 1.6, 0, -1.6, 7, 4);
//	mOscillatorPrototype->add(kSawOscillator, 44100, 1.0, 0, 0.0, 0, 0);
//	mOscillatorPrototype->add(kNoiseOscillator, 44100, 0.5, 0, -0.5, 10, 0);
//	mOscillatorPrototype->add(kSquareOscillator, 44100, 1.0, 0, -1.0, 6, 0);
	mOscillatorPrototype->add(kSawOscillator, 44100, 1.0, 3, 0.0, 0, 10);
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
  return mParameters->getParameterValue(index);
}

void Simpleton::getParameterDisplay(VstInt32 index, char *text) {
  mParameters->getParameterDisplay(index, text);
}

void Simpleton::getParameterLabel(VstInt32 index, char *text) {
  mParameters->getParameterUnit(index, text);
}

void Simpleton::getParameterName(VstInt32 index, char *text) {
  mParameters->getParameterName(index, text);
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

void Simpleton::setBlockSize(VstInt32 blockSize) {
  // TODO: Handle this call if necessary
	AudioEffectX::setBlockSize(blockSize);
}

void Simpleton::setParameter(VstInt32 index, float value) {
  mParameters->setParameter(index, value);
}

void Simpleton::setProgram(VstInt32 index) {
  // TOOD: Set local variables based on program parameters
}

void Simpleton::setProgramName(char *name) {
}

void Simpleton::setSampleRate(float sampleRate) {
	AudioEffectX::setSampleRate(sampleRate);
}