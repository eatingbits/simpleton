#include "Parameters.h"
#include "ParameterCallback.h"

void Parameters::add(Parameter* parameter) {
  mParameters.push_back(parameter);
}

void Parameters::addCallback(std::string name, ParameterCallback *callback) {
	mCallbacks.insert(make_pair(name, callback));
}

void Parameters::addUpdate(std::string name, std::vector<std::string> names) {
	mUpdates.insert(make_pair(name, names));	
}

const int Parameters::size() const {
  return mParameters.size();
}

Parameter* Parameters::getParameter(int index) {
  return mParameters.at(index);
}

float Parameters::getParameterValue(int index) {
  return getParameter(index)->getCurrentValue();
}

void Parameters::getParameterDisplay(int index, char *outBuffer) {
  return getParameter(index)->getDisplay(outBuffer);
}

void Parameters::getParameterName(int index, char *outBuffer) {
  strcpy(outBuffer, getParameter(index)->getName());
}

void Parameters::getParameterUnit(int index, char *outBuffer) {
  strcpy(outBuffer, getParameter(index)->getUnit());
}

void Parameters::setParameter(int index, float newValue) {
  Parameter *parameter = getParameter(index);
	if (parameter) {
		std::string name = parameter->getName();		
		ParameterCallback *callback = getCallback(name);
		parameter->onChange(newValue, callback);
		update(name);
	}
}

ParameterCallback *Parameters::getCallback(std::string name) {
	std::map<std::string, ParameterCallback *>::iterator it = mCallbacks.find(name);
	if (it != mCallbacks.end()) {
		return it->second;
	}
	return NULL;
}

void Parameters::update(const std::string& name) {
	std::map<std::string, std::vector<std::string> >::iterator it = mUpdates.find(name);
	if (it == mUpdates.end()) {
		return;
	}
	
	std::vector<std::string> namesToUpdate = it->second;
	for (unsigned int i = 0; i < namesToUpdate.size(); i++) {
		updateParameter(namesToUpdate.at(i));
	}
}

void Parameters::updateParameter(const std::string& name) {
	for (unsigned int i = 0; i < mParameters.size(); i++) {
		Parameter *parameter = getParameter(i);
		std::string parameterName = parameter->getName();
		if (parameterName == name) {
			parameter->update(getCallback(parameterName));
		}
	}
}