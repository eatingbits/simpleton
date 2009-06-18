/*
 *  Buffer.cpp
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/17/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Buffer.h"

Buffer :: Buffer(int channels, int samples) {
	mChannels = channels;
	mSamples = samples; 
	mValues = new float[channels * samples];
}

void Buffer :: setValue(int channel, int sample, float value) {
	mValues[channel + (sample * mChannels)] = value;
}

float Buffer :: getValue(int channel, int sample) {
	return mValues[channel + (sample * mChannels)];
}

void Buffer :: zero() {
	for (int sample = 0; sample < mSamples; ++sample) {
		for (int channel = 0; channel < mChannels; ++channel) {
			setValue(channel, sample, 0.0);
		}
	}
}

void Buffer :: copyTo(float **outputs) {
	for (int sample = 0; sample < mSamples; ++sample) {
		for (int channel = 0; channel < mChannels; ++channel) {
			outputs[channel][sample] = mValues[channel + (mChannels * sample)];
		}
	}
}

void Buffer :: addTo(float **outputs) {
	for (int sample = 0; sample < mSamples; ++sample) {
		for (int channel = 0; channel < mChannels; ++channel) {
			outputs[channel][sample] += mValues[channel + (mChannels * sample)];
		}
	}
}

