#include "impl/Empire/EmpireShuttle.hpp"

namespace StarWarsTestTask {

EmpireShuttle::EmpireShuttle(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask

