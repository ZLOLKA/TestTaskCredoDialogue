#include "SpaceShipI.hpp"

#include "SpaceShipCharacteristics.hpp"

namespace StarWarsTestTask {
SpaceShipI::SpaceShipI(
  const SpaceShipCharacteristics& characteristics, std::size_t numberInArmy
) noexcept 
    : Attacker(characteristics.getDamage(), characteristics.getAccuracy())
    , Attacked(characteristics.getStartHP(), characteristics.getDodging())
    , numberInArmy(numberInArmy) {}

std::size_t SpaceShipI::getNumberInArmy() const noexcept {
  return numberInArmy;
}

std::string SpaceShipI::getName() const noexcept {
  return getTypeName() + "-" + getArmyAbbreviation()
    + std::to_string(getNumberInArmy());
}

}  // namespace StarWarsTestTask
