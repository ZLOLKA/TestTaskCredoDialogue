#pragma once

#include "Writes.hpp"

#include <string>

namespace StarWarsTestTask {

class GameWorldObjI : public Writes {
public:
  explicit GameWorldObjI(WritterI* const writter) noexcept;

  virtual std::string getName() const noexcept = 0;
  virtual std::string getArmyName() const noexcept = 0;
};

}  // namespace StarWarsTestTask
