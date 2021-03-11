#ifndef CHESS_KING_HPP
#define CHESS_KING_HPP

#include "piece.hpp"


class King : public Piece {
public:
  explicit King(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture);

  void showMoves() override {}
  void clearMoves() override {}
};


#endif
