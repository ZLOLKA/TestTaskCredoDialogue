#pragma once

#include "impl/AllianceSpaceShipI.hpp"
#include "impl/BomberI.hpp"

namespace StarWarsTestTask {

class AllianceBomber : virtual public BomberI, virtual public AllianceSpaceShipI {
public:
  AllianceBomber(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
