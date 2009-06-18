/*
 *  Buffer.h
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/17/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __BUFFER_H__
#define __BUFFER_H__

class Buffer {
public:
	Buffer(int channels, int samples);
	virtual ~Buffer() {}
	virtual void setValue(int channel, int sample, float value);
	void zero();
	void copyTo(float **outputs);
	void addTo(float **outputs);
private:
	float *mValues;
	int mSamples;
	int mChannels;
};

#endif

