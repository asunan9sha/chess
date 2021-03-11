#ifndef CHESS_KNIGHT_HPP
#define CHESS_KNIGHT_HPP

#include "piece.hpp"


class Knight : public Piece {
public:
  explicit Knight(PieceType type);
  void showMoves() override {}
  void clearMoves() override {}
};


#endif
