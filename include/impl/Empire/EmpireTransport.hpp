#pragma once

#include "impl/EmpireSpaceShipI.hpp"
#include "impl/TransportI.hpp"

namespace StarWarsTestTask {

class EmpireTransport : virtual public TransportI, virtual public EmpireSpaceShipI {
public:
  EmpireTransport(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
