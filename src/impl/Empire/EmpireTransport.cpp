#include "impl/Empire/EmpireTransport.hpp"

namespace StarWarsTestTask {

EmpireTransport::EmpireTransport(
  const SpaceShipCharacteristics& characteristics
  , WritterI* const writter
  , std::size_t numberInArmy
) noexcept : GameWorldObjI(writter), SpaceShipI(characteristics, numberInArmy) {}

}  // namespace StarWarsTestTask

