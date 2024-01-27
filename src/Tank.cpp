#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Tank.hpp"
#include "MathUtils.hpp"

Tank::Tank()
: tankTexture(),
  tank(),
  velocity(0, 0),
  speed(250),
  movingUp(false),
  movingDown(false),
  movingLeft(false),
  movingRight(false)
{
  if (!tankTexture.loadFromFile("../../resources/tank.png")) {
    throw std::runtime_error("Unable to load the tank texture!");
  }
  tank.setTexture(tankTexture);
  tank.setPosition(400, 400);
}

void Tank::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(tank);
}

void Tank::processEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.scancode) {
      case sf::Keyboard::Scan::Up:
        movingUp = true;
        break;
      case sf::Keyboard::Scan::Down:
        movingDown = true;
        break;
      case sf::Keyboard::Scan::Left:
        movingLeft = true;
        break;
      case sf::Keyboard::Scan::Right:
        movingRight = true;
        break;
    }
  }

  if (event.type == sf::Event::KeyReleased) {
    switch (event.key.scancode) {
      case sf::Keyboard::Scan::Up:
        movingUp = false;
        break;
      case sf::Keyboard::Scan::Down:
        movingDown = false;
        break;
      case sf::Keyboard::Scan::Left:
        movingLeft = false;
        break;
      case sf::Keyboard::Scan::Right:
        movingRight = false;
        break;
    }
  }

  updateVelocity();
}

void Tank::update(sf::Time dt) {
  tank.move(velocity * speed * dt.asSeconds());
}

void Tank::updateVelocity() {
  sf::Vector2f newVelocity(0, 0);
  if (movingUp) {
    newVelocity += sf::Vector2f(0, -1);
  }
  if (movingDown) {
    newVelocity += sf::Vector2f(0, 1);
  }
  if (movingLeft) {
    newVelocity += sf::Vector2f(-1, 0);
  }
  if (movingRight) {
    newVelocity += sf::Vector2f(1, 0);
  }
  velocity = getUnitVector(newVelocity);
}
