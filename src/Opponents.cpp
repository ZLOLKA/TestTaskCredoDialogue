#include "Opponents.hpp"

#include "Tools.hpp"

namespace StarWarsTestTask {

Opponents::Opponents(decltype(first)&& firstArmy, decltype(second)&& secondArmy) noexcept
: Opponents::BaseType(std::move(firstArmy), std::move(secondArmy)) {

}

void Opponents::tick() noexcept {
  tickFor(&Opponents::first, &Opponents::second);
  tickFor(&Opponents::second, &Opponents::first);
}

void Opponents::tickFor(
  decltype(&Opponents::first) firstArmyField
  , decltype(&Opponents::second) secondArmyField
) noexcept {
  auto& _first = this->*firstArmyField;
  auto& _second = this->*secondArmyField;

  auto& firstEl = *getRandomElFrom(_first.begin(), _first.end());
  auto& secondEl = *getRandomElFrom(_second.begin(), _second.end());
  firstEl->attack(secondEl.get());
  forUpdate.emplace(&secondEl);
}

void Opponents::update() noexcept {
  updateArmy(first);
  updateArmy(second);
}

void Opponents::updateArmy(decltype(Opponents::first)& army) noexcept {
  for(auto it{army.begin()}, end{army.end()}; it != end; ) {
    auto& el = *it;
    if(forUpdate.erase(&el) && el->isDead()) {
      it = army.erase(it);
    } else {
      ++it;
    }
  }
}

}  // namespace StarWarsTestTask
