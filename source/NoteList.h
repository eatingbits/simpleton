#ifndef __NoteList_h__
#define __NoteList_h__

class Oscillator;

class NoteList {
public:
  NoteList() : mSize(0) {}
  void add(int value, Oscillator *oscillator);
	void remove(int value);
  int current() { return mElements[mSize-1]; }
  bool isEmpty() { return mSize == 0; }
	bool isPlaying() { return mSize > 0; }
	Oscillator *getOscillator(int note);
	Oscillator *getCurrentOscillator() { return mOscillators[mSize-1]; }
	float sampleValue();
private:
  int mElements[128];
	Oscillator *mOscillators[128];
  int mSize;
};

#endif