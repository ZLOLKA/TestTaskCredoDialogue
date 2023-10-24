#include "Writes.hpp"

#include "WritterI.hpp"

namespace StarWarsTestTask {

Writes::Writes(WritterI* const writter) noexcept : writter(writter) {}

void Writes::write(const std::string& msg) const noexcept {
  writter->write(msg);
}

}  // namespace StarWarsTestTask
