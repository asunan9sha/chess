#ifndef RPJ_GAMEOBJECT_HPP
#define RPJ_GAMEOBJECT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "utils/types.hpp"

class MasterRenderer;

class GameObject : public sf::RectangleShape {
public:
  GameObject() = default;
  virtual void render(MasterRenderer &renderer) = 0;
  virtual void input(const sf::Event &event) = 0;
  virtual void update(float delta) = 0;
};

#endif
