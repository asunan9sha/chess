#ifndef CHESS_GAMESTATE_HPP
#define CHESS_GAMESTATE_HPP

#include <game/entity/pawn.hpp>
#include "basestate.hpp"
#include "ui/textbutton.hpp"
#include "ui/basicbutton.hpp"
#include "SFML/Graphics.hpp"
#include "resources/resourceholder.hpp"
#include "game/entity/board.hpp"
#include "game/entity/queen.hpp"

class GameState : public BaseState {
public:
  explicit GameState(Application *app);
  ~GameState() override;

  void render(MasterRenderer &renderer) override;

  void update(float delta) override;
  void fixedUpdate(float delta) override;

  void input(const sf::Event &event) override;
  void input(float delta) override;

  void onOpen() override;

private:
  Board *board;

};


#endif
