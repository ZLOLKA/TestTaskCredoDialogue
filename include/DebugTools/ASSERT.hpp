#pragma once

#include "BaseException.hpp"

#include <iostream>
#include <string>

namespace StarWarsTestTask {

class AssertException : public BaseException {
private:
  std::string what_msg;

public:
  explicit AssertException(const std::string& what_msg) noexcept;

  AssertException() noexcept;
  operator bool() const noexcept;

  const char* what() const noexcept override;
};

}  // namespace StarWarsTestTask

#ifndef NDEBUG
  #include <cassert>
  #if USE_ASSERT_AS_THROW
    #define ASSERT(cond, msg) \
      if (not (cond)) \
      throw ::StarWarsTestTask::AssertException( \
          std::string("\nASSERT from StarWarsTestTask: " __FILE__ " ") \
          + std::to_string(__LINE__) + ":" + "\n(" + #cond \
          + ") is false: " + (msg) \
      )
  #else
    #define ASSERT(cond, msg) assert(std::string(msg).data() && (cond))
  #endif
#else
  #include <cstdlib>
  #define ASSERT(cond, msg) std::abort()
#endif

#if not defined(NDEBUG) and USE_ASSERT_AS_THROW
  #define ASSERT_AS_THROW_BEGIN try
  #define ASSERT_AS_THROW_END \
    catch (::StarWarsTestTask::AssertException e) { \
      std::cerr << e.what() << std::endl; \
      assert(::StarWarsTestTask::AssertException()); \
      return 1; \
    }
#else
  #define ASSERT_AS_THROW_BEGIN
  #define ASSERT_AS_THROW_END
#endif
