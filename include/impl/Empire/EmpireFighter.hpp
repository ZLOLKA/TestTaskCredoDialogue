#pragma once

#include "impl/EmpireSpaceShipI.hpp"
#include "impl/FighterI.hpp"

namespace StarWarsTestTask {

class EmpireFighter : virtual public FighterI, virtual public EmpireSpaceShipI {
public:
  EmpireFighter(
    const SpaceShipCharacteristics& characteristics
    , WritterI* const writter
    , std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
