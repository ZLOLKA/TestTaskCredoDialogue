#include "GameWorld.hpp"

#include "DebugTools/ASSERT.hpp"
#include "Preset.hpp"

#include <unordered_set>

namespace StarWarsTestTask {

GameWorld::GameWorld(WritterI* const writter, const Preset& preset) noexcept 
    : Writes(writter)
    , opponents(preset.getAllianceArmy(), preset.getEmpireArmy()) {
}

void GameWorld::nextTick() noexcept {
  opponents.tick();
  opponents.update();
}

bool GameWorld::isGameEnd() const noexcept {
  return opponents.first.isDestroed() || opponents.second.isDestroed();
}

void GameWorld::writeEndGameInfo() const noexcept(not USE_ASSERT_AS_THROW) {
  const bool firstWin = opponents.second.isDestroed();
  const bool secondWin = opponents.first.isDestroed();
  ASSERT(firstWin || secondWin, "Game not ended");

  write("");
  write("--------------------------------------------------------------------");
  write("");
  if(firstWin && secondWin) {
    write("No winner: everyone's dead");
    return;
  }
  const Army& winner = firstWin ? opponents.first : opponents.second;
  write(winner.getName() + " won.");
  writeSurvivorsFor(winner);
}

void GameWorld::writeSurvivorsFor(const Army& army) const noexcept {
  write("Remaining spaceships:");
  std::unordered_multiset<std::string> typesRemaining;
  for(const auto& type: Preset::allSpaceShipTypes) {
    typesRemaining.emplace(type);
  }
  for(const auto& el: army) {
    typesRemaining.emplace(el->getTypeName());
  }
  for(const auto& type: Preset::allSpaceShipTypes) {
    write(std::string(type) + ": " + std::to_string(typesRemaining.count(type) - 1));
  }
}

}  // namespace StarWarsTestTask
