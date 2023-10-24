#pragma once

#include <string>

namespace StarWarsTestTask {

class WritterI;

class Writes {
private:
  WritterI* const writter;

public:
  Writes(WritterI* const writter) noexcept;

  void write(const std::string& msg) const noexcept;
};

}  // namespace StarWarsTestTask
