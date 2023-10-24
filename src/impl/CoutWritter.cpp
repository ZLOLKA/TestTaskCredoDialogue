#include "impl/CoutWritter.hpp"

#include <iostream>

namespace StarWarsTestTask {

void CoutWritter::write(const std::string& msg) const noexcept {
  std::cout << msg << std::endl;
}

}  // namespace StarWarsTestTask
