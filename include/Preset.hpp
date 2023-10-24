#pragma once

#include "DebugTools/ASSERT.hpp"
#include "Army.hpp"
#include "SpaceShipCharacteristics.hpp"

#include <filesystem>
#include <map>
#include <memory>
#include <string>

namespace StarWarsTestTask {

class AbstractSpaceShipFactory;
class WritterI;

class Preset {
public:
  constexpr static auto allSpaceShipTypes = {
    "Bomber", "Fighter", "Scout", "Shuttle", "Transport"
  };

  using SpaceShipTypenameT = std::string;

  using ArmyCharacteristicsT 
    = std::map<SpaceShipTypenameT, SpaceShipCharacteristics>;

private:
  WritterI* const writter;

  ArmyCharacteristicsT allianceCharacteristics;
  ArmyCharacteristicsT empireCharacteristics;

public:
  explicit Preset(
    const std::filesystem::path& pathToSettingsFile, WritterI* const writter
  ) noexcept(not USE_ASSERT_AS_THROW);

  Army getAllianceArmy() const noexcept;
  Army getEmpireArmy() const noexcept;

protected:
  Army getArmy(
    decltype(&Preset::empireCharacteristics) characteristicsField
    , std::unique_ptr<AbstractSpaceShipFactory>&& factory
  ) const noexcept(not USE_ASSERT_AS_THROW);
};

}  // namespace StarWarsTestTask
