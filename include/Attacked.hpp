#pragma once

#include "GameWorldObjI.hpp"

namespace StarWarsTestTask {

class Attacker;

class Attacked : virtual public GameWorldObjI {
private:
  std::size_t hp;
  const float dodging;

public:
  explicit Attacked(
    decltype(hp) hp, decltype(dodging) dodging
  ) noexcept;

  std::string defend(std::size_t damage) noexcept;

  bool isDead() const noexcept;

  decltype(hp) getHp() const noexcept;

private:
  bool isDodged() const noexcept;

  void takeDamage(std::size_t damage) noexcept;
};

}  // namespace StarWarsTestTask
