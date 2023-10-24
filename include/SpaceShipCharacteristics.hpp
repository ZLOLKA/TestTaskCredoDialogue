#pragma once

#include <string>

namespace StarWarsTestTask {

class SpaceShipCharacteristics {
private:
  const std::size_t countInArmy;
  const std::size_t damage;
  const float accuracy;
  const std::size_t startHP;
  const float dodging;

public:
  SpaceShipCharacteristics(
    std::size_t countInArmy
    , std::size_t damage
    , float accuracy
    , std::size_t startHP
    , float dodging
  ) noexcept;

  decltype(countInArmy) getCountInArmy() const noexcept;
  decltype(damage) getDamage() const noexcept;
  decltype(accuracy) getAccuracy() const noexcept;
  decltype(startHP) getStartHP() const noexcept;
  decltype(dodging) getDodging() const noexcept;
};

}  // namespace StarWarsTestTask
