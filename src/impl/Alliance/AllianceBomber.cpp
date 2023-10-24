#include "impl/Alliance/AllianceBomber.hpp"

namespace StarWarsTestTask {

AllianceBomber::AllianceBomber(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask
