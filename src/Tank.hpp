#ifndef TANKGAME_TANK_HPP
#define TANKGAME_TANK_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"

class Tank : public SceneNode {
  public:
      Tank();
  private:
      void processEventCurrent(const sf::Event &event) override;
      void updateCurrent(sf::Time dt) override;
      void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
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
