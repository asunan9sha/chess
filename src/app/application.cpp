#include <SFML/Window/Event.hpp>
#include <resources/resourceholder.hpp>
#include <iostream>

#include "application.hpp"
#include "states/gamestate.hpp"

Application *Application::app_ = nullptr;

Application::Application(const Config &config) : shouldPop(false) {
  window_ = &Window::get();
  window_->initialize(config);

  app_ = this;

  push<GameState>(this);
}

void Application::run() {
  const sf::Time MS_PER_TICK = sf::seconds(1.0f / config_.tps);

  unsigned fps = 0;
  unsigned tickCount = 0;
  float second = 0;

  sf::Clock timer;

  sf::Time lastTime = timer.getElapsedTime();
  sf::Time tickLag = sf::Time::Zero;

  while (window_->isOpen()) {
    sf::Time currentTime = timer.getElapsedTime();
    sf::Time elapsed = currentTime - lastTime;
    lastTime = currentTime;
    tickLag += elapsed;

    while (tickLag >= MS_PER_TICK) {
      ++tickCount;
      current->fixedUpdate(MS_PER_TICK.asSeconds());
      tickLag -= MS_PER_TICK;
    }

    current->update(elapsed.asSeconds());
    current->input(elapsed.asSeconds());

    window_->clear();

    current->render(renderer_);

    renderer_.flush();

    window_->update();

//    std::cout<<sf::Mouse::getPosition(window_->raw()).x<<" ";
//    std::cout<<sf::Mouse::getPosition(window_->raw()).y<<std::endl;

    handleInput();

    ++fps;
    second += elapsed.asSeconds();
    if (second > 0.5f) {

      std::string title(config_.title);
      title.append(" | fps:");
      title.append(std::to_string(fps * 2));
      title.append(" | ups:");
      title.append(std::to_string(tickCount * 2));

      window_->raw().setTitle(title);

      second = 0;
      fps = 0;
      tickCount = 0;
    }

    if (shouldPop) {
      shouldPop = false;

      auto c = states.back();
      states.pop_back();
      delete c;

      if (states.empty()) break;

      current = states.back();
    }

  }
}

void Application::handleInput() {
  sf::Event event{ };
  while (window_->raw().pollEvent(event)) {
    current->input(event);
    switch (event.type) {
      case sf::Event::Closed:window_->raw().close();
        break;
      case sf::Event::Resized: {
        break;
      }
      case sf::Event::MouseWheelScrolled:{
      }
      default:break;
    }
  }
}
