#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Tank Game");
  window.setFramerateLimit(60);

  sf::CircleShape circleShape(50.f);
  circleShape.setFillColor(sf::Color::White);

  while (window.isOpen()) {
    // process events
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // render
    window.clear(sf::Color::Black);
    window.draw(circleShape);
    window.display();
  }

  return 0;
}
