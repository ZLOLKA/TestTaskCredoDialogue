#include "Tools.hpp"

namespace StarWarsTestTask {

float getRandomPercent() noexcept {
  return (std::rand() % 100) / 100.0;
}

int cmpDbl(double a, double b) noexcept {
  constexpr auto eps = 1 / 1000000;
  if(fabs(a - b) <= eps) {
    return 0;
  }
  return a > b ? 1 : -1;
}

int cmpFloat(float a, float b) noexcept {
  constexpr auto eps = 1 / 1000000;
  if(fabs(a - b) <= eps) {
    return 0;
  }
  return a > b ? 1 : -1;
}

}  // namespace StarWarsTestTask
