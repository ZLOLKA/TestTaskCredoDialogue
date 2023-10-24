#include "BaseException.hpp"

namespace StarWarsTestTask {

BaseException::~BaseException() noexcept = default;

const char* BaseException::what() const noexcept {
  return "Unknown exception from StarWarsTestTask";
}

}  // namespace StarWarsTestTask
