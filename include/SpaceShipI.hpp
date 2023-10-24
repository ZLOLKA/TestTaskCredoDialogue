#pragma once

#include "Attacked.hpp"
#include "Attacker.hpp"

#include <string>

namespace StarWarsTestTask {

class SpaceShipCharacteristics;

class SpaceShipI
    : public Attacker
    , public Attacked {
private:
  const std::size_t numberInArmy;

public:
  virtual std::string getTypeName() const noexcept = 0;
  virtual std::string getArmyAbbreviation() const noexcept = 0;
  std::string getName() const noexcept override;

public:
  std::size_t getNumberInArmy() const noexcept;

  virtual ~SpaceShipI() = default;

protected:
  SpaceShipI(
    const SpaceShipCharacteristics& characteristics, std::size_t numberInArmy
  ) noexcept;
};

}  // namespace StarWarsTestTask
