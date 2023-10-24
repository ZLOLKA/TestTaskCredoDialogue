#include "DebugTools/ASSERT.hpp"
#include "GameWorld.hpp"
#include "impl/FstreamWritter.hpp"
#include "Preset.hpp"

#include <ctime>
#include <memory>

int main() ASSERT_AS_THROW_BEGIN {
  std::srand(std::time(nullptr));
  const auto logger = std::make_unique<StarWarsTestTask::FstreamWritter>("./output.txt");

  const StarWarsTestTask::Preset preset{"./settings.json", logger.get()};
  StarWarsTestTask::GameWorld gameWorld{logger.get(), preset};

  while (not gameWorld.isGameEnd()) {
    gameWorld.nextTick();
  }
  gameWorld.writeEndGameInfo();
  return 0;
} ASSERT_AS_THROW_END
