#include "SpaceShipCharacteristics.hpp"

namespace StarWarsTestTask {

SpaceShipCharacteristics::SpaceShipCharacteristics(
  std::size_t countInArmy
  , std::size_t damage
  , float accuracy
  , std::size_t startHP
  , float dodging
) noexcept
    : countInArmy(countInArmy)
    , damage(damage)
    , accuracy(accuracy)
    , startHP(startHP)
    , dodging(dodging) {}

decltype(SpaceShipCharacteristics::countInArmy)
SpaceShipCharacteristics::getCountInArmy() const noexcept {
  return countInArmy;
}

decltype(SpaceShipCharacteristics::damage)
SpaceShipCharacteristics::getDamage() const noexcept {
  return damage;
}

decltype(SpaceShipCharacteristics::accuracy)
SpaceShipCharacteristics::getAccuracy() const noexcept {
  return accuracy;
}

decltype(SpaceShipCharacteristics::startHP)
SpaceShipCharacteristics::getStartHP() const noexcept {
  return startHP;
}

decltype(SpaceShipCharacteristics::dodging)
SpaceShipCharacteristics::getDodging() const noexcept {
  return dodging;
}

}  // namespace StarWarsTestTask
