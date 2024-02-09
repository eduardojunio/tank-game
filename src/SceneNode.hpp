#ifndef TANKGAME_SCENENODE_HPP
#define TANKGAME_SCENENODE_HPP

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
  public:
      typedef std::unique_ptr<SceneNode> Ptr;

      void addChild(Ptr child);
      Ptr removeChild(const SceneNode &child);
      void update(sf::Time dt);
      void processEvent(const sf::Event &event);
  private:
      virtual void processEventCurrent(const sf::Event &event);
      void processEventChildren(const sf::Event &event);
      virtual void updateCurrent(sf::Time dt);
      void updateChildren(sf::Time dt);
      void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
      virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
      void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

      SceneNode *parent;
      std::vector<Ptr> children;
};


#endif//TANKGAME_SCENENODE_HPP
