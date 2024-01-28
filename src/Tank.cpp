#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Tank.hpp"
#include "MathUtils.hpp"
#include "Utils.hpp"

Tank::Tank()
: tankTexture(),
  tank(),
  velocity(0, 0),
  speed(100),
  movingUp(false),
  movingDown(false),
  movingLeft(false),
  movingRight(false)
{
  map = loadMap();
  if (!tankTexture.loadFromFile("../../resources/tank.png")) {
    throw std::runtime_error("Unable to load the tank texture!");
  }
  tank.setTexture(tankTexture);
  tank.setPosition(100, 400);
  sf::FloatRect localBounds = tank.getLocalBounds();
  tank.setOrigin(localBounds.width / 2, localBounds.height / 2);
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
  updateRotation();
}

void Tank::update(sf::Time dt) {
  sf::Vector2f movement = velocity * speed * dt.asSeconds();
  if (!willCollide(movement)) {
    tank.move(movement);
  }
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

void Tank::updateRotation() {
  if (movingUp) {
    tank.setRotation(0);
  }
  if (movingRight) {
    tank.setRotation(90);
  }
  if (movingDown) {
    tank.setRotation(180);
  }
  if (movingLeft) {
    tank.setRotation(270);
  }
  if (movingUp && movingRight) {
    tank.setRotation(45);
  }
  if (movingDown && movingRight) {
    tank.setRotation(135);
  }
  if (movingDown && movingLeft) {
    tank.setRotation(225);
  }
  if (movingUp && movingLeft) {
    tank.setRotation(315);
  }
}

bool Tank::willCollide(sf::Vector2f movement) {
  sf::FloatRect bounds = tank.getGlobalBounds();
  bounds.left += movement.x;
  bounds.top += movement.y;
  bool result = false;
  for (const auto &wallRect : map) {
    result = result || wallRect.intersects(bounds);
  }
  return result;
}
