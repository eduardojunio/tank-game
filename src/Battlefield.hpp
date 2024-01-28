#ifndef TANKGAME_BATTLEFIELD_HPP
#define TANKGAME_BATTLEFIELD_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class Battlefield : public sf::Drawable {
  public:
      Battlefield();

  protected:
      void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  private:
      std::vector<sf::FloatRect> map;
      std::vector<sf::RectangleShape> walls;
};


#endif//TANKGAME_BATTLEFIELD_HPP
