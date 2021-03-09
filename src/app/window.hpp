#ifndef CHESS_WINDOW_HPP
#define CHESS_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "config.hpp"
#include "utils/singleton.hpp"

class Window : public Singleton {
public:
  static Window &get();
  void initialize(const Config &config);

  void clear();
  void draw(const sf::Drawable &drawable);
  void update();

  inline bool isOpen() const { return window_.isOpen(); }
  inline sf::RenderWindow &raw() { return window_; }

private:
  sf::RenderWindow window_;
};


#endif //CHESS_WINDOW_HPP
