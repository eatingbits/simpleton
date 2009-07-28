#include "NamedValueParameter.h"

using std::string;

NamedValueParameter::NamedValueParameter(const char *name, const char *unit) :
Parameter(name, unit),
mValue(0.0)
{
}

void NamedValueParameter::add(const char *value) {
  mValues.push_back(std::string(value));
}

const int NamedValueParameter::valueToIndex(const float value) const {
  unsigned int index = 0;
  
  // To find the step size, we take the inverse of the number of elements in
  // the values array, and then divide the passed in value by this.  So:
  // (1 / number of elements) = step size
  // value / step size = index
  // We multiply by a large factor to achieve better precision by allowing
  // for integer division rather than with floating point.
  // 0.33 - 4
  // 33 value
  // 25 step
  // 33 / 25 = 1
  int newValue = kMaxNamedValueParameters * value;
  int step = kMaxNamedValueParameters / mValues.size();
  index = newValue / step;
  if(index >= mValues.size()) {
    index = mValues.size() - 1;
  }
  
  return index;
}

void NamedValueParameter::getDisplay(char *outBuffer) const {
  strcpy(outBuffer, mValues.at(valueToIndex(mValue)).c_str());
}

string NamedValueParameter :: selectedValue() const {
	return mValues.at(valueToIndex(mValue));
}

const float NamedValueParameter::getCurrentValue() const {
  return mValue;
}

void NamedValueParameter::onChange(float newValue) {
  mValue = newValue;
}