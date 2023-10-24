#pragma once

#include "Army.hpp"

#include <set>
#include <utility>

namespace StarWarsTestTask {

class Opponents : public std::pair<Army, Army> {
  static_assert(std::is_same_v<decltype(first), decltype(second)>);

public:
  using BaseType = std::pair<Army, Army>;

private:
  std::set<decltype(&*std::begin(first))> forUpdate;

public:
  Opponents(decltype(first)&& firstArmy, decltype(second)&& secondArmy) noexcept;

  void tick() noexcept;
  void update() noexcept;

protected:
  void tickFor(
    decltype(&Opponents::first) firstArmyField
    , decltype(&Opponents::second) secondArmyField
  ) noexcept;

  void updateArmy(decltype(first)& army) noexcept;
};
static_assert(std::is_base_of_v<Opponents::BaseType, Opponents>);

}  // namespace StarWarsTestTask
