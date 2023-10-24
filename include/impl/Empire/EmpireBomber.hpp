#pragma once

#include "impl/EmpireSpaceShipI.hpp"
#include "impl/BomberI.hpp"

namespace StarWarsTestTask {

class EmpireBomber : virtual public BomberI, virtual public EmpireSpaceShipI {
public:
  EmpireBomber(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
