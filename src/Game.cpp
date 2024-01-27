#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

Game::Game()
: window(sf::VideoMode(1600, 900), "Tank!"),
  tankTexture(),
  tank()
{
  window.setFramerateLimit(60);
}

void Game::run() {
  sf::Clock clock;
  sf::Time accumulator = sf::Time::Zero;

  if (!tankTexture.loadFromFile("../../resources/tank.png")) {
    std::cerr << "Unable to load the tank texture!" << std::endl;
  }
  tank.setTexture(tankTexture);
  tank.setPosition(400, 400);

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
    }
  }
}

void Game::update(sf::Time dt) {}

void Game::render() {
  window.clear(sf::Color(239, 239, 240));
  window.draw(tank);
  window.display();
}
