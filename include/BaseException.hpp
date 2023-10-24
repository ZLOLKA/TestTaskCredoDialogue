#pragma once

namespace StarWarsTestTask {

class BaseException {
public:
  constexpr static bool is_exception = true;

  virtual ~BaseException() noexcept;

  virtual const char* what() const noexcept;
};

}  // namespace StarWarsTestTask
