#include "ChorusFactory.h"

#include "Source.h"
#include "Joiner.h"
#include "Splitter.h"
#include "Chorus.h"

Source *ChorusFactory :: create(int nrOfVoices, int delay, Source& source) {
	Splitter *splitter = new Splitter(nrOfVoices + 1, source);
	Joiner *joiner = new Joiner();
	int currentDelay = 0;
	for (int i = 0; i < nrOfVoices + 1; i++) {
		joiner->addSource(new Chorus(currentDelay, *splitter));
		currentDelay += delay; 
	}
	return joiner;
}