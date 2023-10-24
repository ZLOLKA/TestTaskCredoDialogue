#pragma once

#include "SpaceShipI.hpp"

namespace StarWarsTestTask {

class EmpireSpaceShipI : public virtual SpaceShipI {
public:
  std::string getArmyName() const noexcept override;
  std::string getArmyAbbreviation() const noexcept override;
};

}  // namespace TarWarsTestTask
