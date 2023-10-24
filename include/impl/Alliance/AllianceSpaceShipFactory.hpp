#pragma once

#include "AbstractSpaceShipFactory.hpp"

#include <memory>

namespace StarWarsTestTask {

class AllianceSpaceShipFactory : public AbstractSpaceShipFactory {
public:
  AllianceSpaceShipFactory(WritterI* const writter) noexcept;

  std::unique_ptr<ShuttleI> createShuttle(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept override;

  std::unique_ptr<TransportI> createTransport(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept override;

  std::unique_ptr<ScoutI> createScout(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept override;

  std::unique_ptr<FighterI> createFighter(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept override;

  std::unique_ptr<BomberI> createBomber(
    const SpaceShipCharacteristics& characteristics
  ) const noexcept override;

  std::string getArmyName() const noexcept override;
};

}  // namespace StarWarsTestTask
