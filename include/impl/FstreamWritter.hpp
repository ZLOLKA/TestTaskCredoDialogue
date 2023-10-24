#pragma once

#include "WritterI.hpp"

#include <filesystem>
#include <string>

namespace StarWarsTestTask {

class FstreamWritter : public virtual WritterI {
private:
  const std::filesystem::path pathToOutFile;

public:
  explicit FstreamWritter(const std::filesystem::path& pathToOutFile) noexcept;
  virtual ~FstreamWritter();

  void write(const std::string& msg) const noexcept override;
};

}  // namespace StarWarsTestTask
