#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

Game::Game()
: window(sf::VideoMode(1600, 900), "Tank!"),
  tank()
{
  window.setFramerateLimit(120);
}

void Game::run() {
  sf::Clock clock;
  sf::Time accumulator = sf::Time::Zero;

  while (window.isOpen()) {
    sf::Time elapsedTime = clock.restart();
    accumulator += elapsedTime;
    processEvents();
    while (accumulator.asSeconds() >= UPDATE_TIME) {
      update(sf::seconds(UPDATE_TIME));
      accumulator -= sf::seconds(UPDATE_TIME);
    }
    render();
  }
}

void Game::processEvents() {
  sf::Event event{};
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    } else {
      tank.processEvent(event);
    }
  }
}

void Game::update(sf::Time dt) {
  tank.update(dt);
}

void Game::render() {
  window.clear(sf::Color(239, 239, 240));
  window.draw(tank);
  window.display();
}
