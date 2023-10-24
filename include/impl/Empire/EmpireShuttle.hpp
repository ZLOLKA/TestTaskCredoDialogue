#pragma once

#include "impl/EmpireSpaceShipI.hpp"
#include "impl/ShuttleI.hpp"

namespace StarWarsTestTask {

class EmpireShuttle : virtual public ShuttleI, virtual public EmpireSpaceShipI {
public:
  EmpireShuttle(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
