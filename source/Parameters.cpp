/*
 *  Parameters.cpp
 *  Simpleton
 *
 *  Created by Nik Reiman on 2009-07-07.
 *  Copyright 2009 Singbox AB. All rights reserved.
 *
 */

#include "Parameters.h"

void Parameters::add(Parameter* parameter) {
  mParameters.push_back(parameter);
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
  getParameter(index)->onChange(newValue);
}