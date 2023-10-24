#pragma once

#include <cstdlib>
#include <iterator>

namespace StarWarsTestTask {

float getRandomPercent() noexcept;

int cmpDbl(double a, double b) noexcept;
int cmpFloat(float a, float b) noexcept;

template<class It>
It getRandomElFrom(It begin, It end) noexcept {
  auto dist = std::distance(begin, end);
  if (dist <= 1) {
    return begin;
  }
  return std::next(begin, std::rand() % dist);
}

}  // namespace StarWarsTestTask
