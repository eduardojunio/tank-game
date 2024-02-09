#ifndef TANKGAME_BATTLEFIELD_HPP
#define TANKGAME_BATTLEFIELD_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"

class Battlefield : public SceneNode {
  public:
      Battlefield();

  private:
      void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

      std::vector<sf::FloatRect> map;
      std::vector<sf::RectangleShape> walls;
};


#endif//TANKGAME_BATTLEFIELD_HPP
