#include "impl/Empire/EmpireSpaceShipFactory.hpp"

#include "impl/Empire/EmpireBomber.hpp"
#include "impl/Empire/EmpireFighter.hpp"
#include "impl/Empire/EmpireScout.hpp"
#include "impl/Empire/EmpireShuttle.hpp"
#include "impl/Empire/EmpireTransport.hpp"

namespace StarWarsTestTask {

EmpireSpaceShipFactory::EmpireSpaceShipFactory(
  WritterI* const writter
) noexcept : AbstractSpaceShipFactory(writter) {}

std::unique_ptr<ShuttleI> EmpireSpaceShipFactory::createShuttle(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<EmpireShuttle>(characteristics, writter, numberInArmy++);
}

std::unique_ptr<TransportI> EmpireSpaceShipFactory::createTransport(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<EmpireTransport>(characteristics, writter, numberInArmy++);
}

std::unique_ptr<ScoutI> EmpireSpaceShipFactory::createScout(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<EmpireScout>(characteristics, writter, numberInArmy++);
}

std::unique_ptr<FighterI> EmpireSpaceShipFactory::createFighter(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<EmpireFighter>(characteristics, writter, numberInArmy++);
}

std::unique_ptr<BomberI> EmpireSpaceShipFactory::createBomber(
  const SpaceShipCharacteristics& characteristics
) const noexcept {
  using namespace std::string_literals;
  static std::size_t numberInArmy = 0;

  return std::make_unique<EmpireBomber>(characteristics, writter, numberInArmy++);
}

std::string EmpireSpaceShipFactory::getArmyName() const noexcept {
  return "Empire";
}

}  // namespace StarWarsTestTask
