#ifndef __NoteList_h__
#define __NoteList_h__

class Source;

class NoteList {
public:
  NoteList() : mSize(0) {}
  void add(int value, Source *source);
	void remove(int value);
  int current() { return mElements[mSize-1]; }
  bool isEmpty() { return mSize == 0; }
	bool isPlaying() { return mSize > 0; }
	Source *getSource(int note);
	Source *getCurrentSource() { return mOscillators[mSize-1]; }
	float sampleValue();
private:
  int mElements[128];
	Source *mOscillators[128];
  int mSize;
};

#endif