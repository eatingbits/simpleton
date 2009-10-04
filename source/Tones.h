#ifndef __TONES_H__
#define __TONES_H__

class Tones {
public:
	Tones();
	
	float operator[] (int pos) const;
	
private:
  // Note frequencies for all MIDI notes.  Generated during initialization
  float mMidiNoteFrequencies[128];	
};

#endif

