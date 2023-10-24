#pragma once

#include "impl/AllianceSpaceShipI.hpp"
#include "impl/ShuttleI.hpp"

namespace StarWarsTestTask {

class AllianceShuttle : virtual public ShuttleI, virtual public AllianceSpaceShipI {
public:
  AllianceShuttle(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
