#include "Oscillator.h"

class SilenceOscillator : public Oscillator {
public:
	SilenceOscillator();
	/* Silence is always 0 */
	float nextSampleValue() { return 0.0; }
	/* Silence doesn't need a previous value, so just terminate the chain */
	float inputValue() { return 0.0; }
private:
};
