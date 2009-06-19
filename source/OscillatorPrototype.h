/*
 *  OscillatorPrototype.h
 *  Simpleton
 *
 *  Created by Rickard Bäckman on 6/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __OSCILLATOR_PROTOTYPE_H__
#define	__OSCILLATOR_PROTOTYPE_H__	

class Oscillator;

enum OscillatorType {
  kSineOscillator,
  kSquareOscillator,
	kSawOscillator,
	kReverseSawOscillator
};

class Prototype {
public:
	Prototype(OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime) :
		mType(type), mSampleRate(sampleRate), mAttackAmplitude(attackAmplitude), mAttackTime(attackTime),
	mDecayAmplitude(decayAmplitude), mDecayTime(decayTime), mReleaseTime(releaseTime) {}
	
	Oscillator *create(Oscillator *parent, float samplesPerPeriod);
private:
	OscillatorType mType;
	int mSampleRate;
	float mAttackAmplitude;
	int mAttackTime;
	float mDecayAmplitude;
	int mDecayTime;
	int mReleaseTime;
};

class OscillatorPrototype {
public:
	OscillatorPrototype() {}
	void add(OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime);		
	Oscillator *create(float samplesPerPeriod);
private:
	Prototype *mPrototypes[4];
	int mPrototypeSize;
};

#endif
