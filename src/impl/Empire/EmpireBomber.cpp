#include "impl/Empire/EmpireBomber.hpp"

namespace StarWarsTestTask {

EmpireBomber::EmpireBomber(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask

