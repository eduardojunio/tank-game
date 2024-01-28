#include <vector>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

std::vector<sf::FloatRect> loadMap() {
  sf::Image map;
  if (!map.loadFromFile("../../resources/map01.png"))
    throw std::runtime_error("Unable to load map01.png!");

  int wallSize = 8 * 5;

  std::vector<sf::FloatRect> result;

  sf::Vector2u size = map.getSize();
  for (unsigned y = 0; y < size.y; ++y) {
    for (unsigned x = 0; x < size.x; ++x) {
      sf::Color color = map.getPixel(x, y);
      if (color == sf::Color::Black) {
        result.emplace_back(x * wallSize, y * wallSize, wallSize, wallSize);
      }
    }
  }

  return result;
}
