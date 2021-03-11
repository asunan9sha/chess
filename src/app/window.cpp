#include "window.hpp"

Window &Window::get() {
  static Window window;
  return window;
}

void Window::initialize(const Config &config) {
  window_.create(sf::VideoMode(config.width, config.height), config.title,sf::Style::Close);
  window_.setVerticalSyncEnabled(config.vSync);
  window_.setKeyRepeatEnabled(false);
  window_.setFramerateLimit(config.frameLimit);

}

void Window::clear() {
  window_.clear();
}

void Window::draw(const sf::Drawable &drawable) {
  window_.draw(drawable);
}

void Window::update() {
  window_.display();
}