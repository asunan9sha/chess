#ifndef CHESS_BASESTATE_HPP
#define CHESS_BASESTATE_HPP

namespace sf {
  class Event;
}

class Application;
class MasterRenderer;

class BaseState {
public:
  explicit BaseState(Application *app) : application_(app) {}
  virtual ~BaseState() = default;

  virtual void render(MasterRenderer &renderer) = 0;

  virtual void update(float delta) = 0;
  virtual void fixedUpdate(float delta) = 0;

  virtual void input(const sf::Event &event) = 0;
  virtual void input(float delta) = 0;

  virtual void onOpen() {};

protected:
  Application *application_;
};


#endif //CHESS_BASESTATE_HPP
