/*
 *  NoteList.cpp
 *  Simpleton
 *
 *  Created by Rickard Lindroth on 6/13/09.
 *  Copyright 2009 eatingbits. All rights reserved.
 *
 */

#include "NoteList.h"

void NoteList :: add(int value) {
	mElements[mSize++] = value;
}

/* Removes the first occurance of the tone we want to remove */
void NoteList :: remove(int value) { 
	bool found = false;
	for (int i = 0; i < mSize; ++i) {
		if (mElements[i] == value) {
			found = true;
		}
		if (found && i < mSize - 1) {
			mElements[i] = mElements[i+1];
		}
	}
	if (found) {
		--mSize;
	}
}

