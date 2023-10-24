#include "impl/Alliance/AllianceSpaceShipFactory.hpp"

#include "impl/Alliance/AllianceBomber.hpp"
#include "impl/Alliance/AllianceFighter.hpp"
#include "impl/Alliance/AllianceScout.hpp"
#include "impl/Alliance/AllianceShuttle.hpp"
#include "impl/Alliance/AllianceTransport.hpp"

namespace StarWarsTestTask {

AllianceSpaceShipFactory::AllianceSpaceShipFactory(
  WritterI* const writter
) noexcept : AbstractSpaceShipFactory(writter) {}

std::unique_ptr<ShuttleI> AllianceSpaceShipFactory::createShuttle(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<AllianceShuttle>(characteristics, writter, numberInArmy++);
}

std::unique_ptr<TransportI> AllianceSpaceShipFactory::createTransport(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<AllianceTransport>(characteristics, writter, numberInArmy++);
}

std::unique_ptr<ScoutI> AllianceSpaceShipFactory::createScout(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<AllianceScout>(characteristics, writter, numberInArmy++);
}

std::unique_ptr<FighterI> AllianceSpaceShipFactory::createFighter(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<AllianceFighter>(characteristics, writter, numberInArmy++);
}

std::unique_ptr<BomberI> AllianceSpaceShipFactory::createBomber(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<AllianceBomber>(characteristics, writter, numberInArmy++);
}

std::string AllianceSpaceShipFactory::getArmyName() const noexcept {
  return "Alliance";
}

}  // namespace StarWarsTestTask
