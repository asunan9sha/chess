#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include "utils/types.hpp"
#include "pawn.hpp"
#include "kninght.hpp"
#include "bishop.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "rook.hpp"

class MasterRenderer;

class Board : public sf::RectangleShape {
public:
  explicit Board(const vec2 &pos, const vec2 &size, const sf::Texture &texture, float angle);
  ~Board() override;

  void render(MasterRenderer &renderer);
  void input(const sf::Event &event);
  void update(float delta);
  void fixedUpdate(float delta);


  std::vector<Piece *> pieces_;

private:
  void initBoard();
  float convertCoord(int x, int y);

private:
  int board_[8][8] = {-4, -2, -3, -6, -5, -3, -2, -4,
                      -1, -1, -1, -1, -1, -1, -1, -1,
                       0,  0,  0,  0,  0,  0,  0,  0,
                       0,  0,  0,  0,  0,  0,  0,  0,
                       0,  0,  0,  0,  0,  0,  0,  0,
                       0,  0,  0,  0,  0,  0,  0,  0,
                       1,  1,  1,  1,  1,  1,  1,  1,
                       4,  2,  3,  6,  5,  3,  2,  4,
  };


};


#endif
