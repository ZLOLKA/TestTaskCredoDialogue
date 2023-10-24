#include "impl/Empire/EmpireScout.hpp"

namespace StarWarsTestTask {

EmpireScout::EmpireScout(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask

