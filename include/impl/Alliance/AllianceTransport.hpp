#pragma once

#include "impl/AllianceSpaceShipI.hpp"
#include "impl/TransportI.hpp"

namespace StarWarsTestTask {

class SpaceShipCharacteristics;

class AllianceTransport : virtual public TransportI, virtual public AllianceSpaceShipI {
public:
  AllianceTransport(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
