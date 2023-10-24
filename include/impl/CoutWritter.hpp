#pragma once

#include "WritterI.hpp"

namespace StarWarsTestTask {

class CoutWritter: public virtual WritterI {
public:
  void write(const std::string& msg) const noexcept override;
};

}  // namespace StarWarsTestTask
