#include "Attacked.hpp"

#include "Tools.hpp"

namespace StarWarsTestTask {

Attacked::Attacked(
  decltype(hp) hp, decltype(dodging) dodging
) noexcept
    : hp(hp), dodging(dodging) {
}
// TODO: :q

std::string Attacked::defend(std::size_t damage) noexcept {
  if (not isDodged()) {
    takeDamage(damage);
    return std::to_string(damage) + " damage";
  } else {
    return "miss";
  }
}

bool Attacked::isDead() const noexcept {
  return hp == 0;
}

decltype(Attacked::hp) Attacked::getHp() const noexcept {
  return hp;
}

bool Attacked::isDodged() const noexcept {
  return cmpFloat(dodging, 1) == 0 || cmpFloat(getRandomPercent(), dodging) < 0;
}

void Attacked::takeDamage(std::size_t damage) noexcept {
  if (damage < hp) {
    hp -= damage;
   } else {
    hp = 0;
   }
}

}  // namespace StarWarsTestTask
