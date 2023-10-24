#include "impl/FstreamWritter.hpp"

#include <fstream>

namespace StarWarsTestTask {

FstreamWritter::FstreamWritter(const std::filesystem::path& pathToOutFile) noexcept 
    : pathToOutFile(pathToOutFile) {}

FstreamWritter::~FstreamWritter() = default;

void FstreamWritter::write(const std::string& msg) const noexcept {
  std::ofstream fstream(pathToOutFile, std::ios::app);
  fstream << msg << std::endl;
}

}  // namespace StarWarsTestTask
