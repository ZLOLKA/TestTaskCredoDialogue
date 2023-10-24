#include "Attacker.hpp"

#include "Attacked.hpp"
#include "Tools.hpp"

namespace StarWarsTestTask {

Attacker::Attacker(
  decltype(damage) damage, decltype(accuracy) accuracy
) noexcept : damage(damage), accuracy(accuracy) {}

void Attacker::attack(Attacked* victim) const noexcept {
  std::string msg{
    getArmyName() + ": " + getName() + " shoot at " + victim->getName() + ". Result: "
  };
  if (isHit()) {
    msg += victim->defend(damage);
  } else {
    msg += "miss";
  }
  msg += ", ";
  if (victim->isDead()) {
    msg += "destroyed";
  } else {
    msg += std::to_string(victim->getHp()) + " strength left";
  }
  msg += ".";
  write(msg);
}

bool Attacker::isHit() const noexcept {
  return cmpFloat(accuracy, 1) == 0 
    || cmpFloat(getRandomPercent(), accuracy) < 0;
}

}  // namespace StarWarsTestTask
