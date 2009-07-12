#ifndef __OSCILLATOR_PROTOTYPE_H__
#define	__OSCILLATOR_PROTOTYPE_H__	

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
	Prototype(OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime) :
		mType(type), mSampleRate(sampleRate), mAttackAmplitude(attackAmplitude), mAttackTime(attackTime),
	mDecayAmplitude(decayAmplitude), mDecayTime(decayTime), mReleaseTime(releaseTime) {}
	
	void setAttack(float attackAmplitude) { mAttackAmplitude = attackAmplitude; }
	void setAttackTime(int attackTime) { mAttackTime = attackTime; }
	void setDecay(float decayAmplitude) { mDecayAmplitude = decayAmplitude; }
	void setDecayTime(int decayTime) { mDecayTime = decayTime; }
	
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
	OscillatorPrototype() : mPrototypeSize(0) {}
	void add(OscillatorType type, int sampleRate, float attackAmplitude, int attackTime, float decayAmplitude, int decayTime, int releaseTime);		
	void clear();
	Oscillator *create(float samplesPerPeriod);
	
	void setAttack(float attackAmplitude);
	void setAttackTime(int attackTime);
	void setDecay(float decayAmplitude);
	void setDecayTime(int decayTime);
private:
	Prototype *mPrototypes[4];
	int mPrototypeSize;
};

#endif

