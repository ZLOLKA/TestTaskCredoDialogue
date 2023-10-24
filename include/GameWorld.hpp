#pragma once

#include "Writes.hpp"
#include "Opponents.hpp"

namespace StarWarsTestTask {

class Preset;
class WritterI;

class GameWorld : public Writes {
private:
  Opponents opponents;

public:
  explicit GameWorld(WritterI* const writter, const Preset& preset) noexcept;

  void nextTick() noexcept;
  bool isGameEnd() const noexcept;

  void writeEndGameInfo() const noexcept(not USE_ASSERT_AS_THROW);

protected:
  void writeSurvivorsFor(const Army& army) const noexcept;
};

}  // namespace StarWarsTestTask
