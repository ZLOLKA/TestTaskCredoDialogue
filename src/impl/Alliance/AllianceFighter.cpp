#include "impl/Alliance/AllianceFighter.hpp"

namespace StarWarsTestTask {

AllianceFighter::AllianceFighter(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask

