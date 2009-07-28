#ifndef __Parameters_h__
#define __Parameters_h__

#include <map>
#include <string>
#include <vector>

class ParameterCallback;
class ParameterComponent;

class Parameters {
public:
  void add(ParameterComponent *component);
	void addCallback(std::string name, ParameterCallback *callback);
	void addUpdate(std::string name, std::vector<std::string>);
  const int size() const;
  
  float getParameterValue(int index);
  void getParameterDisplay(int index, char *outBuffer);
  void getParameterName(int index, char *outBuffer);
  void getParameterUnit(int index, char *outBuffer);
  void setParameter(int index, float newValue);
private:
  ParameterComponent* getComponent(int index);
	ParameterCallback *getCallback(std::string name);
	int componentsParameterOffset(int index);
  
  std::vector<ParameterComponent *> mComponents;
	std::map<std::string, ParameterCallback *> mCallbacks;
};

#endif