/*
 *  NoiseOscillator.cpp
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "NoiseOscillator.h"
#include <cstdlib>

float NoiseOscillator :: nextSampleValue() {
	float amplitudeModifier = getAmplitudeModifier();
	long value = random();
	float ret = ((float) (1000 - (value % 2000))) / 1000.0;
	return amplitudeModifier * ret;
}

/* x % 10
  
   0 % 10 = 0
	 1 % 10 = 1 
   2 % 10 = 2
...
	 9 % 10 = 9
	10 % 10 = 0
  11 % 10 = 1
  ..
	19 % 10 = 9
	

	1 % 2000 = 1
  1999 % 2000 = 1999
  2000 % 2000 = 0
  2001 % 2000 = 1
  3999 % 2000 = 1999
*/