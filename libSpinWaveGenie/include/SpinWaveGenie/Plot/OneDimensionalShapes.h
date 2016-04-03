//
//  OneDimensionalShapes.h
//  spin_wave_genie
//
//  Created by Hahn, Steven E. on 2/5/14.
//
//

#ifndef __OneDimensionalShapes__
#define __OneDimensionalShapes__

#include <iostream>
#include "SpinWaveGenie/Memory.h"

namespace SpinWaveGenie
{

/* Abstract base class */
class OneDimensionalShapes
{
public:
  virtual void setTolerance(double InTolerance) = 0;
  virtual double getMinimumEnergy() = 0;
  virtual double getMaximumEnergy() = 0;
  virtual double getFunction(double frequency, double energy) = 0;
  virtual std::unique_ptr<OneDimensionalShapes> clone() = 0;
  virtual ~OneDimensionalShapes() = default;
};
}
#endif /* defined(__OneDimensionalShapes__) */
