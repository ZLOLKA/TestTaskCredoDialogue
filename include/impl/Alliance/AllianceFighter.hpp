#pragma once

#include "impl/AllianceSpaceShipI.hpp"
#include "impl/FighterI.hpp"

namespace StarWarsTestTask {

class AllianceFighter : virtual public FighterI, virtual public AllianceSpaceShipI {
public:
  AllianceFighter(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
