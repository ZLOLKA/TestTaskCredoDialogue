#pragma once

#include "SpaceShipI.hpp"

namespace StarWarsTestTask {

class ShuttleI : public virtual SpaceShipI {
public:
  std::string getTypeName() const noexcept override;
};

}  // namespace StarWarsTestTask
