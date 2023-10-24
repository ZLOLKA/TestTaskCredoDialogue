#pragma once

#include <string>

namespace StarWarsTestTask {

class WritterI{
public:
  virtual ~WritterI() = default;

  virtual void write(const std::string& msg) const noexcept = 0;
};

}  // namespace StarWarsTestTask
