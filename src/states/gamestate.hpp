#ifndef CHESS_GAMESTATE_HPP
#define CHESS_GAMESTATE_HPP

#include "basestate.hpp"
#include "SFML/Graphics.hpp"
#include "game/entity/board.hpp"

class GameState : public BaseState {
public:
  explicit GameState(Application *app);

  void render(MasterRenderer &renderer) override;

  void update(float delta) override;
  void fixedUpdate(float delta) override;

  void input(const sf::Event &event) override;
  void input(float delta) override;

  void onOpen() override;

private:
  std::unique_ptr<Board> board_;

};


#endif
