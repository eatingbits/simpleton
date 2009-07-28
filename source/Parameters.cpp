#include "Parameters.h"
#include "ParameterComponent.h"

void Parameters::add(ParameterComponent *component) {
	mComponents.push_back(component);
}

void Parameters::addCallback(std::string name, ParameterCallback *callback) {
	mCallbacks.insert(make_pair(name, callback));
}

const int Parameters::size() const {
	int size = 0;
	for (unsigned int i = 0; i < mComponents.size(); i++) {
		size += mComponents[i]->numberOfParameters();
	}
	return size;
}

ParameterComponent* Parameters::getComponent(int index) {
	int current = 0;
	for (unsigned int i = 0; i < mComponents.size(); ++i) {
		current += mComponents[i]->numberOfParameters();
		if (index < current) {
			return mComponents[i];
		}
	}
  return NULL;
}

int Parameters :: componentsParameterOffset(int index) {
	int current = 0;
	for (unsigned int i = 0; i < mComponents.size(); ++i) {
		int next = current + mComponents[i]->numberOfParameters();
		if (index < next) {
			return index - current;
		}
		current = next;
	}
	return 0;
}

float Parameters::getParameterValue(int index) {
  return getComponent(index)->getCurrentValue(componentsParameterOffset(index));
}

void Parameters::getParameterDisplay(int index, char *outBuffer) {
  return getComponent(index)->getDisplay(componentsParameterOffset(index), outBuffer);
}

void Parameters::getParameterName(int index, char *outBuffer) {
  strcpy(outBuffer, getComponent(index)->getName(componentsParameterOffset(index)));
}

void Parameters::getParameterUnit(int index, char *outBuffer) {
  strcpy(outBuffer, getComponent(index)->getUnit(componentsParameterOffset(index)));
}

void Parameters::setParameter(int index, float newValue) {
  ParameterComponent *component = getComponent(index);
	if (component) {
		std::string name = component->getName(componentsParameterOffset(index));		
		component->onChange(componentsParameterOffset(index), newValue);
	}
}

ParameterCallback *Parameters::getCallback(std::string name) {
	std::map<std::string, ParameterCallback *>::iterator it = mCallbacks.find(name);
	if (it != mCallbacks.end()) {
		return it->second;
	}
	return NULL;
}
