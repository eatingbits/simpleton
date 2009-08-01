#ifndef __OSCILLATOR_PROTOTYPE_H__
#define	__OSCILLATOR_PROTOTYPE_H__	

#include <string>

class Oscillator;

enum OscillatorType {
  kSineOscillator,
  kSquareOscillator,
	kSawOscillator,
	kReverseSawOscillator,
	kNoiseOscillator
};

class Prototype {
public:
	Prototype(OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime, float volume) :
		mType(type), mSampleRate(sampleRate), mAttackAmplitude(attackAmplitude), mAttackTime(attackTime),
	mDecayAmplitude(decayAmplitude), mDecayTime(decayTime), mReleaseTime(releaseTime), mVolume(volume) {}
	
	void setAttack(float attackAmplitude) { mAttackAmplitude = attackAmplitude; }
	void setAttackTime(int attackTime) { mAttackTime = attackTime; }
	void setDecay(float decayAmplitude) { mDecayAmplitude = decayAmplitude; }
	void setDecayTime(int decayTime) { mDecayTime = decayTime; }
	void setReleaseTime(int releaseTime) { mReleaseTime = releaseTime; }
	
	bool isSilent() { return mVolume < 0.02; }
	Oscillator *create(Oscillator *parent, float samplesPerPeriod);
	
	static OscillatorType typeFromString(const std::string& name);
private:
	OscillatorType mType;
	int mSampleRate;
	float mAttackAmplitude;
	int mAttackTime;
	float mDecayAmplitude;
	int mDecayTime;
	int mReleaseTime;
	float mVolume;
};

class OscillatorPrototype {
public:
	OscillatorPrototype();
	void add(OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime);		
	void replace(int index, Prototype *prototype);
	void clear();
	Oscillator *create(float samplesPerPeriod);
	
	void setAttack(float attackAmplitude);
	void setAttackTime(int attackTime);
	void setDecay(float decayAmplitude);
	void setDecayTime(int decayTime);
	void setReleaseTime(int releaseTime);
private:
	Prototype *mPrototypes[4];
	int mPrototypeSize;
};

#endif

