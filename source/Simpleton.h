/*
 *  Simpleton - Simpleton.h
 *  Created by Rickard Lindroth on 4/11/09
 *  Copyright (c) 2009 eatingbits, All rights reserved
 */

#ifndef __Simpleton_H
#define __Simpleton_H

#include <math.h>
#include <stdio.h>

#ifndef __audioeffectx__
#include "audioeffectx.h"
#endif

enum {
  // kFirstParameter = 0,
  kNumParameters
};

static const unsigned long kUniqueId = 'SIMP';
static const int kNumPrograms = 0;
static const int kNumInputs = 0;
static const int kNumOutputs = 2;

class Simpleton : public AudioEffectX {
public:
  Simpleton(audioMasterCallback audioMaster);
  ~Simpleton();
  
  virtual VstInt32 canDo(char *text);
  virtual bool copyProgram(long destination);
  
  virtual VstInt32 getCurrentMidiProgram(VstInt32 channel, MidiProgramName *currentProgram);
  virtual bool getEffectName(char *name);
  virtual bool getMidiKeyName(VstInt32 channel, MidiKeyName *keyName);
  virtual VstInt32 getMidiProgramCategory(VstInt32 channel, MidiProgramCategory *category);
  virtual VstInt32 getMidiProgramName(VstInt32 channel, MidiProgramName *midiProgramName);
  virtual VstInt32 getNumMidiInputChannels();
  virtual VstInt32 getNumMidiOutputChannels();
  virtual bool getOutputProperties(VstInt32 index, VstPinProperties *properties);
  virtual float getParameter(VstInt32 index);
  virtual void getParameterDisplay(VstInt32 index, char *text);
  virtual void getParameterLabel(VstInt32 index, char *label);
  virtual void getParameterName(VstInt32 index, char *text);
  virtual VstPlugCategory getPlugCategory();
  virtual void getProgramName(char *name);
  virtual bool getProgramNameIndexed(VstInt32 category, VstInt32 index, char *text);
  virtual bool getProductString(char *text);
  virtual bool getVendorString(char *text);
  virtual VstInt32 getVendorVersion();
  
  virtual bool hasMidiProgramsChanged(VstInt32 channel);
  
  virtual VstInt32 processEvents(VstEvents *events);
  virtual void processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames);
  
  virtual void setSampleRate(float sampleRate);
  virtual void setParameter(VstInt32 index, float value);
  virtual void setProgram(VstInt32 index);
  virtual void setProgramName(char *name);  
  virtual void setBlockSize(VstInt32 blockSize);
  
private:
  bool initialize();
  void noteOn(VstInt32 note, VstInt32 velocity, VstInt32 delta);
  void noteOff(VstInt32 note, VstInt32 delta);
  
  // Note frequencies for all MIDI notes.  Generated during initialization
  float mMidiNoteFrequencies[128];
  float mCurrentNoteFreq;
  bool mNotePlaying;
  unsigned long mNoteFrame;
};

#endif
