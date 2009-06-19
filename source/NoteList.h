/*
 *  NoteList.h
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

class NoteList {
public:
  NoteList() : mSize(0) {}
  void add(int value);
	void remove(int value);
  int current() { return mElements[mSize-1]; }
  bool isEmpty() { return mSize > 0; }
private:
  int mElements[128];
  int mSize;
};

