/*
 *  FloatValueParameter.cpp
 *  Simpleton
 *
 *  Created by Nik Reiman on 2009-07-07.
 *  Copyright 2009 Singbox AB. All rights reserved.
 *
 */

#include "FloatValueParameter.h"

FloatValueParameter::FloatValueParameter(const char *name, const char *unit,
                                         const float lowValue, const float hiValue) :
Parameter(name, unit),
mLowValue(lowValue),
mHiValue(hiValue),
mValue(0.0f)
{
}

void FloatValueParameter::getDisplay(char *outBuffer) const {
  sprintf(outBuffer, "%3.2f", mValue);
}

const float FloatValueParameter::getCurrentValue() const {
  return mValue;
}

void FloatValueParameter::onChange(const float newValue) {
  mValue = newValue * (mHiValue - mLowValue) + mLowValue;
}