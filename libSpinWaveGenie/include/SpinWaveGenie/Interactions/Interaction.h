#ifndef __Interaction_H__
#define __Interaction_H__ 1

#include "SpinWaveGenie/Containers/Cell.h"
#include "SpinWaveGenie/Export.h"
#include <Eigen/Dense>
#include <array>
#include <memory>
#include <string>

//! Base class for all classes describing magnetic interactions

namespace SpinWaveGenie
{

class Neighbors;

class SPINWAVEGENIE_EXPORT Interaction
{
public:
  virtual std::array<std::string, 2> sublattices() const = 0;
  bool operator<(const Interaction &other) const;
  //! Calculate the classical energy associated with a given Cell.
  virtual void calculateEnergy(const Cell &cell, double &energy) = 0;
  virtual void calcConstantValues(const Cell &cell) = 0;
  virtual void calculateFirstOrderTerms(const Cell &cell, Eigen::VectorXcd &elements) = 0;
  //! virtual method for adding terms to the matrix LN
  //! \param K reciprocal lattice point currently being simulated.
  //! \param cell pointer to Cell object containing magnetic ground state information
  //! \param LN matrix used to calculate spin wave frequencies and intensities
  virtual const std::string &getName() const = 0;
  virtual void updateValue(double value) = 0;
  virtual void updateMatrix(const Eigen::Vector3d &K, Eigen::MatrixXcd &LN) const = 0;
  virtual std::unique_ptr<Interaction> clone() const = 0;
  virtual ~Interaction() = default;

private:
};

}

#endif // __Interaction_H__
