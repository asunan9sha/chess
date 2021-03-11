#ifndef CHESS_QUEEN_HPP
#define CHESS_QUEEN_HPP

#include "piece.hpp"


class Queen : public Piece {
public:
  explicit Queen(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture);

  void showMoves() override {}
  void clearMoves() override {}
};


#endif
