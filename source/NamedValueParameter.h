/*
 *  NamedValueParameter.h
 *  Simpleton
 *
 *  Created by Nik Reiman on 2009-07-07.
 *  Copyright 2009 Singbox AB. All rights reserved.
 *
 */

#ifndef __NamedValueParameter_h__
#define __NamedValueParameter_h__

#include <cstdlib>
#include "Parameter.h"

class NamedValueParameter : public Parameter {
public:
  void getDisplay(char *outBuffer) const;
  const float getCurrentValue() const;
  void onChange(const float newValue);
};

#endif