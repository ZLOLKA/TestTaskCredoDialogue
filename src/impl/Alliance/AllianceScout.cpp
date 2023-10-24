#include "impl/Alliance/AllianceScout.hpp"

namespace StarWarsTestTask {

AllianceScout::AllianceScout(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask

