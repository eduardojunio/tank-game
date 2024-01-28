#ifndef TANKGAME_TANK_HPP
#define TANKGAME_TANK_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class Tank : public sf::Drawable {
  public:
      Tank();

      void processEvent(const sf::Event &event);
      void update(sf::Time dt);
  protected:
      void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  private:
      void updateVelocity();
      void updateRotation();
      bool willCollide(sf::Vector2f movement);

      sf::Texture tankTexture;
      sf::Sprite tank;
      sf::Vector2f velocity;
      float speed;
      bool movingUp;
      bool movingDown;
      bool movingLeft;
      bool movingRight;
      std::vector<sf::FloatRect> map;
};


#endif//TANKGAME_TANK_HPP
