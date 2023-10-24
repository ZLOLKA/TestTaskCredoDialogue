#include "impl/Alliance/AllianceShuttle.hpp"

namespace StarWarsTestTask {

AllianceShuttle::AllianceShuttle(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask
