#include "AbstractSpaceShipFactory.hpp"

#include "impl/BomberI.hpp"
#include "impl/FighterI.hpp"
#include "impl/ScoutI.hpp"
#include "impl/ShuttleI.hpp"
#include "impl/TransportI.hpp"

namespace StarWarsTestTask {

AbstractSpaceShipFactory::AbstractSpaceShipFactory(
  WritterI* const writter
) noexcept : writter(writter) {}

std::unique_ptr<SpaceShipI> AbstractSpaceShipFactory::createSpaceShipByTypename(
  const std::string& spaceShipTypename
  , const SpaceShipCharacteristics& characteristics
) const noexcept(not USE_ASSERT_AS_THROW) {
  if (spaceShipTypename == "Bomber") {
    return createBomber(characteristics);
  } else if (spaceShipTypename == "Fighter") {
    return createFighter(characteristics);
  } else if (spaceShipTypename == "Scout") {
    return createScout(characteristics);
  } else if (spaceShipTypename == "Shuttle") {
    return createShuttle(characteristics);
  } else if (spaceShipTypename == "Transport") {
    return createTransport(characteristics);
  } else {
    ASSERT(false, "Not correct SpaceShipTypename");
    return nullptr;
  }
}

}  // namespace StarWarsTestTask
