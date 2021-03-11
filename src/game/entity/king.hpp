#ifndef CHESS_KING_HPP
#define CHESS_KING_HPP

#include "piece.hpp"


class King : public Piece {
public:
  explicit King(PieceType type);
  void showMoves() override {}
  void clearMoves() override {}
};


#endif
