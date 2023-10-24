#pragma once

#include "GameWorldObjI.hpp"

namespace StarWarsTestTask {

class Attacked;

class Attacker : virtual public GameWorldObjI {
private:
  const std::size_t damage;
  const float accuracy;

public:
  Attacker(
    decltype(damage) damage, decltype(accuracy) accuracy
  ) noexcept;

  void attack(Attacked* victim) const noexcept;

  decltype(damage) getDamage() const noexcept;

private:
  bool isHit() const noexcept;
};

}  // namespace StarWarsTestTask
