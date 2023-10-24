#include "Army.hpp"

namespace StarWarsTestTask {

Army::Army(const std::string& name) noexcept : name(name) {}

// TODO:
Army::cIt Army::begin() const noexcept {
  return std::cbegin(composition);
}

Army::cIt Army::end() const noexcept {
  return std::cend(composition);
}

void Army::emplace(std::unique_ptr<SpaceShipI>&& spaceShip) noexcept {
  composition.emplace(std::move(spaceShip));
}

Army::It Army::erase(Army::It it) noexcept {
  return composition.erase(it);
}

const std::string& Army::getName() const noexcept {
  return name;
}

bool Army::isDestroed() const noexcept {
  return composition.empty();
}

}  // namespace StarWarsTestTask
