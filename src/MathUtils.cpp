#include <cmath>
#include "MathUtils.hpp"

sf::Vector2f getUnitVector(const sf::Vector2f &vector) {
  float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

  if (magnitude != 0.f) {
    return { vector.x / magnitude, vector.y / magnitude };
  } else {
    return { 0, 0 };
  }
}
