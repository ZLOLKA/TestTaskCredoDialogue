#pragma once

#include "impl/AllianceSpaceShipI.hpp"
#include "impl/ScoutI.hpp"

namespace StarWarsTestTask {

class AllianceScout : virtual public ScoutI, virtual public AllianceSpaceShipI {
public:
  AllianceScout(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
