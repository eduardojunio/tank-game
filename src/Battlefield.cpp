#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Battlefield.hpp"
#include "Utils.hpp"

Battlefield::Battlefield()
: walls()
{
  if (!map.loadFromFile("../../resources/map01.png"))
    throw std::runtime_error("Unable to load map01.png!");

  int wallSize = 8 * 5;

  sf::Vector2u size = map.getSize();
  for (unsigned y = 0; y < size.y; ++y) {
    for (unsigned x = 0; x < size.x; ++x) {
      sf::Color color = map.getPixel(x, y);
      if (color == sf::Color::Black) {
        sf::RectangleShape wall(sf::Vector2f(wallSize, wallSize));
        wall.setFillColor(sf::Color::Black);
        wall.setPosition(x * wallSize, y * wallSize);
        walls.push_back(wall);
      }
    }
  }
}

void Battlefield::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for (const auto &wall : walls) {
    target.draw(wall);
  }
}
