#ifndef CHESS_APPLICATION_HPP
#define CHESS_APPLICATION_HPP


#include <states/basestate.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "renderers/masterrenderer.hpp"
#include "config.hpp"
#include "window.hpp"

class Application {
public:
  explicit Application(const Config &config);

  void run();

  template<typename S, typename... Args>
  void push(Args &&... args) {
    states.push_back(new S(std::forward<Args>(args)...));
    current = states.back();

    current->onOpen();
  }

  inline static Application &getApplication() { return *app_; }

  inline const Window &getWindow() const { return *window_; }
  inline Window &getWindow() { return *window_; }

private:
  void handleInput();

private:
  Window *window_;
  MasterRenderer renderer_;

  bool shouldPop;

  Config config_;

  BaseState *current;
  std::vector<BaseState *> states;

  static Application *app_;
};


#endif //CHESS_APPLICATION_HPP
