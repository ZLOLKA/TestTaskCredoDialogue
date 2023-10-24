#pragma once

#include "SpaceShipI.hpp"

namespace StarWarsTestTask {

class AllianceSpaceShipI : public virtual SpaceShipI {
public:
  std::string getArmyName() const noexcept override;
  std::string getArmyAbbreviation() const noexcept override;
};

}  // namespace TarWarsTestTask
