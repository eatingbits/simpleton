/*
 *  Envelope.h
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ENVELOPE_H__
#define __ENVELOPE_H__

class Envelope {
public:
	virtual ~Envelope() {}
	virtual float getAmplitudeModifier() = 0;
	virtual bool isPlaying() = 0; 
	virtual void noteOn() = 0;
	virtual void noteOff() = 0;
};

#endif

