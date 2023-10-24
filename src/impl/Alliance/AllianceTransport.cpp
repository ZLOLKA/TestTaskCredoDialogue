#include "impl/Alliance/AllianceTransport.hpp"

namespace StarWarsTestTask {

AllianceTransport::AllianceTransport(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask

