#pragma once

#include "DebugTools/ASSERT.hpp"

#include <map>
#include <memory>
#include <string>

namespace StarWarsTestTask {

class SpaceShipCharacteristics;
class WritterI;

class SpaceShipI;

class ShuttleI;
class TransportI;
class ScoutI;
class FighterI;
class BomberI;

class Preset;

class AbstractSpaceShipFactory {
protected:
  WritterI* const writter;

public:
  virtual std::unique_ptr<ShuttleI> createShuttle(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept = 0;

  virtual std::unique_ptr<TransportI> createTransport(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept = 0;

  virtual std::unique_ptr<ScoutI> createScout(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept = 0;

  virtual std::unique_ptr<FighterI> createFighter(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept = 0;

  virtual std::unique_ptr<BomberI> createBomber(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept = 0;

  virtual std::string getArmyName() const noexcept = 0;

public:
  AbstractSpaceShipFactory(WritterI* const writter) noexcept;
  virtual ~AbstractSpaceShipFactory() = default;

  std::unique_ptr<SpaceShipI> createSpaceShipByTypename(
    const std::string& spaceShipTypename
    , const SpaceShipCharacteristics& characteristics
  ) const noexcept(not USE_ASSERT_AS_THROW);
};

}  // namespace StarWarsTestTask
