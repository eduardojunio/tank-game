#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Battlefield.hpp"
#include "Utils.hpp"

Battlefield::Battlefield()
: walls(),
  map()
{
  map = loadMap();
  for (const auto &wallRect : map) {
    sf::RectangleShape wall(sf::Vector2f(wallRect.width, wallRect.height));
    wall.setFillColor(sf::Color::Black);
    wall.setPosition(wallRect.left, wallRect.top);
    walls.push_back(wall);
  }
}

void Battlefield::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
  for (const auto &wall : walls) {
    target.draw(wall, states);
  }
}
