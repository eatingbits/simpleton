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
  NoteList() : size(0) {}
  void add(int value) { elements[size++] = value; }
  void remove(int value) { 
    bool found = false;
    for (int i = 0; i < size; i++) {
      if (elements[i] == value) {
        found = true;
      }
      if (found && i < size - 1) {
        elements[i] = elements[i+1];
      }
    }
    if (found) {
      --size;
    }
  }
  
  int current() {
    return elements[size-1];
  }
  
  bool isEmpty() {
    return size > 0;
  }
    
private:
  int elements[32];
  int size;
};

