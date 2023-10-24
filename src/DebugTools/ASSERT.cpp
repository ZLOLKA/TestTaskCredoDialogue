#include "DebugTools/ASSERT.hpp"

namespace StarWarsTestTask {

AssertException::AssertException(const std::string& what_msg
) noexcept : what_msg(what_msg) {};

AssertException::AssertException() noexcept : what_msg("") {};

AssertException::operator bool() const noexcept {
  return false;
}

const char* AssertException::what() const noexcept {
  return what_msg.c_str();
}

}  // namespace StarWarsTestTask
