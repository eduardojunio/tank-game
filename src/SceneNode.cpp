#include <utility>
#include <algorithm>
#include <stdexcept>
#include "SceneNode.hpp"

void SceneNode::addChild(SceneNode::Ptr child) {
  child->parent = this;
  children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::removeChild(const SceneNode& child) {
  auto found = std::find_if(children.begin(), children.end(), [&](SceneNode::Ptr &ptr) { return ptr.get() == &child; });
  if (found == children.end()) {
    throw std::logic_error("Could not find the child to remove");
  }
  return std::move(*found);
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  drawCurrent(target, states);
  drawChildren(target, states);
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const {
  for (const SceneNode::Ptr &child : children) {
    child->draw(target, states);
  }
}

void SceneNode::update(sf::Time dt) {
  updateCurrent(dt);
  updateChildren(dt);
}

void SceneNode::updateChildren(sf::Time dt) {
  for (const auto &child : children) {
    child->update(dt);
  }
}

void SceneNode::updateCurrent(sf::Time dt) {}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {}

void SceneNode::processEvent(const sf::Event& event) {
  processEventCurrent(event);
  processEventChildren(event);
}

void SceneNode::processEventChildren(const sf::Event& event) {
  for (const auto &child : children) {
    child->processEvent(event);
  }
}

void SceneNode::processEventCurrent(const sf::Event& event) {}
