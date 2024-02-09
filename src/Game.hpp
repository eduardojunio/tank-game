#ifndef TANKGAME_GAME_HPP
#define TANKGAME_GAME_HPP

#include <SFML/Graphics.hpp>
#include "Tank.hpp"
#include "Battlefield.hpp"

class Game {
  public:
      static constexpr double UPDATE_TIME = 1. / 120; // in seconds

      Game();

      void run();
  private:
      void processEvents();
      void update(sf::Time dt);
      void render();

      sf::RenderWindow window;
      Battlefield battlefield;
};


#endif//TANKGAME_GAME_HPP
