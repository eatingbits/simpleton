#ifndef __Parameters_h__
#define __Parameters_h__

#include <map>
#include <string>
#include <vector>

#include "Parameter.h"

class ParameterCallback;

class Parameters {
public:
  void add(Parameter* parameter);
	void addCallback(std::string name, ParameterCallback *callback);
	void addUpdate(std::string name, std::vector<std::string>);
  const int size() const;
  
  float getParameterValue(int index);
  void getParameterDisplay(int index, char *outBuffer);
  void getParameterName(int index, char *outBuffer);
  void getParameterUnit(int index, char *outBuffer);
  void setParameter(int index, float newValue);
private:
  Parameter* getParameter(int index);
	ParameterCallback *getCallback(std::string name);
	void update(const std::string& name);
	void updateParameter(const std::string& name);
  
  std::vector<Parameter*> mParameters;
	std::map<std::string, ParameterCallback *> mCallbacks;
	std::map<std::string, std::vector<std::string> > mUpdates;
};

#endif