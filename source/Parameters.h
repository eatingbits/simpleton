#ifndef __Parameters_h__
#define __Parameters_h__

#include <vector>

#include "Parameter.h"

class Parameters {
public:
  void add(Parameter* parameter);
  const int size() const;
  
  float getParameterValue(int index);
  void getParameterDisplay(int index, char *outBuffer);
  void getParameterName(int index, char *outBuffer);
  void getParameterUnit(int index, char *outBuffer);
  void setParameter(int index, float newValue);
private:
  Parameter* getParameter(int index);
  
  std::vector<Parameter*> mParameters;
};

#endif