#pragma once

#include "impl/EmpireSpaceShipI.hpp"
#include "impl/ScoutI.hpp"

namespace StarWarsTestTask {

class EmpireScout : virtual public ScoutI, virtual public EmpireSpaceShipI {
public:
  EmpireScout(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
