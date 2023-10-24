#include "impl/Empire/EmpireFighter.hpp"

namespace StarWarsTestTask {

EmpireFighter::EmpireFighter(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask

