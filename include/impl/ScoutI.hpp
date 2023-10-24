#pragma once

#include "SpaceShipI.hpp"

namespace StarWarsTestTask {

class ScoutI : virtual public SpaceShipI {
public:
  std::string getTypeName() const noexcept override;
};

}  // namespace StarWarsTestTask
