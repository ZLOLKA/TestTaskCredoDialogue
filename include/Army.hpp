#pragma once

#include "SpaceShipI.hpp"

#include <memory>
#include <string>
#include <unordered_set>

namespace StarWarsTestTask {

class Army {
private:
  std::string name;
  std::unordered_multiset<std::unique_ptr<SpaceShipI>> composition;
  using It = decltype(std::begin(composition));
  using cIt = decltype(std::cbegin(composition));

public:
  explicit Army(const std::string& name) noexcept;
  
  cIt begin() const noexcept;
  cIt end() const noexcept;
  void emplace(std::unique_ptr<SpaceShipI>&& spaceShip) noexcept;
  It erase(It it) noexcept;
  
  const std::string& getName() const noexcept;
  bool isDestroed() const noexcept;
};

}  // namespace StarWarsTestTask
